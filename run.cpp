#include <iostream>
#include <cmath>
#include "Cryption.hpp"


int run()
{
//    mp::cpp_int e = 65537;
//    mp::cpp_int first_prime("318831468460481049114126232101899133976907367481127");
//    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
//    std::cout << "prime generated : " << pg.generatePrime() << "\n";


    std::cout << "test run \n";
    Cryption<mp::cpp_int> crypt = Cryption<mp::cpp_int>();
    crypt.generateKeys();
    mp::cpp_int cyphertext = crypt.encrypt(1234);
    std::cout << "encryption of 1234 " << cyphertext << '\n';
    std::cout << "decryption of 1234 " << crypt.decrypt(cyphertext) << '\n';

    system("pause");
    return 988;
}



