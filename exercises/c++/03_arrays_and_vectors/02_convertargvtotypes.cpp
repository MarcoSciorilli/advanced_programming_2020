#include <iomanip>
#include <iostream>
#include <utility>
#include <sstream>

void print_ma(std::size_t* p, std::size_t row, std::size_t col);
void transpose(std::size_t* p, std::size_t row, std::size_t col);


int main()
{	
	auto args = new std::size_t[2]{};
	for(std::string line; std::getline(std::cin, line); )
	{
		std::istringstream iss(line);
		int i{0};
		for (std::size_t arg; iss >> arg; )
		{
			args[i]=arg;
			i+=1;
		}
		std::cout << "Received dimensions: '" << "\n rows:" << args[0]<<"  columns " << args[1]<< std::endl;
		break;
	}
	auto d_ma = new std::size_t[args[0] * args[1]]{};

	for (std::size_t i = 0; i < args[0]*args[1]; ++i)
		d_ma[i]=i;
	print_ma(d_ma, args[0], args[1]);
	transpose(d_ma,args[0],args[1]);
	print_ma(d_ma, args[1], args[0]);
	delete[] d_ma;
	return 0;
}



void print_ma(std::size_t* p, std::size_t row, std::size_t col) 
{
	for (std::size_t i = 0; i < row; ++i) 
	{
		for (std::size_t j = 0; j < col; ++j)
		{
			std::cout << std::setw(2) << p[i * col + j] << " ";
		}

		std::cout << std::endl;	
	}
}

void transpose(std::size_t* p, std::size_t row, std::size_t col)
{

    const std::size_t sup = (row*col -1);
    const std::size_t under   = (row*col)/col;
    bool visited[row*col]{false};
    std::size_t cyc{0};
	while (++cyc != row*col) 
  	{
		if (visited[cyc])
			continue;
        std::size_t a = cyc;
        do  
        {
            a = a == sup ? sup : (under * a) % sup;
            std::swap(p[a], p[cyc]);
            visited[a] = true;
        }while ( a != cyc);
    }

}

