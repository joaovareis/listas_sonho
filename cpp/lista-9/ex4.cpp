#include <iostream>
#include <cctype>
#include <cstring>

void rot13(char* arr);

int main() {

    char arr[100];

    std::cout<<"Digite a frase: ";
    std::cin.getline(arr, 100);

    rot13(arr);

    for(int i = 0; i < strlen(arr); i++) {
        std::cout<<*(arr + i);
    }

    std::cout<<std::endl;

    rot13(arr);

    for(int i = 0; i < strlen(arr); i++) {
        std::cout<<*(arr + i);
    }

    return 0;

}

void rot13(char* arr) {

    int arr_size = strlen(arr);

    for (int i = 0; i < arr_size; i++) {

        int ascii_nmbr = static_cast<int>(*(arr + i));

        if (ascii_nmbr > 64 and ascii_nmbr < 78) {
            ascii_nmbr += 13;

        } else if(ascii_nmbr > 77 and ascii_nmbr < 91) {
            ascii_nmbr -=13;

        } else if(ascii_nmbr > 96 and ascii_nmbr < 110 ) {
            ascii_nmbr += 13;

        } else if(ascii_nmbr > 109 and ascii_nmbr < 123) {
            ascii_nmbr -= 13;
        }

        *(arr + i) = static_cast<char>(ascii_nmbr);
    }
}