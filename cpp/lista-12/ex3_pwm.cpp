#include <iostream>

class Atuador {

    private:
    std::string identificador;
    
    protected:
    bool estadoAtuador;

    public:

    Atuador(std::string id) :
    identificador{id},
    estadoAtuador{false}{
    }

    std::string getIdentificador() {return identificador;}
    bool getEstadoAtuador() {return estadoAtuador;}

    void ligar(){
        estadoAtuador = true;
    }

    void desligar(){
        estadoAtuador = false;
    }
};

class ServoMotor : public Atuador {
    
    private:
    float anguloAtual;
    float pulsoMinimo;
    float pulsoMaximo;

    public:

    ServoMotor(std::string id, float pulso_min, float pulso_max) :
    Atuador(id),
    pulsoMinimo{pulso_min},
    pulsoMaximo{pulso_max},
    anguloAtual{0.0}{
    }

    float getAnguloAtual() {return anguloAtual;}
    float getPulsoMinimo() {return pulsoMinimo;}
    float getPulsoMaximo() {return pulsoMaximo;}

    void setPulsoMinimo(float new_pulso_min) {
        if (new_pulso_min >= 0) {
            this->pulsoMinimo = new_pulso_min;
        } else {
            std::cout<<"Pulso minimo invalido, nao pode ser negativo"<<std::endl;
        }

        return;
    }

    void setPulsoMaximo(float new_pulso_max) {
        if (new_pulso_max > pulsoMinimo) {
            this->pulsoMaximo = new_pulso_max;
        } else {
            std::cout<<"Pulso maximo invalido, nao pode ser menor ou igual ao pulso minimo"<<std::endl;
        }
        
        return;
    }

    void moverPara(float angulo) {
        if (not getEstadoAtuador()) {
            std::cout<<"Servo ainda nao esta ligado"<<std::endl;

        } else if (angulo < 0 or angulo > 180) {
            std::cout<<"Angulo invalido, deve estar entre 0 a 180 graus"<<std::endl;

        } else {
            float pulso = pulsoMinimo + (angulo / 180) * (pulsoMaximo - pulsoMinimo);

            this->anguloAtual = angulo;
            std::cout<<"Servo "<<getIdentificador()<<", angulo "<<anguloAtual<<" graus, pulso "<<pulso<<" microssegundos"<<std::endl;
        }

        return;
    }
};

int main() {
    ServoMotor servo {"SERVO001", 500.0, 2500.0};
    std::cout << "Tentando mover antes de ligar" << std::endl;
    servo.moverPara(90.0);
    std::cout << "Tentando configurar um pulso minimo invalido" << std::endl;
    servo.setPulsoMinimo(-100.0);
    servo.ligar();
    servo.moverPara(0.0);
    servo.moverPara(90.0);
    servo.moverPara(180.0);
    std::cout << "Tentando mover para um angulo invalido" << std::endl;
    servo.moverPara(200.0);
    return 0;
}