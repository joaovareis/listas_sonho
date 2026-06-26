#include <iostream>

using namespace std;

struct SensorDistancia { 
    int id;
    double leitura;

    SensorDistancia(int id_passado){
        id = id_passado;
        leitura = 0.0;
    }

};

int main() {

    SensorDistancia variavel(1);

    cout<<"Dados Sensor: "<<endl;

    cout<<"ID: "<<variavel.id<<endl;

    cout<<"Leitura: "<<variavel.leitura<<endl;

    return 0;

}