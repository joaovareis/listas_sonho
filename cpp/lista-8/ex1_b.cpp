#include <iostream>
#include <cmath>

int raizes(double A, double B, double C, double *x1, double *x2);

int main() {

    double a;
    std::cout<<"Digite o coeficiente a: ";
    std::cin>>a;

    double b;
    std::cout<<"Digite o coeficiente b: ";
    std::cin>>b;

    double c;
    std::cout<<"Digite o coeficiente c: ";
    std::cin>>c;

    std::cout<<"------ Pela funcao ------"<<std::endl;

    double* x1 = new double;
    double* x2 = new double;

    std::cout<<"Numero de raizes: "<<raizes(a, b, c, x1, x2)<<std::endl;
    std::cout<<"Raizes: "<<*x1<<", "<<*x2<<std::endl;

    delete x1;
    delete x2;
    
    return 0;
}

int raizes(double A, double B, double C, double *x1, double *x2) {

    double delta = pow(B, 2) - (4 * A * C);

    if (delta < 0){
        *x1 = 0;
        *x2 = 0;

        return 0;

    } else if (delta == 0) {
        *x1 = - ((B) / (2*A));
        *x2 = *x1;

        return 1;

    } else {
        *x1 = (-B + sqrt(delta))/(2*A);
        *x2 = (-B - sqrt(delta))/(2*A);

        return 2;

    }
}