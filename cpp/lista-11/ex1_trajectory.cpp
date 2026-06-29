#include <iostream>
#include <cmath>

float MATH_PI  = 4*atan(1);

class Simulation {

    public:

    float v0;
    double theta;
    float g;

    double tempo_total;
    double altura_maxima;
    double alcance;

    Simulation(float vel_inicial, float ang_lanca)
        :   v0{vel_inicial},
            theta{ang_lanca*MATH_PI/180},
            g{9.8} {

        tempo_total = 2 * v0 * sin(theta) / g;
        altura_maxima = (std::pow(v0,2) * std::pow(sin(theta), 2)) / (2 * g);
        alcance = (std::pow(v0, 2) * sin(2 * theta)) / g;
        
    }

    float getV0() {return v0;}
    float getTheta() {return theta;}
    float getGravidade() {return g;}

    double calcular_tempo_voo() {

        return tempo_total;
    }

    double calcular_altura_maxima() {

        return altura_maxima;
    }

    double calcular_alcance () {

        return alcance;
    }

    std::pair<double, double> posicao_em (float t) {

        if (t < 0) {
            std::cout<<"[ERRO]: O valor de t recebido, "<<t<<", e inválido (menor que zero)"<<std::endl;
            return {0,0};

        } else if (t > tempo_total) {
            std::cout<<"[ERRO]: Instante de tempo invalido: "<<t<<"s, esta fora do intervalo de voo [0, "<<tempo_total<<"]"<<std::endl;
            return {0,0};

        } else {
            double pos_x = v0 * cos(theta) * t;
            double pos_y = v0 * sin(theta) * t - (g * std::pow(t, 2)) / 2;

            return {pos_x, pos_y};
        }
    }
};

int main () {

    Simulation simulacao{15, 45};

    double tempo_voo = simulacao.calcular_tempo_voo();
    std::cout<<"Tempo de voo: "<<tempo_voo<<std::endl;
    
    double altura_maxima = simulacao.calcular_altura_maxima();
    std::cout<<"Altura maxima: "<<altura_maxima<<std::endl;

    double alcance = simulacao.calcular_alcance();
    std::cout<<"ALcance: "<<alcance<<std::endl;

    auto pos = simulacao.posicao_em(tempo_voo / 2);
    std::cout<<"x = "<<pos.first<<" m, y = "<<pos.second<<" m"<<std::endl;

    pos = simulacao.posicao_em(10);

}