#include <array>
#include <iostream>
#include <vector>
#include <string>

enum class Month{January = 1,February, March, April, May, June, July, August, September, October, November, December};

class Date{
    int myday;
    Month mymonth;
    unsigned int myyear;
    std::string print_month(const Month m) const noexcept;
    void increment_day() noexcept {myday++;}
    void increment_year() noexcept {myyear++;}
    void increment_month() noexcept {Month opt{mymonth}; int a{static_cast<int>(opt)};  if(a==12){mymonth = Month(1);} else{mymonth =Month(a+1);}}
    void _next_day(int& x, const Month m) noexcept;
public:
    void next_day() noexcept{ _next_day(myday, mymonth);}
    void add_days(const unsigned int n) {for (unsigned int i = 0; i < n; i++){next_day();}}
    int day() const noexcept {return myday;}
    std::string month()  const noexcept {return print_month(mymonth);}
    unsigned int year() const noexcept {return myyear;}
    void print_date() const noexcept;
     Date(int&& myday, Month&& mymonth, unsigned int&& myyear ): myday{myday}, mymonth{mymonth}, myyear{myyear} { };
    ~Date() noexcept=default;

};
void Date::print_date() const noexcept{
std::cout << "Day " << myday << "\n"
<< "Month " << print_month(mymonth)<< "\n"
<< "Year " << myyear<< std::endl;
return;}

bool operator==(const Date& lhs, const Date& rhs){
    if(lhs.day()==rhs.day() and lhs.month()==rhs.month() and lhs.year() == rhs.year()){
        return true;
    }
    else{
        return false;
    }
}
bool operator!=(const Date& lhs, const Date& rhs){
    return !(lhs.day()==rhs.day() and lhs.month()==rhs.month() and lhs.year() == rhs.year());
}


void Date::_next_day(int& x, const Month m) noexcept{
    switch(m){
        case Month::February:
            if (x==28) {
                myday = 1;
                increment_month();
            }
            else{
                increment_day();
            }
            break;
        case Month::November: case Month::April: case Month::June: case Month::September:
            if (x==30) {
                myday = 1;
                increment_month();
            }
            else{
                increment_day();
            }
            break;
        case Month::December:
            if (x==31) {
                myday = 1;
                increment_month();
                increment_year();
            }
            else{
                increment_day();
            }
            break;
        default:
            if (x==31) {
                myday = 1;
                increment_month();
            }
            else{
                increment_day();
            }
    };
}

std::string Date::print_month( const Month m) const noexcept {
    switch(m){
        case Month::January:{
            std::string a{"January"};
            return a;}
        case Month::February:{
            std::string a{"February"};
            return a;}
        case Month::March:{
            std::string a{"March"};
            return a;}
        case Month::April:{
            std::string a{"April"};
            return a;}
        case Month::May:{
            std::string a{"May"};
            return a;}
        case Month::June:{
            std::string a{"June"};
            return a;}
        case Month::July:{
            std::string a{"July"};
            return a;}
        case Month::August:{
            std::string a{"August"};
            return a;}
        case Month::September:{
            std::string a{"September"};
            return a;}
        case Month::October:{
            std::string a{"October"};
            return a;}
        case Month::November:{
            std::string a{"November"};
            return a;}
        case Month::December:{
            std::string a{"December"};
            return a;}
        default:{
            std::string a{"Unknown method"};
            return a;}
    };
}


int main()
{

	Date l{28,Month::January,1997};
    Date s{28,Month::January,1997};
    l.print_date();
    s.print_date();
    bool a{s==l};
    std::cout << a << std::endl;
    return 0;
}