#include <iostream>
#include <cmath>
#include "Cryption.hpp"
#include <boost/random/random_device.hpp>


int main()
{

//    mp::cpp_int e = 65537;
//    mp::cpp_int first_prime("318831468460481049114126232101899133976907367481127");

//    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
//    std::cout << "prime generated : " << pg.generatePrime() << "\n";

    Cryption<mp::cpp_int> crypt = Cryption<mp::cpp_int>();
    crypt.generateKeys();
    mp::cpp_int cyphertext = crypt.encrypt(1234);
    std::cout << "encryption of 1234 " << cyphertext << '\n';
    std::cout << "decryption of 1234 " << crypt.decrypt(cyphertext) << '\n';



//    system("pause");
    return 0;
}



// doxygen stuff for main page
/*! \mainpage TPCS RSA project by Dong Joo Lee
 *
 * \section Description
 *
 * A project to explore the number theory concepts surrounding RSA
 *
 * \section Concepts-and-Implementations
 * Implemented functions for prime generation, primality testing(fermat/miller-rabin)
 * ,modulo inverse solving(extended GCD), fast modulo exponentiation, and
 * RSA encryption/decryption
 *
 *
 * \subsection  SECTION1 Primality Testing:
 *  preliminary check by dividing by small primes sieve of Eratosthenes),followed by fermat test, then finally miller-rabin test
 * \subsection  SECTION2 Mod Inverse Solver:
 * perform extended euclidean GCD algorithm
 * \subsection  SECTION3 Fast Mod Exponentiation:
 * left to right/right to left binary method
 *
 *
 * etc...
 */
