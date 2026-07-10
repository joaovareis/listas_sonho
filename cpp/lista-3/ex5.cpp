#include <iostream>

int main() {

    int seletor;
    std::string nome;
    int numero_usp;
    std::string departamento;
    std::string instituicao;

    std::cout<<"Qual tipo de pessoa esta utilizando o sistema?"<<std::endl;
    std::cout<<"1 - Aluno"<<std::endl;
    std::cout<<"2 - Professor"<<std::endl;
    std::cout<<"3 - Visitante"<<std::endl;
    std::cout<<"Digite a opcaoo: ";
    std::cin>>seletor;

    switch(seletor){

        case 1:
            std::cout<<"Digite seu nome: ";
            std::cin>>nome;

            std::cout<<"Digite seu numero USP: ";
            std::cin>>numero_usp;

            std::cout<<"Bem-vindo ao sistema."<<std::endl;
            std::cout<<"Tipo de usuario: Aluno"<<std::endl;
            std::cout<<"Nome: "<<nome<<std::endl;
            std::cout<<"Numero USP: "<<numero_usp<<std::endl;
            break;

        case 2:

            std::cout<<"Digite seu nome: ";
            std::cin>>nome;

            std::cout<<"Digite seu departamento: ";
            std::cin>>departamento;

            std::cout<<"Bem-vindo ao sistema."<<std::endl;
            std::cout<<"Tipo de usuario: Professor"<<std::endl;
            std::cout<<"Nome: "<<nome<<std::endl;
            std::cout<<"Departamento: "<<departamento<<std::endl;
            break;

        case 3:

            std::cout<<"Digite seu nome: ";
            std::cin>>nome;

            std::cout<<"Digite a instituicao de origem: ";
            std::cin>>instituicao;

            std::cout<<"Bem-vindo ao sistema."<<std::endl;
            std::cout<<"Tipo de usuario: Visitante"<<std::endl;
            std::cout<<"Nome: "<<nome<<std::endl;
            std::cout<<"Instituicao: "<<instituicao<<std::endl;
            break;

        default: 

            std::cout << "Opcao invalida" << std::endl;
            break;

    }

    return 0;
}