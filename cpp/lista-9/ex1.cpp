#include <iostream>
#include <cctype>
#include <cstring>

int main() {

    char arr[50];

    std::cout<<"Digite a placa: ";
    std::cin.getline(arr, 50);

    int size = strlen(arr);
    bool validez = true;

    if (size != 7) {
        std::cout<<"Placa invalida: deve ter 7 caracteres"<<std::endl;
        return 0;

    } else {

        for(int i = 0; i < 7; i++) {

            *(arr+i) = static_cast<char>(toupper(*(arr + i)));
        }
    }

    for(int i = 0; i < 3; i++) {

        if (not isalpha(*(arr + i))) {
            validez = false;
        }
    }

    if(not isdigit(*(arr + 3)) or not isdigit(*(arr + 5)) or not isdigit(*(arr + 6))) {
        validez = false;
    }

    if(not isalpha(*(arr + 4))) {
        validez = false;
    }

    if (validez) {
        std::cout<<"Placa valida: ";
        for(int i = 0; i < 7; i++) {
            std::cout<<*(arr+i);
        }
    } else {
        std::cout<<"Placa invalida: formato incorreto"<<std::endl;
    }

    return 0;
}