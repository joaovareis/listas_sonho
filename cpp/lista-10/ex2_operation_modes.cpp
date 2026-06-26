#include <iostream>

using namespace std;

enum class EstadoSistema {
    INICIALIZANDO,
    OPERANDO,
    ERRO_SENSOR,
};

int main(){

    EstadoSistema variavel = EstadoSistema::OPERANDO;

    switch(variavel){

        case EstadoSistema::INICIALIZANDO:

            cout<<"Robo iniciando"<<endl;
            break;

        case EstadoSistema::OPERANDO:

            cout<<"Robo operando"<<endl;
            break;

        case EstadoSistema::ERRO_SENSOR:

            cout<<"Robo com erro"<<endl;
            break;
    }

    return 0;

}