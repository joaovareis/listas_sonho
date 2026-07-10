#include <iostream>

int main() {

    int ano;

    std::cout<<"Digite o ano: ";
    std::cin>>ano;

    if (ano%400 == 0) {
        std::cout<<"Parabens, e bissexto"<<std::endl;

    } else if (ano%100 == 0){
        std::cout<<"Nao e bissexto"<<std::endl;

    } else if (ano%4 == 0) {
        std::cout<<"Parabens, e bissexto"<<std::endl;

    } else{
        std::cout<<"Nao e bissexto"<<std::endl;
    }

    return 0;
}