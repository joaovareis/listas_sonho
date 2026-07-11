#include <iostream>
#include <cmath>
#include <iomanip>

#define l 0.25
#define w 0.18

double raio_curvatura(double phi);
double vel_angular(double v, double phi);
double angulo_interno(double phi);
double angulo_externo(double phi);
double vel_roda_interna(double theta, double r);
double vel_roda_externa(double theta, double r);
void exibir_estado(double v, double phi);

int main() {

    std::cout<<"------- Caso 1 ---------"<<std::endl;
    exibir_estado(2.0, 0.0);
    std::cout<<std::endl;
    std::cout<<"------- Caso 2 ---------"<<std::endl;
    exibir_estado(2.0, 0.3);
    std::cout<<std::endl;
    std::cout<<"------- Caso 3 ---------"<<std::endl;
    exibir_estado(2.0, 0.5);
    std::cout<<std::endl;
    std::cout<<"------- Caso 4 ---------"<<std::endl;
    exibir_estado(2.0, 0.785);
    std::cout<<std::endl;
    std::cout<<"------- Caso 5 ---------"<<std::endl;
    exibir_estado(1.0, 0.3);

}

double raio_curvatura(double phi) {

    if(phi != 0){ 
        return l/tan(phi);

    } else {
        return INFINITY;
    }
}

double vel_angular(double v, double phi) {

    return v*tan(phi)/l;

}

double angulo_interno(double phi) {

    double ang = atan((2*l*sin(phi))/((2*l*cos(phi)) - (w*sin(phi))));

    return ang;
}

double angulo_externo(double phi) {

    double ang = atan((2*l*sin(phi))/((2*l*cos(phi)) + (w*sin(phi))));

    return ang;
}

double vel_roda_interna(double theta, double r, double v) {

    double vel = theta *(r - w/2);

    if(r == INFINITY){
        return v;
    } else {
        return vel;
    }
}

double vel_roda_externa(double theta, double r, double v) {

    double vel = theta *(r + w/2);

    if(r == INFINITY){
        return v;
    } else {
        return vel;
    }
}

void exibir_estado(double v, double phi) {

    std::cout<<std::left<<std::setw(18)<<"phi_base"<<" = "<<phi<<" rad"<<std::endl;

    double r = raio_curvatura(phi);
    std::cout<<std::left<<std::setw(18)<<"r"<<" = "<<r<<" m"<<std::endl;

    double theta = vel_angular(v, phi);
    std::cout<<std::left<<std::setw(18)<<"theta"<<" = "<<theta<<" rad/s"<<std::endl;

    double phi_i = angulo_interno(phi);
    std::cout<<std::left<<std::setw(18)<<"phi_i"<<" = "<<phi_i<<" rad"<<std::endl;

    double phi_o = angulo_externo(phi);
    std::cout<<std::left<<std::setw(18)<<"phi_o"<<" = "<<phi_o<<" rad"<<std::endl;

    double v_i = vel_roda_interna(theta, r, v);
    std::cout<<std::left<<std::setw(18)<<"v_i"<<" = "<<v_i<<" m/s"<<std::endl;

    double v_o = vel_roda_externa(theta, r, v);
    std::cout<<std::left<<std::setw(18)<<"v_o"<<" = "<<v_o<<" m/s"<<std::endl;
    
}