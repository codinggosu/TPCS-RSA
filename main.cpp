#include <iostream>
#include <cmath>
#include "PrimeGen.hpp"


int main()
{

//    mp::cpp_int e = 65537;
//    mp::cpp_int first_prime("318831468460481049114126232101899133976907367481127");

    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
//    std::cout << "is prime for sure:" << pg.generatePrime();
    mp::cpp_int candidate("428640646032571816849859006098220984814463001448911");
    std::cout << candidate;



//  system("pause");
    return 0;
}
