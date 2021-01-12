#include <iostream>
#include <string>


int main() {
  std::cout << "Inserire grandezza:\n ";
  std::string unit;
  double size;
  std::cin >> size >> unit;
  double newSize{size *  0.025 };
  std::cout << " " <<  newSize  << " m \n";
    return 0;
}
