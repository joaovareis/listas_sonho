#include <iostream>
#include <cmath>
#include <iomanip>

#define g 9.81

int main() {

    float theta;
    float v0;

    std::cout<<"Digite a velocidade inicial (m/s): ";
    std::cin>>v0;

    std::cout<<"Digite o angulo de lancamento (graus): ";
    std::cin>>theta;

    float Vx = v0 * std::cos(theta*M_PI/180);
    float Vy = v0 * std::sin(theta*M_PI/180);
    float t_voo = (2 * Vy) / g;
    float alcance = Vx * t_voo;
    float h_max = std::pow(Vy, 2) / (2 * g);

    std::cout<<""<<std::endl;
    std::cout<<"=========================================="<<std::endl;
    std::cout<<"           Analise de Projetil            "<<std::endl;
    std::cout<<"=========================================="<<std::endl;
    std::cout << std::setfill('.');
    std::cout<<std::fixed<<std::setprecision(2);

    std::cout<<std::left<<std::setw(25) <<"  Velocidade inicial"<<std::right<<std::setw(10) << v0<<" m/s"<<std::endl;
    std::cout<<std::left<<std::setw(25) <<"  Angulo de lancamento"<<std::right<<std::setw(10) << theta<<" graus"<<std::endl;

    std::cout<<"------------------------------------------"<<std::endl;

    std::cout<<std::left<<std::setw(25) <<"  Componente Vx"<<std::right<<std::setw(10) << Vx<<" m/s"<<std::endl;
    std::cout<<std::left<<std::setw(25) <<"  Componente Vy"<<std::right<<std::setw(10) << Vy<<" m/s"<<std::endl;

    std::cout<<"------------------------------------------"<<std::endl;

    std::cout<<std::left<<std::setw(25) <<"  Tempo de voo"<<std::right<<std::setw(10) << t_voo<<" s"<<std::endl;
    std::cout<<std::left<<std::setw(25) <<"  Alcance horizontal"<<std::right<<std::setw(10) << alcance<<" m"<<std::endl;
    std::cout<<std::left<<std::setw(25) <<"  Altura maxima"<<std::right<<std::setw(10) << h_max<<" m"<<std::endl;

    std::cout<<"=========================================="<<std::endl;

    return 0;
}