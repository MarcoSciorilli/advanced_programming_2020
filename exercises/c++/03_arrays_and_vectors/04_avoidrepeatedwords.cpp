#include <iomanip>
#include <iostream>
#include <utility>
#include <sstream>
#include <algorithm>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s);

int main()
{	
	std::cout<<"Write alla the words you want, when finished, press crtl+D"<<std::endl;
	std::vector<std::string> v;
	for(std::string line; std::getline(std::cin, line); )
	{
		std::istringstream iss(line);
		for (std::string arg; iss >> arg; )
		{	if (v.size()==0)
				v.push_back(arg);

			for (std::size_t i{0}; i<v.size(); i++)
			{
				if(arg==v.at(i))
					break;
				if(i==v.size()-1)
					v.push_back(arg);
			}
		}
	}
	print_vector(v, "Words without repetitions ");
	return 0;
}

template <typename T>
void print_vector(const std::vector<T>& v, const std::string& s) 
{
  std::cout << s << ": ";
  for (const auto& x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}
