#pragma once

template <typename T> requires std::floating_point<T>
class complex_number
{
	T real, imag;
	
public:
	// Default constructor
	complex_number()
		: real(0), imag(0)
	{}
    
	// User-defined constructor
    explicit complex_number(T n)
		: real(n), imag(0) 
	{}

	// User-defined constructor
	complex_number (T n, T d)
		: real(n), imag(d)
	{}
	
	// Return the conjugate
	complex_number<T> conjugate(void) {
		return complex_number<T>(real, -imag);
	}
	
	// Return the real part of the complex number
	T real_part(void) const {
		return real;
	}
	
	// Return the imaginary part of the complex number
	T imag_part(void) const {
		return imag;
	}
	
	// Define the += operator for complex number
	complex_number& operator+=(const complex_number& other) {
	T a = real;
	T b = imag;
	T c = other.real;
	T d = other.imag;
	real = a+c;
	imag = b+d;
	return *this;
	}
	
	// Define the + operator in terms of operator+= defined above
	complex_number operator+(const complex_number& other) const {
	complex_number ret = *this;
	ret += other;
	return ret;
	}
	
	// Define the *= operator for complex number
	complex_number& operator*=(const complex_number& other) {
	T a = real;
	T b = imag;
	T c = other.real;
	T d = other.imag;
	real = a*c-b*d;
	imag = a*d+b*c;
	return *this;
	}
	
	// Define the * operator in terms of operator*= defined above
	complex_number operator*(const complex_number& other) const {
	complex_number ret = *this;
	ret *= other;
	return ret;
	}
	
	// Define the += operator between a complex number on the left and a type T on the right
	complex_number& operator+=(const T& other) {
	real += other;
	return *this;
	}
	
	// Define operator + in terms of operator +=
	complex_number operator+(const T& other) const {
	complex_number ret = *this; 
	ret += other;
	return ret;
	}
	
	// Define the *= operator between a complex number on the left and a type T on the right
	complex_number& operator*=(const T& other) {
	real *= other;
	imag *= other;
	return *this;
	}
	
	// Define operator * in terms of operator *=
	complex_number operator*(const T& other) const {
	complex_number ret = *this;
	ret *= other;
	return ret;
	}
};

// Operator defined to compute the sum of a type T on the left and a complex number on the right
template<typename T> requires std::floating_point<T>
complex_number<T>
operator+(const T& i, const complex_number<T>& r)
{
	return r + i;
}

// Operator defined to compute the product of a type T on the left and a complex number on the right
template<typename T>  requires std::floating_point<T>
complex_number<T>
operator*(const T& i, const complex_number<T>& r)
{
	return r * i;
}

// Overload of <<, to print the complex numbers.

template<typename T> requires std::floating_point<T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& r) {
	if (r.imag_part() !=0)
		if(r.imag_part()>0)
			if(r.imag_part()!=1)
				os << r.real_part() << " + " << r.imag_part()<< "i";
			else
				os << r.real_part() << " + i";
		else
			if(r.imag_part() != -1)
				os << r.real_part() << " " << r.imag_part() << "i";
			else
				os << r.real_part() << " -i";
	else
		os << r.real_part();
	
	return os;
}	