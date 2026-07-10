#include <iostream>

int main(){

    int a;
    int b;

    std::cout<<"Digite o primeiro numero: ";
    std::cin>>a;

    std::cout<<"Digite o segundo numero: ";
    std::cin>>b;

    if (a > b){
        std::cout<<"O primeiro e maior"<<std::endl;

    } else if (b > a){
        std::cout<<"O segundo e maior"<<std::endl;

    } else:: std::cout<<"Sao iguais"<<std::endl;

    return 0;
}