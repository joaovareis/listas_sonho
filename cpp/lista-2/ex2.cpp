#include <iostream>
#include <iomanip>

int main() {

    float a = 1.0 / 3.0;
    double b = 1.0 / 3.0;
    long double c = 1.0 / 3.0;

    bool comp_a = (a*3 == 1);
    bool comp_b = (b*3 == 1);
    bool comp_c = (c*3 == 1);

    std::cout<<std::fixed<<std::setprecision(25);
    std::cout<<std::boolalpha;

    std::cout<<"float: "<<a<<" (Exatamente 1? "<<comp_a<<")"<<std::endl;
    std::cout<<"double: "<<b<<" (Exatamente 1? "<<comp_b<<")"<<std::endl;
    std::cout<<"long double: "<<c<<" (Exatamente 1? "<<comp_b<<")"<<std::endl;

    return 0;
}

//Dá true por que 3 é pequeno
//Se usar algo como 49, daí double e long double dão falso.