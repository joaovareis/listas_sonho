#include <iostream>
#include <cmath>

int main() {

    int* ptr_a = new int;
    std::cout<<"Digite o coeficiente a: ";
    std::cin>>*ptr_a;

    int* ptr_b = new int;
    std::cout<<"Digite o coeficiente b: ";
    std::cin>>*ptr_b;

    int* ptr_c = new int;
    std::cout<<"Digite o coeficiente c: ";
    std::cin>>*ptr_c;

    std::cout<<"------ Pela main ------"<<std::endl;

    float* delta = new float;

    *delta = pow(*ptr_b, 2) - (4 * *ptr_a * *ptr_c);

    if (*delta < 0) {
        std::cout<<"Sem raizes reais"<<std::endl;

    } else if (*delta == 0) {

        float* raiz = new float;
        *raiz = -(*ptr_b)/(2 * *ptr_a);

        std::cout<<"Unica raiz: "<<*raiz<<std::endl;

        delete raiz;

    } else {

        float* raiz_1 = new float;
        float* raiz_2 = new float;

        *raiz_1 = (-(*ptr_b) + sqrt(*delta))/(2 * *ptr_a);
        *raiz_2 = (-(*ptr_b) - sqrt(*delta))/(2 * *ptr_a);

        std::cout<<"Raizes: "<<*raiz_1<<", "<<*raiz_2<<std::endl;

        delete raiz_1;
        delete raiz_2;

    }

    delete ptr_a;
    delete ptr_b;
    delete ptr_c;
    delete delta;

    return 0;

}
