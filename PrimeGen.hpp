#ifndef PRIMEGEN_HPP_INCLUDED
#define PRIMEGEN_HPP_INCLUDED
#endif // PRIMEGEN_HPP_INCLUDED
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/random.hpp>
#include <cmath>
#include <random>
#include <ctime>
#include <boost/random/uniform_int_distribution.hpp>
#include "FastExpo.hpp"
#include <set>
#include <chrono>



/// A class to generate large prime numbers
template <class Number>
class PrimeGen{
public:
//    public variables
    /// sieve for first few primes less than a certain number, preliminary check before entering miller rabin
    /// uses set for constant remove times
    std::set<int> primeSeive;


//  public functions

    /// generate a sieve until the "until" value of primes: used to do preliminary prime checks before entering
    /// expensive probabilistic prime checks -> by prelimCheck() implementation of  Sieve of Eratosthenes algorithm
    /// @param[in] until uses int as input since check sieve is likely to be small
    void createSieve(int until){
//        std::cout << "generating prime sieve \n";
        //initialize temp sieve
        for (int i = 2; i < until; i++) this->primeSeive.insert(i);
        int until_root = std::sqrt(until); // sqrt of until for checking optimization
        int multiple = 2; // begin with eliminating multiples of 2
        int composite = 4; //begin by eliminating 4
        while (multiple <= until_root){
            while (composite < until){
                this->primeSeive.erase(composite);
                composite += multiple;
            }
            multiple ++;
        }
    }


    /// a function to check whether a number is divisible by any small prime in the member variable sieve
    bool prelimCheck(Number primeCandidate){
        for (auto prime : this->primeSeive){
            if ((primeCandidate % prime) == 0) {
                return false;
            }
        }
        return true;
    }

    /// a 100% sure method to detect whether a number is prime, works by dividing from 2 to sqrt(n)
    bool isPrimeSure(Number num){
        if (num%2 == 0) return false;
        Number until = boost::multiprecision::sqrt(num); //fails for regular int type and any other type that can't be an input to boost::mp::sqrt
        for (int i = 3; i <= until; i+=2){
            if (num%i == 0 ) return false;
        }
        return true;
    }

    /// Fermat primality test: uses the identity a^(n-1) = 1 (mod n) when n is prime, used for "middle" step before miller rabin
    /// after preliminary sieve checks
    bool fermatTest(Number candidate, int repetitions=20){
        std::mt19937_64 gen(std::time(0)); //seed for uniform int distribution "a" generator
        boost::random::uniform_int_distribution<Number> disa (2, candidate-2); // generate a
        mp::cpp_int a;
        mp::cpp_int minus_one = candidate -1;
        for (int i = 0; i < repetitions; i ++){
            a = disa(gen); // reset a
            if (customExpoMod(a, minus_one, candidate) != 1) return false;
        }
        return true;
    }


    /// miller rabin test: find r and s s.t(n-1) = r*(2^s) where r is odd
    /// if a^r = 1 (mod n) or a^((2^j)r) = -1 (mod n) where a is integer in range [1, n-1] and j is integer s.t 0 ¡Â j ¡Â s-1
    /// then n is strong pseudo prime to base a
    /// @param[in] candidate: prime number candidate, repetitions: number of test repetitions
    bool millerRabinTest(Number candidate, int repetitions=25){
//        std::cout << "candidate being checked is : " << candidate << "\n";
        // find r and s
        mp::cpp_int s = 0;
        mp::cpp_int r = candidate - 1;
        while ((r & 1) == 0){
            s += 1;
            r /= 2;
        }
        std::mt19937_64 gen(std::time(0)); // PRNG for seeding uniform_int_distribution
        boost::random::uniform_int_distribution<Number> disa (2, candidate-2); //generator for a which is int in range [1,n-1]
        mp::cpp_int a = disa(gen);
        // j is declared as int since exponentiating any reasonable number more than 2 ^ 64 times would require 7 exabytes of RAM
        int j = 0;
        mp::cpp_int two = 2;
        mp::cpp_int two_expo_j = fastExpo(two, j); // 2 ^ j
        mp::cpp_int expo_j_r = two_expo_j * r; // (2 ^ j) * r
        // loop to iterate test with different a 25 times
        for (int i = 0; i < 25; i ++){
            while (j <= s-1){
                if ((fastExpoMod(a, r, candidate) == 1) || (fastExpoMod(a, expo_j_r, candidate)==candidate-1)){
//                    std::cout << candidate << " is a prime !!!! \n";
                    return true;
                }
                j++;
                // if j was iterated from 0 to s-1 and test didn't return true: a is strong witness to compositeness for candidate
                if (j==s-1) return false;
            }
            a = disa(gen); //reset a
            j = 0; // reset j
        }
        return false;
    }

    /// function to generate random number to test for primality, uses b + 2i where b is an odd number
    /// uses device random, which is non deterministic hardware entropy random number generator as seed for PRNG
    Number generateCandidate() {
        // i had to make multiple engines because the test environment didn't support random_device
        // which led to the same number being used as a seed for mt19937
        std::random_device seed;
        std::mt19937 mtb(seed()*(int)std::time(0)); //engine for b
        std::mt19937 mti(seed() * (int)std::chrono::system_clock::now().time_since_epoch().count()); //engine for i
        std::default_random_engine eng{static_cast<long unsigned int>(time(0))}; //engine for extra randomness
        mp::cpp_int b = mtb();
        mp::cpp_int i = mti();
        // big number to make b bigger than max range of mt19937
        mp::cpp_int bigNum("13");
        // make sure b is odd and bigger than 0
        while ((b & 1) == 0 || b < 0) b = mtb();
        //make sure that i is bigger than 0
        while (i < 0) i = mti();
        b *= bigNum;
        i *= (eng() * std::time(0) * 13);
    return b + (2*i) / 3000000000000;
    }


    Number generatePrime(){
//        std::cout << "level ++";
        // generate prime candidate
        mp::cpp_int candidate = this->generateCandidate();
        // generate prime sieve if it hasn't been generated yet
        if (this->primeSeive.size() == 0) this->createSieve(1000);
        // preliminary and intermediate checks: sieve for preliminary, fermat for intermediate
        // continuously create new candidate if preliminary / intermediate check fails
        while (!this->prelimCheck(candidate) || !this->fermatTest(candidate))
            candidate = this->generateCandidate();

        if (millerRabinTest(candidate))
            return candidate;
        else
            // recursively call generate prime until prime that passes all tests is found
            return this->generatePrime();
    }

private:
    // no private functions or variables
    // maybe make primeSieve, createSieve private functions?

};
