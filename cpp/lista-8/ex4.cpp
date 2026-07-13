#include <iostream>
#include <cmath>

double mediaSimples(const double *arr, int size);

void desvioSimples(const double *arr, const int size, const double media, double *arr_result);

void desvioQuadratico(const double *arr, const int size, double *arr_result);

int main() {

    std::cout<<"----- Caso 1 -----"<<std::endl;

    double meu_array[8] = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
    double media;

    double array_simples[8];
    double array_quadratico[8];

    media = mediaSimples(meu_array, std::size(meu_array));

    desvioSimples(meu_array, std::size(meu_array), media, array_simples);
    desvioQuadratico(array_simples, std::size(meu_array), array_quadratico);

    std::cout<<"Media: "<<media<<std::endl;

    std::cout<<"Desvio Simples: ";
    for(int i = 0; i < std::size(meu_array); i++) {
        std::cout<<*(array_simples + i)<<", ";
    }
    std::cout<<std::endl;
    
    std::cout<<"Desvio Quadrado: ";
    for(int i = 0; i < std::size(meu_array); i++) {
        std::cout<<*(array_quadratico + i)<<", ";
    }
    std::cout<<std::endl;
    return 0;
}

double mediaSimples(const double *arr, int size) {
    double sum;

    for(int i = 0; i < size; i++) {

        sum +=*(arr + i);
    } 
    
    return sum/size;
}

void desvioSimples(const double *arr, const int size, const double media, double *arr_result) {

    for (int i = 0; i < size; i++) {

        *(arr_result + i) = *(arr + i) - media;

    }
}

void desvioQuadratico(const double *arr, const int size, double *arr_result) {

    for (int i = 0; i < size; i++) {

        *(arr_result + i) = pow(*(arr + i), 2);
    }
}