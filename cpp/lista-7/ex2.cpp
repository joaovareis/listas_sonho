#include <iostream>
#include <utility>
#include <iomanip>
#include <cmath>

void exibir(double real, double imaginaria);

void Complexo(std::pair<double, double> z1, std::pair<double, double> z2, std::string op);

int main() {

    std::pair<double,double> z1 {1.0, 2.0};
    std::pair<double,double> z2 {3.0, -1.0};
    std::pair<double,double> z3 {5.0, 3.0};
    std::pair<double,double> z4 {2.0, 1.0};
    std::pair<double,double> z5 {3.0, 4.0};
    std::pair<double,double> z6 {2.0, 3.0};
    Complexo(z1, z2, "soma");
    Complexo(z3, z4, "subtracao");
    Complexo(z1, z2, "produto");
    Complexo(z1, z2, "divisao");
    Complexo(z5, z5, "modulo");
    Complexo(z6, z6, "conjugado");

    return 0;

}

void exibir(double real, double imaginaria) {

    if (imaginaria >= 0) {
        std::cout<<"("<<real<<" + "<<imaginaria<<"i)";

    } else {
        std::cout<<"("<<real<<" - "<<abs(imaginaria)<<"i)";
    }

}

void Complexo(std::pair<double, double> z1, std::pair<double, double> z2, std::string op) {

    if (op == "soma"){

        std::cout<<std::setw(15)<<std::left<<"soma: ";
        exibir(z1.first, z1.second);
        std::cout<<" + ";
        exibir(z2.first, z2.second);
        std::cout<<" = ";
        exibir(z1.first + z2.first, z1.second + z2.second);
        std::cout<<std::endl;

    } else if (op == "subtracao"){

        std::cout<<std::setw(15)<<std::left<<"subtracao: ";
        exibir(z1.first, z1.second);
        std::cout<<" - ";
        exibir(z2.first, z2.second);
        std::cout<<" = ";
        exibir(z1.first - z2.first, z1.second - z2.second);
        std::cout<<std::endl;

    } else if (op == "produto"){

        std::cout<<std::setw(15)<<std::left<<"produto: ";
        exibir(z1.first, z1.second);
        std::cout<<" * ";
        exibir(z2.first, z2.second);
        std::cout<<" = ";

        double re = z1.first*z2.first - z1.second*z2.second;
        double im = z1.first*z2.second + z2.first*z1.second;

        exibir(re, im);
        std::cout<<std::endl;

    } else if (op == "divisao"){

        std::cout<<std::setw(15)<<std::left<<"divisao: ";
        exibir(z1.first, z1.second);
        std::cout<<" / ";
        exibir(z2.first, z2.second);
        std::cout<<" = ";

        double d = z2.first*z2.first + z2.second*z2.second;
        double re = (z1.first*z2.first + z1.second*z2.second)/d;
        double im = (z2.first*z1.second - z1.first*z2.second)/d;

        exibir(re, im);
        std::cout<<std::endl;

    } else if (op == "modulo"){

        std::cout<<std::setw(15)<<std::left<<"modulo: ";
        if (z1.second >= 0) {
            std::cout<<"|"<<z1.first<<" + "<<z1.second<<"i|";

        } else {
            std::cout<<"|"<<z1.first<<" + "<<z1.second<<"i|";
        }

        std::cout<<"            = "<<sqrt(pow(z1.first,2) + pow(z1.second, 2))<<std::endl;

    } else if (op == "conjugado") {

        std::cout<<std::setw(15)<<std::left<<"conjugado: ";
        if (z1.second >= 0) {
            std::cout<<"("<<z1.first<<" + "<<z1.second<<"i)*";

        } else {
            std::cout<<"("<<z1.first<<" + "<<z1.second<<"i)*";
        }

        std::cout<<"           = ";
        exibir(z1.first, -z1.second);

    }
}