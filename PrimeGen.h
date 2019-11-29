#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include <vector>

namespace mp = boost::multiprecision;

template <class Number>
class PrimeGen{
public:
//    public variables

//    generate a sieve until the "until" value of primes, uses int as input since check sieve is likely to be small
    std::vector<int> createSieve(int until){
        std::vector<int> temp = std::vector<int>();
        temp.reserve(until);
//        initialize temp sieve
        for (int i = 2; i < until; i ++) temp.push_back(i);
        int check = 2;
        int until_root = std::sqrt(until);
//        while (check <= until_root){
//
//
//        }
        return temp;

    }

//    public methods
    bool isPrimeSure(Number num){
        if (num%2 == 0) return false;
        Number until = mp::sqrt(num); //fails for regular int type and any other type that can't be an input to boost::mp::sqrt

        for (int i = 3; i <= until; i+=2){
            if (num%i == 0 ) return false;
        }
        return true;
    }
//    public stuff

private:


};
