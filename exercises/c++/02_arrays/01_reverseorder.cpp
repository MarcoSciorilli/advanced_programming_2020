#include <iostream>
template <typename T>
T * allocator(std::size_t n);

template <typename T>
void printrev(T * da, std::size_t n);

int main() 
{
	std::cout << "Please insert array lenght: ";
	std::size_t n;
	std::cin >> n;
	int * da=allocator<int>(n);
	printrev(da, n);
	
	delete[] da;
	return 0;
}


template <typename T>
T * allocator(std::size_t n) 
{
	T * da{new T [n]};  // allocated on the HEAP, or free-store
	std::cout << "Please insert array elements: ";
	for (std::size_t i{0}; i < n; ++i)
	{
		std::cin >> da[i];
	}

	return da;
}

template <typename T>
void printrev(T * da, std::size_t n){
  for(int i = n-1; i>=0; i--){
    std::cout << da[i] << std::endl;
  }
}