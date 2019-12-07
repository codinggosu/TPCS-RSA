#include <iostream>
#include <cmath>
#include "Cryption.hpp"
#include <boost/random/random_device.hpp>
#include "ModuloInv.hpp"


int main()
{

//    mp::cpp_int e = 65537;
//    mp::cpp_int first_prime("318831468460481049114126232101899133976907367481127");

//    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();



//    Cryption<mp::cpp_int> crypt = Cryption<mp::cpp_int>();
//    crypt.generateKeys();
//    mp::cpp_int cyphertext = crypt.encrypt(1234);
//    std::cout << "encryption of 1234 " << cyphertext << '\n';
//    std::cout << "decryption of 1234 " << crypt.decrypt(cyphertext) << '\n';


    int x = mod_inverse(2, 5);
    // prints x = 3:
    std::cout << "x = " << x << "\n";

    int y = mod_inverse(2, 4);
    if (y == 0)
    {
        std::cout << "There is no inverse of 2 mod 4\n";
    }


//    system("pause");
    return 0;
}
