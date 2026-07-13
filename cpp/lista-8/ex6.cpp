#include <iostream>
#include <utility>
#include <vector>

int coletar_negativos(const double *arr, int n, std::pair<double, int> *resultado);

int main() {

    std::cout<<"----- Caso 1 -----"<<std::endl;

    double array_1[5] = {3.5, 1.2, -4.8, 7.1, -0.5};

    std::pair<double, int> arr_result_1[std::size(array_1)];

    int num_neg;

    num_neg = coletar_negativos(array_1, std::size(array_1), arr_result_1);

    if (num_neg) {

        std::cout<<num_neg<<" negativos: ";

        for(int i = 0; i<std::size(arr_result_1); i++) {

            if((arr_result_1 + i)->first != 0) {

                std::cout<<"("<<(arr_result_1 + i)->first<<", indice "<<(arr_result_1 + i)->second<<")";
            }
        }
    } else {
        
        std::cout<<"Nenhum negativo encontrado"<<std::endl;
    }

    std::cout<<std::endl;

    std::cout<<"----- Caso 2 -----"<<std::endl;

    double array_2[4] = {-1.0, -2.0, -3.0, -4.0};
    std::pair<double, int> arr_result_2[std::size(array_2)];

    num_neg = coletar_negativos(array_2, std::size(array_2), arr_result_2);

    if (num_neg) {

        std::cout<<num_neg<<" negativos: ";

        for(int i = 0; i<std::size(arr_result_2); i++) {

            if((arr_result_2 + i)->first != 0) {

                std::cout<<"("<<(arr_result_2 + i)->first<<", indice "<<(arr_result_2 + i)->second<<") ";
            }
        }
    } else {
        
        std::cout<<"Nenhum negativo encontrado"<<std::endl;
    }

    std::cout<<std::endl;

    std::cout<<"----- Caso 3 -----"<<std::endl;

    double array_3[4] = {1.0, 2.0, 3.0, 4.0};
    std::pair<double, int> arr_result_3[std::size(array_3)];

    num_neg = coletar_negativos(array_3, std::size(array_3), arr_result_3);

    if (num_neg) {

        std::cout<<num_neg<<" negativos: ";

        for(int i = 0; i<std::size(arr_result_3); i++) {

            if((arr_result_3 + i)->first != 0) {

                std::cout<<"("<<(arr_result_3 + i)->first<<", indice "<<(arr_result_3 + i)->second<<")";
            }
        }
    } else {

        std::cout<<"Nenhum negativo encontrado"<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

int coletar_negativos(const double *arr, int n, std::pair<double, int> *resultado) {

    int num_negativos = 0;

    for (int i = 0; i < n; i++) {

        if (*(arr + i) < 0) {

            *(resultado + num_negativos) = {*(arr + i), i};
            num_negativos++;
        }
    }

    return num_negativos;
}