#include <iostream>
#include <cmath>

class FonteDeEnergia {
    
    private:
    std::string identificador;
    float capacidadePeukert;

    public:

    FonteDeEnergia(std::string id, float cap):
    identificador{id},
    capacidadePeukert{cap}{
    }

    std::string getIdentificador() {return identificador;}
    float getCapacidadePeukert() {return capacidadePeukert;}

    void setCapacidadePeukert(float new_cap) {
        if (new_cap > 0) {
            this->capacidadePeukert = new_cap;
        } else {
            std::cout<<"Capacidade invalida, deve ser maior que zero"<<std::endl;
        }
        return;
    }
};

class BateriaNaoLinear : public FonteDeEnergia {

    private:
    float expoentePeukert;

    protected:
    float capacidadeConsumida;

    public:
    BateriaNaoLinear(std::string id, float cap, float expo) :
    FonteDeEnergia(id, cap),
    expoentePeukert{expo},
    capacidadeConsumida{0.0}{
    }

    float getExpoentePeukert() {return expoentePeukert;}
    float getCapacidadeConsumida() {return capacidadeConsumida;}

    void setExpoentePeukert(float new_expo) {
        if (new_expo > 0) {
            this->expoentePeukert = new_expo;
        } else {
            std::cout<<"Expoente invalido, deve ser maior que zero"<<std::endl;
        }
        return;
    }

    void consumirComPeukert(float corrente, float tempoHoras) {

        float consumo = std::pow(corrente, expoentePeukert) * tempoHoras;

        capacidadeConsumida += consumo;

        float percentual = 100 * capacidadeConsumida / getCapacidadePeukert();

        float tempo_total = getCapacidadePeukert() / std::pow(corrente, expoentePeukert);

        std::cout<<"Bateria "<<getIdentificador()<<std::endl;
        std::cout<<"Capacidade consumida nesta descarga, "<<consumo<<std::endl;
        std::cout<<"Percentual total consumido, "<<percentual<<std::endl;
        std::cout<<"Tempo total de descarga nesta corrente, "<<tempo_total<<" horas"<<std::endl;
    }
};

int main() {
    BateriaNaoLinear bateria {"BAT002", 120.0, 1.2};
    std::cout << "Tentando configurar uma capacidade invalida" << std::endl;
    bateria.setCapacidadePeukert(-10.0);
    bateria.consumirComPeukert(5.0, 2.0);
    return 0;
}