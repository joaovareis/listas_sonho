#include <iostream>
#include <cstring>
#include <cctype>

void atBash(char* arr);

int main() {

    char arr[100];

    std::cout<<"Digite a frase: ";
    std::cin.getline(arr, 100);

    atBash(arr);

    for(int i = 0; i < strlen(arr); i++) {
        std::cout<<*(arr + i);
    }

    std::cout<<std::endl;

    atBash(arr);

    for(int i = 0; i < strlen(arr); i++) {
        std::cout<<*(arr + i);
    }

    return 0;
}

void atBash(char* arr) {
    
    int size_str = strlen(arr);

    for(int i = 0; i < size_str; i++){

        if(isalpha(*(arr + i))) {

            if(islower(*(arr + i))) {

                *(arr + i) = static_cast<char>(- static_cast<int>(*(arr+i)) + 219);

            } else {

                *(arr + i) = static_cast<char>(- static_cast<int>(*(arr+i)) + 155);
            }
        }
    }

}