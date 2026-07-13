#include <iostream>

void findMininum(const double *arr, int size, double *min);

void findMaximum(const double *arr, int size, double *min);

double media(const double *arr, int size);

int main() {

    double meus_numeros[4] = {-3.0, -1.0, -5.0, -2.0};

    double* max = new double;
    double* min = new double;

    findMininum(meus_numeros, std::size(meus_numeros), min);
    findMaximum(meus_numeros, std::size(meus_numeros), max);

    std::cout<<*max<<std::endl;
    std::cout<<*min<<std::endl;
    std::cout<<media(meus_numeros, std::size(meus_numeros))<<std::endl;

    delete min;
    delete max;

    return 0;
}

void findMininum(const double *arr, int size, double *min) {

    *min = *arr;

    for (int i = 0; i < size; i++){

        if (*(arr + i) < *min){

            *min = *(arr + i);
        }
    }
}

void findMaximum(const double *arr, int size, double *max) {

    *max = *arr;

    for (int i = 0; i < size; i++){

        if (*(arr + i) > *max){

            *max = *(arr + i);
        }
    }
}

double media(const double *arr, int size) {

    double sum;

    for(int i; i < size; i++) {
        sum += *(arr + i);
    }

    return sum/size;
}

