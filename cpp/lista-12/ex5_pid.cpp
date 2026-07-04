#include <iostream>

class Robo {

    private:
    std::string identificador;
    float velocidadeAtual;

    public:

    Robo(std::string id) :
    identificador{id},
    velocidadeAtual{0.0} {
    }

    std::string getIdentificador() {return identificador;}
    float getVelocidadeAtual() {return velocidadeAtual;}

    void setVelocidadeAtual(float new_vel) {
        this->velocidadeAtual = new_vel;
    }
};

class RoboComControladorPID : public Robo{

    private:
    float ganhoProporcional;
    float ganhoIntegral;
    float ganhoDerivativo;
    float erroAnterior;

    protected:
    float somaIntegral;

    public:

    RoboComControladorPID(std::string id, float gp, float gi, float gd) :
    Robo(id),
    ganhoProporcional{gp},
    ganhoIntegral{gi},
    ganhoDerivativo{gd},
    erroAnterior{0.0},
    somaIntegral{0.0} {
    }

    float getGanhoProporcional() {return ganhoProporcional;}
    float getGanhoIntegral() {return ganhoIntegral;}
    float getGanhoDerivativo() {return ganhoDerivativo;}
    float getSomaIntegral() {return somaIntegral;}

    void setGanhoProporcional(float new_gain) {
        if (new_gain > 0) {
            this->ganhoProporcional = new_gain;
        } else {
            std::cout<<"Ganho proporcional invalido, deve ser maior que zero"<<std::endl;
        }
    }

    void setGanhoIntegral(float new_gain) {
        if (new_gain > 0) {
            this->ganhoIntegral = new_gain;
        } else {
            std::cout<<"Ganho integral invalido, deve ser maior que zero"<<std::endl;
        }
    }

    void setGanhoDerivativo(float new_gain) {
        if (new_gain > 0) {
            this->ganhoDerivativo = new_gain;
        } else {
            std::cout<<"Ganho derivativo invalido, deve ser maior que zero"<<std::endl;
        }
    }

    void atualizarVelocidade(float velocidadeDesejada, float deltaT) {

        float erro = velocidadeDesejada - getVelocidadeAtual();

        somaIntegral += erro * deltaT;

        float derivada = (erro - erroAnterior) / deltaT;

        float saida = ganhoProporcional * erro + ganhoDerivativo * derivada + ganhoIntegral * somaIntegral;

        setVelocidadeAtual(getVelocidadeAtual() + saida*deltaT);

        this->erroAnterior = erro;

        std::cout<<"[PID] Robo "<<getIdentificador()<<", erro "<<erro<<", saida "<<saida<<", nova velocidade "<<getVelocidadeAtual()<<std::endl;
    }
};

int main() {
    RoboComControladorPID robo {"ROBO005", 0.4, 0.1, 0.05};
    std::cout << "Tentando configurar um ganho proporcional invalido" << std::endl;
    robo.setGanhoProporcional(-0.1);
    std::cout << "Tentando configurar um ganho integral invalido" << std::endl;
    robo.setGanhoIntegral(-0.5);
    std::cout << "Tentando configurar um ganho derivativo invalido" << std::endl;
    robo.setGanhoDerivativo(-0.2);
    robo.atualizarVelocidade(12.0, 1.0);
    robo.atualizarVelocidade(12.0, 1.0);
    robo.atualizarVelocidade(12.0, 1.0);
    robo.atualizarVelocidade(12.0, 1.0);
    return 0;
}