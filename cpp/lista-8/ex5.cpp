#include <iostream>
#include <vector>

void dobrarLimiar(std::vector<double>* arr, const double* limiar);

void showVector(const std::vector<double> *arr);

int main() {

    std::cout<<"----- Caso 1 -----"<<std::endl;

    std::vector<double> vetor_1 = {1.5, 4.0, 0.8, 5.2, 2.1, 6.0};
    std::vector<double>* ptr_1 = &vetor_1;
    double limiar = 3.0;

    showVector(ptr_1);

    dobrarLimiar(ptr_1, &limiar);

    showVector(ptr_1);

    std::cout<<"----- Caso 2 -----"<<std::endl;

    std::vector<double> vetor_2 =  {0.5, 0.5, 0.5};
    std::vector<double>* ptr_2 = &vetor_2;
    limiar = 1.0;

    showVector(ptr_2);

    dobrarLimiar(ptr_2, &limiar);
    
    showVector(ptr_2);

    std::cout<<"----- Caso 3 -----"<<std::endl;

    std::vector<double> vetor_3 = {5.0, 6.0, 7.0};
    std::vector<double>* ptr_3 = &vetor_3;
    limiar = 3.0;

    showVector(ptr_3);

    dobrarLimiar(ptr_3, &limiar);
    
    showVector(ptr_3);

}

void dobrarLimiar(std::vector<double>* arr, const double* limiar) {

    for(int i = 0; i < arr->size(); i++ ){

        if (*(arr->data() + i) < *limiar) {

            *(arr->data() + i) += *(arr->data() + i);

        }
    }
}

void showVector(const std::vector<double> *arr) {

    std::cout<<"{";

    for(int i = 0; i < arr->size(); i++ ){

        if (i != arr->size() - 1 ) {
            std::cout<<*(arr->data() + i)<<", ";

        } else {
            std::cout<<*(arr->data() + i);
        }

    }

    std::cout<<"}"<<std::endl;

}
