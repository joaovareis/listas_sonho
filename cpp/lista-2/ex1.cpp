#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

    float cat_a;
    float cat_b;

    std::cout<<"Digite o cateto a: ";
    std::cin>>cat_a;

    std::cout<<"Digite o cateto b: ";
    std::cin>>cat_b;

    float hip = std::sqrt(std::pow(cat_a, 2) + std::pow(cat_b, 2));

    float area = (cat_a * cat_b) / 2;

    float alpha = std::atan(cat_a/cat_b) * (180 / M_PI);

    std::cout<<std::fixed<<std::setprecision(2);

    int col = 18;

    std::cout<<""<<std::endl;
    std::cout<<"==================================="<<std::endl;
    std::cout<<"        Triangulo Retangulo        "<<std::endl;
    std::cout<<"==================================="<<std::endl;

    std::cout   <<std::left<<std::setw(20) <<" Cateto a: "          <<std::right<<std::setw(12) <<cat_a<<std::endl;
    std::cout   <<std::left<<std::setw(20) <<" Cateto b: "          <<std::right<<std::setw(12) <<cat_b<<std::endl;
    std::cout   <<std::left<<std::setw(20) <<" Hipotenusa: "        <<std::right<<std::setw(12) <<hip<<std::endl;
    std::cout   <<std::left<<std::setw(20) <<" Area: "              <<std::right<<std::setw(12) <<area<<std::endl;
    std::cout   <<std::left<<std::setw(20) <<" Angulo (graus): "    <<std::right<<std::setw(12) <<alpha<<std::endl;

    std::cout<<"==================================="<<std::endl;

    return 0;
}