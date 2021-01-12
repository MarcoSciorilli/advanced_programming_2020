#include <iostream>
#include <cmath>

int main() 
{
	std::cout << "Please insert upper prime limit: ";
	std::size_t n;
	std::cin >> n;
	bool da[n]={0};
    
    for (std::size_t i{2};i<std::sqrt(n);++i)
    {
        if (da[i]==0)
        {
            for (std::size_t j{i*i}; j<n;j+=i)
                da[j] =1;
        }
	}

	for (std::size_t i{2}; i < n; ++i)
  	{
  		if(da[i]==0)
    	std::cout << i << std::endl;
  	}
	return 0;
}