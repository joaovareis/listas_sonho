#include <iostream>

const double MATH_PI = 3.1415926535897;

class Atuador {

    private:

    std::string identificador;
    bool estadoAtuador;

    protected:

    float tensaoNominal;

    public:

    Atuador(std::string id, float tensao) :
        identificador{id}, 
        tensaoNominal{tensao},
        estadoAtuador{false} {
        }

    std::string getIdentificador() {return identificador;}
    bool getEstadoAtuador(){return estadoAtuador;}
    float getTensaoNominal(){return tensaoNominal;}

    void ligar(){
        estadoAtuador = true;
        return;
    }

    void desligar(){
        estadoAtuador = false;
        return;
    }

    void setTensaoNominal(float nova_tensao){
        if (nova_tensao > 0) {
            this->tensaoNominal = nova_tensao;
        } else {
            std::cout<<"Valores de tensao < 0 ou = 0 nao sao permitidos"<<std::endl;
        }

        return;
    }

};

class Motor : public Atuador {

    private:

    float torqueNominal;
    float resistenciaEnrolamento;
    float rpmAtual;
    float eficiencia;

    public:

    Motor(std::string id, float tensao, float torque, float resistencia, float efici) :
    Atuador(id, tensao), 
    torqueNominal{torque}, 
    resistenciaEnrolamento{resistencia}, 
    eficiencia{efici}{ 
    }

    float getRpmAtual() {return rpmAtual;}
    float getTorqueNominal() {return torqueNominal;}
    float getResistenciaEnrolamento() {return resistenciaEnrolamento;}
    float getEficiencia() {return eficiencia;}

    void setTorqueNominal(float novo_torque){
        if (novo_torque > 0) {
            this->torqueNominal = novo_torque;
        } else {
            std::cout<<"Valores de torque < 0 ou = 0 nao sao permitidos"<<std::endl;
        }

        return;
    }

    void setResistenciaEnrolamento(float nova_resistencia){
        if (nova_resistencia >= 0) {
            this->resistenciaEnrolamento = nova_resistencia;
        } else {
            std::cout<<"Valores de resistencia < 0 nao sao permitidos"<<std::endl;
        }

        return;
    }

    void setEficiencia(float nova_eficiencia){
        if (nova_eficiencia > 0 and nova_eficiencia <= 1) {
            this->eficiencia = nova_eficiencia;
        } else {
            std::cout<<"Eficiencia invalida, deve estar entre 0 e 1"<<std::endl;
        }

        return;
    }

    void girar(float rotacao_desejada){

        if (not getEstadoAtuador()) {
            std::cout<<"Motor ainda nao esta ligado"<<std::endl;
        } else {

            this->rpmAtual = rotacao_desejada;

            float vel_ang = 2 * MATH_PI * rpmAtual / 60;

            float pot_mecanica = torqueNominal * vel_ang;

            float pot_eletrica = pot_mecanica / eficiencia;

            float corrente = pot_eletrica / tensaoNominal;

            float pot_perdida = corrente * corrente * resistenciaEnrolamento;

            std::cout<<"Motor: "<<getIdentificador()<<", rpm: "<<getRpmAtual()<<std::endl;
            std::cout<<"Potencia mecanica: "<<pot_mecanica<<" Watts"<<std::endl;
            std::cout<<"Potencia eletrica: "<<pot_eletrica<<" Watts"<<std::endl;
            std::cout<<"Corrente: "<<corrente<<" Amperes"<<std::endl;
            std::cout<<"Perdas por efeito Joule: "<<pot_perdida<<" Watts"<<std::endl;

        }
    }
};

int main() {

    Motor motor {"MOT001", 24.0, 6.0, 0.5, 0.85};

    motor.girar(1200);

    std::cout << std::endl << "Tentando configurar uma eficiencia invalida" << std::endl;
    motor.setEficiencia(1.5);

    motor.ligar();

    motor.girar(1200);

    return 0;
}