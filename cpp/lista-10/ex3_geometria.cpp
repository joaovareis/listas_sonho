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

int main() {

    PontoCartesiano origem = {};
    PontoCartesiano alvo = {3, 4};

    float distancia = origem.calcularDistanciaAte(alvo);

    cout<<"Distancia: "<<distancia<<endl;

    return 0;

}