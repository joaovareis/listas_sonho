#ifndef ODOMETRIA
#define ODOMETRIA 

namespace Odometria{
    double distancia_percorrida(double dt, double v);
    void atualizar_posicao(double &x, double &y, double v, double dt);
    void atualizar_posicao_curva(double &x, double &y, double &theta, double dt, double v, double omega);
    void exibir_postura(double &x, double &y, double &theta, double v, double dt, double omega, int passos);
}

#endif
