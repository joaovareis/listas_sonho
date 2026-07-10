#include <iostream>
#include <iomanip>
#include <vector>

int main() {

    std::vector<float> leituras = {5.0, -12.5, 3.4, -4.2, 5.0};
    int contador;

    for(int i = 0; i < 5; i++) {
         
        if (leituras[i] > 0) {
            std::cout<<std::fixed;
            std::cout<<"Leitura "<<std::setprecision(0)<<i+1<<" registrada: "<<std::setprecision(2)<<leituras[i]<<std::endl;

        } else {
            std::cout<<"[Erro] Leitura "<<std::setprecision(0)<<i+1<<" ignorada por ruido."<<std::endl;
        }
    }

    return 0;

}