#ifndef PRIMEGEN_HPP_INCLUDED
#define PRIMEGEN_HPP_INCLUDED
#endif // PRIMEGEN_HPP_INCLUDED
#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <boost/random/uniform_int_distribution.hpp>
//#include <boost/random/mersenne_twister.hpp>
#include "FastExpo.hpp"



/// A class to generate large prime numbers
template <class Number>
class PrimeGen{
public:
//    public variables
    std::vector<int> primeSeive;

    /// generate a sieve until the "until" value of primes: used to do preliminary prime checks before entering
    /// expensive probabilistic prime checks -> by prelimCheck()
    /// @param[in] until uses int as input since check sieve is likely to be small
    void createSieve(int until){
        std::vector<int> temp = std::vector<int>();
        temp.reserve(until);
//        initialize temp sieve
        for (int i = 2; i < until; i ++) temp.push_back(i);
        int check = 2;
        int until_root = std::sqrt(until);
//        while (check <= until_root){
//        }
//        return temp;
    }
    /// a function to check whether a number is divisible by any small prime in the member variable sieve
    bool prelimCheck(Number primeCandidate){
        for (auto prime : this->primeSeive){
            if (primeCandidate % prime == 0) return false;
        }
        return true;
    }

//    public methods
    /// a 100% sure method to detect whether a number is prime, works by dividing from 2 to sqrt(n)
    bool isPrimeSure(Number num){
        if (num%2 == 0) return false;
        Number until = boost::multiprecision::sqrt(num); //fails for regular int type and any other type that can't be an input to boost::mp::sqrt
        for (int i = 3; i <= until; i+=2){
            if (num%i == 0 ) return false;
        }
        return true;
    }

    /// function to generate random number to test for primality, uses b + 2i where b is an odd number
    /// uses device random, which is non deterministic hardware entropy random number generator as seed for PRNG
    Number generateCandidate() {
        std::random_device seedGen;
        std::mt19937 mt(seedGen()*std::time(0));
        mp::cpp_int b = mt();
        mp::cpp_int i = mt();
        mp::cpp_int bigNum("110130847310391570192384409610374094385013");
        while ((b& 1) == 0 || b < 0) b = mt();
        while (i < 0) i = mt();
        b *= bigNum;
        i *= (std::time(0)*11);
    return b + (2*i);
    }


    /// miller rabin test: find r and s s.t(n-1) = r*(2^s) where r is odd
    /// if a^r = 1 (mod n) or a^((2^j)r) = -1 (mod n) where a is integer in range [1, n-1] and j is integer s.t 0 ¡Â j ¡Â s-1
    /// then n is strong pseudo prime to base a
    /// @param[in] candidate: prime number candidate, repetitions: number of test repetitions
    bool millerRabinTest(Number candidate, int repetitions=25){
        // find r and s
        mp::cpp_int s = 0;
        mp::cpp_int r = candidate - 1;
        while ((r & 1) == 0){
            s += 1;
            r /= 2;
        }

        // use a 64 bit number as a, since candidate is always bigger than 64 bits
        std::mt19937_64 gen;
        mp::cpp_int a = gen();
//        mp::cpp_int a = candidate - gen()*std::time(0);
        boost::random::uniform_int_distribution<Number> dis(1,s-1); // generator for j which is an integer in range [0, s-1]
        mp::cpp_int j = dis(gen);
        mp::cpp_int two = 2;
        mp::cpp_int two_expo_j = fastExpo(two, j); // 2 ^ j
        mp::cpp_int expo_j_r = two_expo_j * r; // (2 ^ j) * r
//        for (int i = 0; i < 25; i ++){
//                if ((fastExpo(a, r) % candidate == 1) || fastExpo(a, expo_j_r)%candidate==-1)
//                    continue;
//                else return false;
//        }

        return true;
    }


private:


};
