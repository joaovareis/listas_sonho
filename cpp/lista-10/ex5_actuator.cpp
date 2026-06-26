#include <iostream>

using namespace std;

struct AtuadorLinear { 
    int id_atuador;
    double extensao_atual;

};

int main() {

    AtuadorLinear array[3];

    array[0].extensao_atual = 1;
    array[0].id_atuador = 6;

    array[1].extensao_atual = 2;
    array[1].id_atuador = 7;

    array[2].extensao_atual = 3;
    array[2].id_atuador = 8;

    int indice_maior = 0; 

    for (int i = 1; i < 3; i++) {
        if (array[i].extensao_atual > array[indice_maior].extensao_atual) {
            indice_maior = i;
        }
    }

    cout<<"Atuador com maior extensao: "<<array[indice_maior].id_atuador<<endl;

    return 0;

}