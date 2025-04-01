#include <iostream>
#include "complex.hpp"

int main()
{ 
	using cn = complex_number<double>;
	cn c1(-5.0, 4.0);
	cn c2(1.0, 7.5);
	cn c3;
	cn c4(9.0);
	
	std::cout << "c1: " << c1 << std::endl;  //check if the << overload is working correctly
	std::cout << "c2: " << c2 << std::endl;
	std::cout << "c3: " << c3 << std::endl;  //check if the default constructor is working correctly
	std::cout << "c4: " << c4 << std::endl;  //check if the explicit constructor is working correctly
	std::cout << "c1 real part: " << c1.real_part() << " and c1 imaginary part: " << c1.imag_part() << std::endl;
	std::cout << "c2 real part: " << c2.real_part() << " and c2 imaginary part: " << c2.imag_part() << std::endl;
	std::cout << "Conjugate of " << c1 << " is " << c1.conjugate() << std::endl;
	std::cout << "Conjugate of " << c2 << " is " << c2.conjugate() << std::endl;
	
	cn sum = c1 + c2;
	cn product = c1 * c3;
	cn c5 = c4 + 1.0;
	cn c6 = -2.0 + c2;
	cn c7 = c1 * -2.0;
	cn c8 = 3.0 * c3;
	
	std::cout << "Sum: " << c1 << " + " << c2 << " = " << sum << std::endl;
	std::cout << "Product: " << c1 << " * " << c3 << " = " << product << std::endl;
	std::cout << "Sum: " << c4 << " + " << "1" << " = " << c5 << std::endl;
	std::cout << "Sum: " << "-2" << " + " << c2 << " = " << c6 << std::endl;
	std::cout << "Product: " << c1 << " * " << "-2" << " = " << c7 << std::endl;
	std::cout << "Product: " << "3" << " * " << c3 << " = " << c8 << std::endl;
	
	return 0;
}