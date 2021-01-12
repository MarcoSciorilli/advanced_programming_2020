#include <iostream>
#include <string>

void line_formatter(int& a);


int main() 
{
  int a;
  std::cout << "Number of characters per line:\n";  
  std::cin >> a;
  std::cin.ignore(1000,'\n');
  line_formatter(a);
  return 0;
}


void line_formatter(int& a) 
{
  int count{0};
  int i{0};
  std::string text;
  std::cout << "Testo da impaginare:\n";
  std::getline(std::cin,text);
  std::cout << "Testo impaginato:\n";
  for (char & c : text)
  {
    count+=1;
    if (count % a ==0)
    {
      if (c==' ')
      {
        text.erase (text.begin()+count-1);
        text.insert(count-1, "\n");
      }
      else
      {
        i=0;
        for(;;)
        {
          if (text.at(count-i) == ' ')
          {
            text.erase (text.begin()+count-i);
            text.insert(count-i, "\n");
            break;
          }
          i+=1;
        }    
      }
 
    }
  }
  std::cout<< text<< "\n";
}std::cout << "Testo impaginato:\n";