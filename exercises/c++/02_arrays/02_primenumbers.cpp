#include <iostream>

template <typename T>
void arrayprime(std::size_t n);


int main() 
{
	std::cout << "Please insert upper prime limit: ";
	std::size_t n;
	std::cin >> n;
	arrayprime<int>(n);
	return 0;
}


template <typename T>
void arrayprime(std::size_t n) 
{	
	std::size_t da[n];
	std::size_t k{0};
	for (std::size_t i{2}; i < n; ++i)
	{
		for (std::size_t j{1}; j<= i; ++j)
		{
			if(i%j == 0 && j!=1) 
				break;
			if(j==i/2)
			{ //if none of those is a perfect divisor, sign the number
	    		da[k]=i;
	    		k++;
	    	}
		}

	}
	int b[k]; 				 //create a new array of the right size, and copy the values of interest found in the previous loop
	for (std::size_t i{0}; i <= k; ++i)
		b[i]=da[i];

	for (std::size_t i{0}; i < k; ++i)
  	{
    	std::cout << b[i] << std::endl;
  	}
}


