#ifndef MODULOINV_HPP_INCLUDED
#define MODULOINV_HPP_INCLUDED
#endif // MODULOINV_HPP_INCLUDED
#include <boost/integer/mod_inverse.hpp>


/// function to return to modular inverse of a
/// @param[in] mod: the number to be modulo by,
/// a: number which the result is a modulo inverse of
template <class Number>
Number modInverse(Number a, Number mod){
    return boost::integer::mod_inverse(a, mod);
}
