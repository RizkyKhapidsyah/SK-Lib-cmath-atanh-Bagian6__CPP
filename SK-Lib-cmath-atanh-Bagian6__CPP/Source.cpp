#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <iostream>
#include <cmath>
#include <cfloat>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "atanh(0) = " << std::atanh(0) << '\n' << "atanh(-0) = " << std::atanh(-0.0) << '\n' << "atanh(0.9) = " << std::atanh(0.9) << '\n';
    // error handling 
    errno = 0;

    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "atanh(-1) = " << std::atanh(-1) << '\n';

    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }

    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "    FE_DIVBYZERO raised\n";
    }
        

    _getch();
    return 0;
}