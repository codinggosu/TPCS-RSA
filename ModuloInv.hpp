#ifndef MODULOINV_HPP_INCLUDED
#define MODULOINV_HPP_INCLUDED
#endif // MODULOINV_HPP_INCLUDED
#include <boost/integer/mod_inverse.hpp>


/// wrapper for boost function to calculate mod inverse
/// assumption that e, and d are relatively prime satisfied by the
/// fact that e is prime
/// @param[in] mod: the totient, s.t e*d(mod totient) = 1
/// @param[in] e: 65537, default value of e
template <class Number>
Number modInverse(Number mod, Number e = 65537){
    return boost::integer::mod_inverse(e, mod);
}

/// custom function to return to modular inverse of e, d, uses extended euclidean GCD algorithm
/// @param[in] mod: the totient, s.t e*d(mod totient) = 1
/// @param[in] e: 65537, default value of e
/// assumption that e and d are relatively prime satisfied by the
/// fact that e is prime
template<class Number>
Number customModInverse(Number mod, Number e = 65537){
    // EXTENDED GCD

    // start at "step 2" of GCD extended
    Number temp = mod % e;
    //remainder
    Number r = e % temp;
    // quotient
    Number prev_q = mod / e;
    Number q = e / temp;
    //Bezout Coefficients s and t, postfix _one, _two denote order in recursive relationg
    // ex: s_step = s_two - q * s_one
    Number s_one = 0;
    Number s_two = 1;
    Number t_one = 1;
    Number t_two = 0;
    // swap variable for swaps
    Number holder;
    while (r != 0){
        holder = s_one;
        s_one = s_two - prev_q * holder;
        s_two = holder;
        holder = t_one;
        t_one = t_two - prev_q * holder;
        t_two = holder;
        prev_q = q;
        q = temp / r;
        holder = temp;
        temp = r;
        r = holder % r;
    }
    // advance s and t one more time
    holder = s_one;
    s_one = s_two - prev_q * holder;
    s_two = holder;
    holder = t_one;
    t_one = t_two - prev_q * holder;
    t_two = holder;
    //ensure that d is positive
    return (t_one%mod + mod) % mod;
}
