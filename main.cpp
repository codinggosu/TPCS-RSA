#include <iostream>
#include <cmath>
#include "Cryption.hpp"


int main(int argc, char* argv[])
{


//    Cryption<mp::cpp_int> crypt = Cryption<mp::cpp_int>();
    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();



// generate N primes
//    int generate_n_primes = std::stoi(argv[1]);
//    std::cout << "Generate " << generate_n_primes << " primes.\n";
//    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < generate_n_primes; i ++){
//        std::cout << pg.generatePrime() << "\n";
//    }
//    auto finish = std::chrono::high_resolution_clock::now();
//    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds> (finish-start);
//    std::cout << "Elapsed time in microseconds: " << elapsed.count();


//    generate large prime
//    std::cout << pg.generatePrime();


// generate and print keys
//    crypt.generatePrintKeys();

// encrypt variables
//    std::string n = argv[1];
//    std::string pt = argv[2];
//    std::string e = argv[3];
//    mp::cpp_int public_n = mp::cpp_int(n);
//    mp::cpp_int plaintext = mp::cpp_int(pt);
//    mp::cpp_int exponent = mp::cpp_int(e);
//    std::cout << "encrypted message:" << crypt.encrypt(public_n, plaintext, exponent);

// decrypt variables
//    std::string n = argv[1];
//    std::string ct = argv[2];
//    std::string d = argv[3];
//    mp::cpp_int public_n = mp::cpp_int(n);
//    mp::cpp_int cyphertext = mp::cpp_int(ct);
//    mp::cpp_int private_key = mp::cpp_int(d);
//    std::cout << "decrypted message:" << crypt.decrypt(public_n, cyphertext, private_key);









// testing various functions
//    std::cout << "custom mod inverse" << customModInverse(1324124314523451) <<"\n";
//    std::cout << "default mod inverse" <<modInverse(1324124314523451)<<"\n";
//    mp::cpp_int a("132412134124312341234");
//    mp::cpp_int b("1234123412341234123412431234");
//    mp::cpp_int e("65537");
//    std::cout << "custom expo mod" << customExpoMod(a, e, b) <<"\n";
//    std::cout << "default expo mod" <<fastExpoMod(a, e, b)<<"\n";
//    mp::cpp_int pt = crypt.decrypt(ct);
//    std::cout << crypt.decrypt(ct) << "\n";
//    std::cout << pt;




//    mp::cpp_int first_prime("318831468460481049114126232101899133976907367481127");
//    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
//    std::cout << "prime generated : " << pg.generatePrime() << "\n";


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
