#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include "PrimeGen.h"

namespace mp = boost::multiprecision;

int main()
{



    mp::cpp_int hello = 65537;
    mp::cpp_int asdf("2132134213423112324256474315526436262568356454562523523543143142134234234");
    std::cout << asdf << "big number" << "\n";
    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
    std::vector<int> stuff = pg.createSieve(100);
    for (auto elem : stuff) std::cout << elem << "-> ";
//    std::cout << "is it a prime?" << pg.isPrimeSure(hello) << "\n";
//    std::cout << "sqrt" << std::sqrt(34) << "\n";
//    std::cout << "Hello world! " << hello << std::endl;
//  system("pause");
    return 0;
}
