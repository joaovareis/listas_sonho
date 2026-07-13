#include <iostream>

void orderValues(double *a, double *b, double *c);

int main() {

    double a;
    std::cout<<"Digite o primeiro valor: ";
    std::cin>>a;

    double* ptr_a = &a;

    double b;
    std::cout<<"Digite o segundo valor: ";
    std::cin>>b;

    double* ptr_b = &b;

    double c;
    std::cout<<"Digite o terceiro valor: ";
    std::cin>>c;

    double* ptr_c = &c;

    orderValues(ptr_a, ptr_b, ptr_c);

    std::cout<<"O valores ordenados sao: "<<*ptr_a<<", "<<*ptr_b<<", "<<*ptr_c<<std::endl;

}

void orderValues(double *a, double *b, double *c) { //devolver a < b < c

    if (*a > *b) {
        std::swap(*a, *b);
    }

    if(*a > *c) {
        std::swap(*a, *c);
    }

    if(*b > *c) {
        std::swap(*b, *c);
    }
}