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

/// wrapper for boost multi precision fast expo mod function used for testing
template <class Number>
Number fastExpoMod(Number base, Number exponent, Number mod){
    return mp::powm(base, exponent, mod);
}

/// Custom Fast modular exponentiation algorithm
template <class Number>
Number customExpoMod(Number base, Number exponent, Number mod){
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
        Number answer = 1;
        // vector to hold binary bits
        std::vector<bool> bin = std::vector<bool>();
        // temporary variable to hold base being divided by 2
        Number temp = exponent;
        //convert to binary
        while (temp > 0){
            bool even_odd = temp & 1;
            bin.push_back(even_odd);
            temp /= 2;
        }
//        std::reverse(bin.begin(),bin.end());
        // variable to keep track to base ^ (some power of 2) modulo mod
        Number base_two = base % mod;
        for (auto i : bin){
            if (i){
                answer *= base_two;
            }
            base_two = (base_two * base_two) % mod;
//            std::cout << "answer" << answer;
        }
        return answer % mod;
    }
}


#endif // FASTEXPO_HPP_INCLUDED
