#include <iostream>
#include <cmath>

using namespace std;

struct PontoCartesiano { 
    float x;
    float y;

    PontoCartesiano(){
        x = 0.0;
        y = 0.0;
    }

    PontoCartesiano(float x_inicial, float y_inicial) {
        x = x_inicial;
        y = y_inicial;
    }

    float calcularDistanciaAte(PontoCartesiano alvo) {

        float dx = x - alvo.x;
        float dy = y - alvo.y;

        return sqrt(pow(dx,2) + pow(dy, 2));
    }

};

enum class ModoNavegacao {
    AGUARDANDO,
    EM_ROTA,
    DESTINO_ALCANCADO,
};

struct Robo {
    ModoNavegacao modo;       
    PontoCartesiano posicao;

    Robo(){
        modo = ModoNavegacao::AGUARDANDO;
        posicao = PontoCartesiano {};
    }

};

void atualizarRobo(Robo* ptr_robo, PontoCartesiano alvo) {

    float distancia = 0.0;

    switch(ptr_robo->modo){

        case ModoNavegacao::AGUARDANDO:

            ptr_robo->modo = ModoNavegacao::EM_ROTA;
            cout<<"Robo saiu de AGUARDANDO para EM_ROTA"<<endl;

            break;

        case ModoNavegacao::EM_ROTA:

            distancia = ptr_robo->posicao.calcularDistanciaAte(alvo);
            cout<<"Distancia ate alvo: "<<distancia<<endl;
        
            if (distancia < 0.1){
  
                ptr_robo->modo = ModoNavegacao::DESTINO_ALCANCADO;
                cout<<"Robo saiu de EM_ROTA para DESTINO_ALCANCADO"<<endl;
            }
            break;

        case ModoNavegacao::DESTINO_ALCANCADO:

            cout<<"DESTINO_ALCANCADO Robo encerrado"<<endl;
            break;
    }

};

int main(){

    Robo meu_robo;
    
    PontoCartesiano alvo(0.03f, 0.04f);

    atualizarRobo(&meu_robo, alvo);
    atualizarRobo(&meu_robo, alvo);
    atualizarRobo(&meu_robo, alvo);

}