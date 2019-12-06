#ifndef FASTEXPO_HPP_INCLUDED
#define FASTEXPO_HPP_INCLUDED
#include <boost/multiprecision/cpp_int.hpp>

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


#endif // FASTEXPO_HPP_INCLUDED
