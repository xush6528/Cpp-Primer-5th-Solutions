#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::istream; using std::ostream;
#include <string>
using std::string;
#include <initializer_list>
using std::initializer_list;


class Employee{
    friend std::istream &read(std::istream &, Employee &);
    friend istream &operator>>(istream &, Employee &);
    friend ostream &operator<<(ostream &, const Employee &);
    friend Employee operator+(const Employee &, const Employee &);
    friend bool operator==(const Employee &, const Employee &);
    friend bool operator!=(const Employee &, const Employee &);
public:
    Employee(std::istream &is = std::cin){read(is, *this);}
    Employee(const std::string &ns, const std::string &ss,
             unsigned an, const std::string &ts, const std::string &is,
             double sn): name(ns), sex(ss), age(an), title(ts), inDate(is),
                         salmon(sn), salyear(sal_year()){};
    Employee &operator+=(const Employee &);
    Employee &operator=(initializer_list<string>);
private:
    std::string name;
    std::string sex;
    unsigned age;
    std::string title;
    std::string inDate;
    double salmon;
    double sal_year() const;
    double salyear;

};

std::istream &read(std::istream &is, Employee &per){
    is >> per.name >> per.sex >> per.age >> per.title
       >> per.inDate >> per.salmon;
    return is;
}
inline
double Employee::sal_year() const {
    if (salmon)
        return salmon * 12;
}

ostream &operator<<(ostream &os, const Employee &rhs){
    os << rhs.name << " " << rhs.sex << " " << rhs.age << " "
       << rhs.title << " " << rhs.inDate << " " << rhs.salmon
       << " " << rhs.salyear << " " << rhs.sal_year();
    return os;
}

istream &operator>>(istream &in, Employee &rhs){
    if (in){
        in >> rhs.name >> rhs.sex >> rhs.age >> rhs.title
           >> rhs.inDate >> rhs.salmon;
    } else {
        rhs = Employee();
    }
    return in;
}

bool operator==(const Employee &lhs, const Employee &rhs){
    return lhs.name == rhs.name && lhs.sex == rhs.sex &&
           lhs.age == rhs.age && lhs.title == rhs.title &&
           lhs.inDate == rhs.inDate && lhs.salmon == rhs.salmon &&
           lhs.salyear == rhs.salyear;
};

bool operator!=(const Employee &lhs, const Employee &rhs){
    return !(lhs == rhs);
};

int main() {}