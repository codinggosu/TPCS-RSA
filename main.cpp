#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include "PrimeGen.h"

namespace mp = boost::multiprecision;

int main()
{
    mp::cpp_int hello = 65537;
    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
    std::cout << "is it a prime?" << pg.isPrimeSure(hello);
    std::cout << "sqrt" << std::sqrt(34);
    std::cout << "Hello world! " << hello << std::endl;
//    system("pause");
    return 0;
}
