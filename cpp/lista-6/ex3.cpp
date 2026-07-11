#include <map>
#include <iostream>

int main() {
    
    std::map<std::string, int> erros;

    int cod_erro;

    while (cod_erro != -1) {

        std::cout<<"Inisira o ID do erro: ";
        std::cin>>cod_erro;

        erros[std::to_string(cod_erro)] += 1;
    }

    std::cout<<"--- Relatorio de Erros ANYmal ---"<<std::endl;

    for(const auto& [cod_erro, count] : erros) {

        if (cod_erro != "-1") {
            std::cout<<"Componente ["<<cod_erro<<"]: "<<count<<" falha(s) detectadas."<<std::endl;
            
        }
    }
}