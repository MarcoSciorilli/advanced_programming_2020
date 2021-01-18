#include <iomanip>
#include <iostream>
#include <utility>

void print_ma(int* p, int row, int col);
void transpose(int* p, int row, int col);




int main()
{
	auto d_ma = new int[7 * 5]{};
	for (int i = 0; i < 7*5; ++i)
		d_ma[i]=i;


	print_ma(d_ma, 7, 5);
	transpose(d_ma,7,5);
	print_ma(d_ma, 5, 7);
	delete[] d_ma;
	return 0;
}



void print_ma(int* p, int row, int col) 
{
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << std::setw(2) << p[i * col + j] << " ";
		}

		std::cout << std::endl;	
	}
}

void transpose(int* p, int row, int col)
{

    const int sup = (row*col -1);
    const int under   = (row*col)/col;
    bool visited[row*col]{false};
    int cyc{0};
	while (++cyc != row*col) 
  	{
		if (visited[cyc])
			continue;
        int a = cyc;
        do  
        {
            a = a == sup ? sup : (under * a) % sup;
            std::swap(p[a], p[cyc]);
            visited[a] = true;
        }while ( a != cyc);
    }

}

