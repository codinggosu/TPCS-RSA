#ifndef FASTEXPO_HPP_INCLUDED
#define FASTEXPO_HPP_INCLUDED
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

namespace mp = boost::multiprecision;


/// Function to return the exponent of a number
/// @param[in] base: base of the exponent, exponent: exponent
template <class Number>
Number fastExpo(Number base, int exponent){
    return mp::pow(base,exponent);
}
template <class Number>
Number fastExpoMod(Number base, Number exponent, Number mod){
    return mp::powm(base, exponent, mod);
}

/// Fast modular exponentiation algorithm
template <class Number>
Number customeExpoMod(Number base, Number exponent, Number mod){
    // for when exponentiating by e, note 65536 = 2 ^ 16
    if (exponent == 65537){
        Number temp = 1;
        Number answer = mp::pow(base, 1) % mod;
        while (temp < 65536){
            answer = (answer*answer) % mod;
            temp *= 2;
        }
        answer *= base; // one last exponentiation to go from 65536 to 65537
        return answer%mod;
    }
    // for when exponentiating by d
    else{
        // vector to hold binary bits
        std::vector<bool> bin = std::vector<bool>();
        // temporary variable to hold base being divided by 2
        mp::cpp_int temp = base;
        //convert to binary
        while (base> 0){
            bool even_odd = base & 1;
            bin.push_back(even_odd);
            base /= 2;
        }
        //variable to keep track of what bits are "on" and what bits are "off"
        int exp = 0;
        std::reverse(bin.begin(),bin.end());




//        for (auto i :bin )
//            std::cout << i;
//        std::cout << "end of vector \n";
        return 88;
    }
}


#endif // FASTEXPO_HPP_INCLUDED
