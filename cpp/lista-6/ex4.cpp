#include <vector>
#include <iostream>

int main() {

    float entrada;
    int sala = 0;

    std::vector<std::vector<float>> todas_leituras;
    std::vector<float> leituras;

    while(entrada != -2) {

        std::cout<<"Digite a leitura: ";
        std::cin>>entrada;

        if (entrada == -1) {
            
            todas_leituras.push_back(leituras);
            leituras.clear();

        } else if (entrada != -2) {

            leituras.push_back(entrada);
        }

    }

    std::cout<<"--- Relatorio de Varredura Multissetorial ---"<<std::endl;

    for(int i = 0; i < todas_leituras.size(); i++) {

        std::cout<<"Setor ["<<i<<"]: "<<todas_leituras[i].size()<<" obstaculo(s) encontrado(s). Dados: ";

        for (int j = 0; j < todas_leituras[i].size(); j++) {
            std::cout<<"["<<todas_leituras[i][j]<<"]";
        }

        std::cout<<std::endl;
    }

    std::cout<<"Status: Processamento de mapa finalizado."<<std::endl;

}