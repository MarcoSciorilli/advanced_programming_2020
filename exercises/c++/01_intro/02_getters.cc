#include <iostream>
#include <string>

void get_int(int& a);
void get_double(double& a);



int main() {
	std::cout << "Pick a integer number:\n";
	int a;
	std::cin >> a;
	get_int(a);
	std::cout << "Pick a double number:\n";
	double b;
	std::cin >> b;
	get_double(b);

	return 0;
}



void get_int(int& a) 
{	int i;
	while(std::cin >> i)
		if(i==a)
		{
			std::cout << "Correct number is:\n"<< i << "\n";
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
		}
}

void get_double(double& a) 
{	double i;
	while(std::cin >> i)
		if(i==a)
		{
			std::cout << "Correct number is:\n"<< i << "\n";
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
		}
}