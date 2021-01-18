#include <iomanip>
#include <iostream>
#include <utility>
#include <sstream>
#include <algorithm>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s);

template <typename T>
T median(const std::vector<T>& v);

template <typename T>
T mean(const std::vector<T>& v);


int main()
{	
	std::vector<double> v;
	for(std::string line; std::getline(std::cin, line); )
	{
		std::istringstream iss(line);
		for (double arg; iss >> arg; )
		{
			v.push_back(arg);
		}
	}
	std::cout << "Received vector of size: " << v.size() << " \n";	
	std::sort( v.begin(), v.end() );
	std::cout<< "The median is: "<< median(v) << "\nThe mean is: "<< mean(v)<< std::endl;
	return 0;
}


template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s) {
  std::cout << s << ": ";
  for (const auto& x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}

template <typename T>
T median(const std::vector<T>& v)
	{
		T median;
		median=v.at(v.size()/2);
		return median;
	}

template <typename T>
T mean(const std::vector<T>& v)
	{
		T mean;
		for (double i{0}; i<v.size(); i++)
			mean=mean+v.at(i);
		return mean=mean/v.size();
	}
