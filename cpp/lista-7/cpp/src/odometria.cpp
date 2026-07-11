#include <iostream>
#include "../lib/odometria.hpp"
#include <cmath>
#include <iomanip>


double Odometria::distancia_percorrida(double dt, double v) {

    double dist = v*dt;

    return dist;

}
void Odometria::atualizar_posicao(double &x, double &y, double v, double dt){

    double dist = Odometria::distancia_percorrida(dt, v);
    x += dist;
}
void Odometria::atualizar_posicao_curva(double &x, double &y, double &theta, double dt, double v, double omega){

    double dist = Odometria::distancia_percorrida(dt, v);

    x += dist*cos(theta + omega*dt/2);
    y += dist*sin(theta + omega*dt/2);

    theta += omega*dt;
}

void Odometria::exibir_postura(double &x, double &y, double &theta, double v, double dt, double omega, int passos){

    if (omega == 0) {
        for(int i = 0; i<passos; i++) {
            std::cout<<std::fixed<<std::setprecision(4);
            Odometria::atualizar_posicao(x, y, v, dt);
            std::cout<<std::setw(10)<<"passo="<<i+1<<std::setw(10)<<" x="<<x<<std::setw(10)<<" y="<<y<<std::setw(10)<<" theta="<<std::setprecision(2)<<theta<<" rad"<<std::endl;
        }
    } else {
        for(int i = 0; i<passos; i++) {
            std::cout<<std::fixed<<std::setprecision(4);
            Odometria::atualizar_posicao_curva(x, y, theta, dt, v, omega);
            std::cout<<std::setw(10)<<"passo="<<i+1<<std::setw(10)<<" x="<<x<<std::setw(10)<<" y="<<y<<std::setw(10)<<" theta="<<std::setprecision(2)<<theta<<" rad"<<std::endl;
        }
    }
}