#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>

int main() {

    char arr[100];
    char username[100];
    std::vector<int> pos_espaco;

    std::cout<<"Digite o nome: ";
    std::cin.getline(arr, 100);

    int size = strlen(arr);
    bool tem_espaco = false;

    for(int i = 0; i < size; i ++) {

        if (isspace(*(arr+i))) {
            tem_espaco = true;
            pos_espaco.push_back(i);
        }
    }

    if (not tem_espaco) {
        std::cout<<"Nome invalido: deve conter pelo menos um sobrenome"<<std::endl;
        return 0;
    }

    std::cout<<"Primeiro nome: ";

    for(int i = 0; i < pos_espaco[0]; i++) {

        *(username + i) = *(arr + i);
        std::cout<<*(arr + i);
    }

    std::cout<<std::endl;

    std::cout<<"Sobrenome: ";

    *(username + pos_espaco[0]) = '.';

    for (int i = 0; i < (size - pos_espaco.back()); i ++) {

        *(username + pos_espaco[0] + 1 + i) = *(arr + pos_espaco.back() + 1 + i);
        std::cout<<*(arr + pos_espaco.back() + 1 + i);
    }

    *(username + size) = '\0';
    
    std::cout<<std::endl;
    
    std::cout<<"Usuario: ";

    for(int i = 0; i <strlen(username); i++) {

        *(username + i) = static_cast<char>(tolower(*(username + i)));

        std::cout<<*(username + i);
    }

    std::cout<<std::endl;

    std::cout<<"Comprimento: "<<size - pos_espaco.size()<<std::endl;

    return 0;

}