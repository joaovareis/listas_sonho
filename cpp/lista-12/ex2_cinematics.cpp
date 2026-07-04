#include <iostream>

class Robo {

    private:
    std::string identificador;
    float posicaoAtual;

    protected:
    float massa;

    public:

    Robo(std::string id, float mass) :
    identificador{id}, massa{mass}, posicaoAtual{0.0} {
    }

    std::string getIdentificador() {return identificador;}
    float getPosicaoAtual() {return posicaoAtual;}
    float getMassa() {return massa;}

    void avancarPosicao(float dist) {
        this->posicaoAtual += dist;
    }

    void setMassa(float new_mass) {
        if (new_mass > 0){
            this->massa = new_mass;
        } else { 
            std::cout<<"Massa invalida, deve ser maior que zero"<<std::endl;
        }
    }
};

class RoboAcelerado : public Robo {

    private:
    float velocidadeInicial;
    float aceleracao;

    public:
    RoboAcelerado(std::string id, float mass, float v0, float accel) :
    Robo(id, mass),
    velocidadeInicial{v0},
    aceleracao{accel}{
    }

    float getVelocidadeInicial() {return velocidadeInicial;}
    float getAceleracao() {return aceleracao;}

    void setVelocidadeInicial(float new_vel) {
        this->velocidadeInicial = new_vel;
    }

    void setAceleracao(float new_accel) {
        this->aceleracao = new_accel;
    }

    void mover(float t) {

        float d = velocidadeInicial * t + 0.5 * aceleracao * t * t;

        avancarPosicao(d);

        float vf = velocidadeInicial + aceleracao * t;
        
        float forca = massa * aceleracao;

        float trabalho = forca * d;

        float ec = 0.5 * massa * vf * vf;

        std::cout<<"Robo: "<<getIdentificador()<<std::endl;
        std::cout<<"Distancia percorrida, "<<d<<std::endl;
        std::cout<<"Velocidade final, "<<vf<<std::endl;
        std::cout<<"Forca aplicada, "<<forca<<std::endl;
        std::cout<<"Trabalho realizado, "<<trabalho<<std::endl;
        std::cout<<"Energia cinetica final, "<<ec<<std::endl;
        std::cout<<"Posicao atual, "<<getPosicaoAtual()<<std::endl;

    }
};

int main() {

    RoboAcelerado robo {"ROBO002", 10.0, 2.0, 1.5};

    std::cout << "Tentando configurar uma massa invalida" << std::endl;

    robo.setMassa(-5.0);

    robo.mover(4.0);

    return 0;
}