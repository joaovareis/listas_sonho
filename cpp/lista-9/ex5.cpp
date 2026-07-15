#include <iostream>
#include <cstring>
#include <cctype>

void repeatKey (char* arr, char* key, int* decoder);
void encode (char* arr, int* decoder, char* codigo);
void decode(char* codigo, int* decoder, char* arr);

int main() {
    char arr[100];
    char key[100];
    int decoder[100];
    char codigo[100];

    std::cout<<"Digite a frase: ";
    std::cin.getline(arr, 100);

    std::cout<<"Digite a chave: ";
    std::cin.getline(key, 100);

    repeatKey(arr, key, decoder);
    encode(arr, decoder, codigo);

    for(int i = 0; i < strlen(codigo); i++){
        std::cout<<*(codigo + i);
    }

    std::cout<<std::endl;

    decode(codigo, decoder, arr);

    for(int i = 0; i < strlen(arr); i++){
        std::cout<<*(arr + i);
    }
}

void decode(char* codigo, int* decoder, char* arr) {
    int size_arr = strlen(codigo);

    for(int i = 0; i < size_arr; i++){

        int ascii_nmbr = static_cast<int>(*(codigo + i));

        if (ascii_nmbr > 64 and ascii_nmbr < 91) {
            ascii_nmbr = ascii_nmbr - 65 - *(decoder + i);

            if (ascii_nmbr < 0) {
                ascii_nmbr += 26;
            } 

            *(arr + i) = static_cast<char>(ascii_nmbr + 65);

        } else if(ascii_nmbr > 96 and ascii_nmbr < 123) {
            ascii_nmbr = ascii_nmbr - 97 - *(decoder + i);

            if (ascii_nmbr < 0) {
                ascii_nmbr += 26;
            } 

            *(arr + i) = static_cast<char>(ascii_nmbr + 97);

        } else {
            *(arr + i) = *(codigo + i);
        }
    }
}

void encode (char* arr, int* decoder, char* codigo) {

    int size_arr = strlen(arr);

    for(int i = 0; i < size_arr; i++){

        int ascii_nmbr = static_cast<int>(*(arr + i));

        if (ascii_nmbr > 64 and ascii_nmbr < 91) {
            
            ascii_nmbr = ascii_nmbr - 65 + *(decoder + i);

            if (ascii_nmbr > 25) {
                ascii_nmbr -= 26;
            } 

            *(codigo + i) = static_cast<char>(ascii_nmbr + 65);

        } else if(ascii_nmbr > 96 and ascii_nmbr < 123) {
            ascii_nmbr = ascii_nmbr - 97 + *(decoder + i);

            if (ascii_nmbr > 25) {
                ascii_nmbr -= 26;
            } 

            *(codigo + i) = (ascii_nmbr + 97);

        } else {
            *(codigo + i) = *(arr + i);
        }
    }
}

void repeatKey (char* arr, char* key, int* decoder) {
    
    int size_arr = strlen(arr);
    int size_key = strlen(key);

    for(int i = 0; i < size_key; i++) {
        *(key + i) = toupper(*(key + i));
    }

    int key_index = 0;

    for(int i = 0; i < size_arr; i++) {

        if(isalpha(*(arr + i))) {
            if (key_index < size_key) {
                decoder[i] = static_cast<int>(*(key + key_index)) - 65;
                key_index++;

            } else {
                key_index = 1;
                decoder[i] = static_cast<int>(*(key)) - 65;
            }

        } else {
            decoder[i] = -1;
        }
    }
}

