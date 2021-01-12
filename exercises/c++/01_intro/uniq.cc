#include <iostream>
#include <string>

int main() {
	std::cout << "Insert string of text:\n";
	std::string line;
	std::string compare;
	int i{0};
	while(std::getline(std::cin,line))
	{	
		if(i==0)
		{
			i+=1;
			compare=line;
		}
		else
		{
			if(compare == line)
				i+=1;
			if(compare != line)
			{
				std::cout << i << " " << compare << "\n";
				i=1;
				compare=line;
			}
		}
	}
	std::cout << i << " " << compare << "\n";
	return 0;
}
