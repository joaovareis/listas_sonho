#include <iostream>
#include <cmath>

void aplicar(double *arr, int n, double (*fn)(double));

void copiar(const double* arr, int n, double* copia);

double dobrar(double x);

double quadrado(double x);

double mod(double x);

int main() {
    
    double meu_array[5] = {-3.0, 1.5, -2.0, 4.0, -0.5};
    int tamanho = std::size(meu_array);

    double copia_dobra[tamanho];
    double copia_quadrada[tamanho];
    double copia_mod[tamanho];

    copiar(meu_array, tamanho, copia_dobra);
    copiar(meu_array, tamanho, copia_quadrada);
    copiar(meu_array, tamanho, copia_mod);

    aplicar(copia_dobra, tamanho, dobrar);
    aplicar(copia_quadrada, tamanho, quadrado);
    aplicar(copia_mod, tamanho, mod);

    std::cout<<"Dobrado: {";

    for (int i = 0; i < tamanho; i++) {

        if (i != tamanho - 1) {
            std::cout<<*(copia_dobra + i)<<", ";
        } else{
            std::cout<<*(copia_dobra + i);
        }
    }

    std::cout<<"}"<<std::endl;

    std::cout<<"Quadrado: {";

    for (int i = 0; i < tamanho; i++) {

        if (i != tamanho - 1) {
            std::cout<<*(copia_quadrada + i)<<", ";
        } else{
            std::cout<<*(copia_quadrada + i);
        }
    }

    std::cout<<"}"<<std::endl;

    std::cout<<"Absoluto: {";

    for (int i = 0; i < tamanho; i++) {

        if (i != tamanho - 1) {
            std::cout<<*(copia_mod + i)<<", ";
        } else{
            std::cout<<*(copia_mod + i);
        }
    }

    std::cout<<"}"<<std::endl;
    
    return 0;
}

void aplicar(double *arr, int n, double (*fn)(double)) {

    for (int i = 0; i < n; i++) {
        *(arr + i) = fn(*(arr+i));
    }
}

void copiar(const double* arr, int n, double* copia) {

    for(int i = 0; i < n; i++) {
        *(copia + i) = *(arr + i);
    }
}

double dobrar(double x) {
    return 2*x;
}

double quadrado(double x) {
    return pow(x, 2);
}

double mod(double x) {
    if (x > 0) {
        return x;

    } else {
        return -x;
        
    }
}
