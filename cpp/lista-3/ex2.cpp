#include <iostream>

int main(){

    int a;
    int b;

    std::cout<<"Digite o primeiro numero: ";
    std::cin>>a;

    std::cout<<"Digite o segundo numero: ";
    std::cin>>b;

    if (b == 0){
        std::cout<<"Nao e possivel dividir por zero"<<std::endl;

    } else:: std::cout<<"O resultado e: "<<a/b<<std::endl;

    return 0;
}