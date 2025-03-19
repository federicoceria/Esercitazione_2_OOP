#include <iostream>
#include <fstream>

unsigned int sum_values(unsigned int N)
{
	return N * (N+1) * (2*N+1)/6;
}

int main()
{	
    std::ifstream file("data.txt"); //oppure file.open("data.txt") nella riga successiva;
	
	if(file.fail())
	{
		std::cerr << "File not found" << std::endl;
		return 1;
	}
	std::string tmp; //tmp è un valore temporaneo che non viene poi utilizzato
	std::getline(file, tmp); //getline legge finchè non trova un carattere di new values
	std::cout << tmp << std::endl;
	unsigned int n = 0;
	unsigned int val;
	unsigned int sum = 0;
	while(file >> val)
	{
		sum += val * val;
		n++;
	}
	
	unsigned int S = sum_values(n);
	std::cout << "sum= " << sum << std::endl;
	std::cout << "S= " << S << std::endl;
	
	return 0;
}