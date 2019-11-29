#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>


namespace mp = boost::multiprecision;

template <class Number>
class PrimeGen{
public:
//    Non probabalistic, always sure output is or isn't prime 100 percent
    bool isPrimeSure(Number num){
        if (num%2 == 0) return false;
        Number until = mp::sqrt(num); //fails for regular int type and any other type that can't be an input to boost::mp::sqrt
        for (int i = 3; i <= until; i+=2){
            if (num%i == 0 ) return false;
        }
        return true;
    }



private:


};
