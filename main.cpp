#include <iostream>
#include <cmath>
#include "PrimeGen.hpp"


int main()
{

//    mp::cpp_int hello = 65537;
    mp::cpp_int big("2132134213423112324256474315526436262568356454562523523543143142134234234");
//    std::cout << asdf << "big number" << "\n";
    PrimeGen<mp::cpp_int> pg = PrimeGen<mp::cpp_int>();
    std::cout << "preliminary check: " << pg.prelimCheck(100) << "\n";
    mp::cpp_int candidate = pg.generateCandidate();
    std::cout << "candidate number check   " << candidate<< "\n";
    std::cout << "check a  " << pg.millerRabinTest(candidate) << "\n";
    mp::cpp_int three = 3;
    mp::cpp_int two = 2;
    mp::cpp_int answer = mp::pow(two, 3);
    std::cout << answer << "is the answer";


//    std::cout << "is it a prime?" << pg.isPrimeSure(hello) << "\n";
//    std::cout << "sqrt" << std::sqrt(34) << "\n";
//    std::cout << "Hello world! " << hello << std::endl;
//  system("pause");
    return 0;
}
