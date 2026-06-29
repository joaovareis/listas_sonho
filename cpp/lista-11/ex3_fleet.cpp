#include <iostream>

class Drone {

    public:

    std::string identificador;
    std::string modelo;
    float altitude_atual;
    float autonomia_restante;
    float capacidade_maxima;
    float carga_atual;

    static int numdrones;
    static float autonomia_total;

    Drone (std::string id, std::string model, float initial_autonomy, float max_cargo)
    :   identificador{id},
        modelo{model},
        altitude_atual{0.0},
        autonomia_restante{initial_autonomy},
        capacidade_maxima{max_cargo},
        carga_atual{0.0}{

        autonomia_total += autonomia_restante;
        numdrones += 1;
    }

    ~Drone () {
        autonomia_total -= autonomia_restante;
        numdrones -=1;
    }

    static int getNumDrones() {return numdrones;}

    static void getAutonomiaMedia() {
        if (numdrones > 0) {
            std::cout<<autonomia_total/numdrones<<std::endl;
        } else {
            std::cout<<0<<std::endl;
        }
        
        return;
    }

    void consumir_bateria_para_voo(float distancia) {

        float consumo_por_metro = 0.01 * (1.0 + altitude_atual / 100.0) * (1.0 + carga_atual / 2.0);
        float consumo_total = distancia * consumo_por_metro;

        if (consumo_total > autonomia_restante) {
            std::cout<<identificador<<": Autonomia insuficiente para percorrer "<<distancia<<"m"<<std::endl;

        } else {
            autonomia_restante -= consumo_total;
            autonomia_total -= consumo_total;

            std::cout<<identificador<<": percorreu "<<distancia<<", consumindo "<<consumo_total<<"% de bateria. Autonomia restante: "<<autonomia_restante<<"%"<<std::endl;
        }
        
        return;
    }

    void subir (float metros) {
        
        this->altitude_atual += metros;
        std::cout<<identificador<<": subiu "<<metros<<"m, altitude atual: "<<altitude_atual<<"m"<<std::endl;
        return;
    }

    void descer (float metros) {
        
        this->altitude_atual -= metros;
        std::cout<<identificador<<": desceu "<<metros<<"m, altitude atual: "<<altitude_atual<<"m"<<std::endl;
        return;
    }

    void carregar_carga (float carga_nova) {

        if ((carga_atual + carga_nova) > capacidade_maxima) {
            std::cout<<identificador<<": recusou a carga. Carga proposta ("<<carga_nova+carga_atual<<" kg) ultrapassa limite("<<capacidade_maxima<<" kg)"<<std::endl;

        } else {
            this->carga_atual += carga_nova;
            std::cout<<identificador<<": recebeu a carga de "<<carga_nova<<" kg. Carga total: "<<carga_atual<<" kg"<<std::endl;
        }

        return;
    }

};

int Drone::numdrones = 0;
float Drone::autonomia_total = 0;

int main () {

    Drone::getAutonomiaMedia();

    Drone dr1 {"DR-01", "Harpia", 50, 2};

    dr1.subir(50);

    dr1.carregar_carga(1.5);

    dr1.consumir_bateria_para_voo(500);

    dr1.consumir_bateria_para_voo(50000);

    return 0;
}

