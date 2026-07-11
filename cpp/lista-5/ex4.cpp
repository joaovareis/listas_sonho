#include <iostream>
#include <cmath>
#include <iomanip>

int mapa_esparso_A[7][7] = {
{0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0}
};

int mapa_esparso_B[8][8] = {
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 0, 0, 0, 0, 0},
{0, 1, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 1, 1},
{0, 0, 0, 0, 0, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 0}
};

int mapa_esparso_C[10][10] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
{0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 1, 0, 0, 0, 1, 0, 0, 0, 0}
};

int main() {

    int x;
    int y;
    float dist = 100;
    int coluna;
    int linha;

    std::cout<<"Digite as coordenadas"<<std::endl;
    std::cout<<"coluna: ";
    std::cin>>x;

    std::cout<<"linha: ";
    std::cin>>y;

    std::cout<<"Verificando coordenada ["<<x<<", "<<y<<"]"<<std::endl;

    if (mapa_esparso_A[y][x] == 0) {

        std::cout<<"Status: Caminho Livre."<<std::endl;
        std::cout<<"Buscando obstaculo mais proximo..."<<std::endl;

        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                
                if(mapa_esparso_A[i][j] == 1) {

                    if (sqrt(pow((x-j), 2) + pow((y-i), 2)) < dist) {
                        dist = sqrt(pow((x-j), 2) + pow((y-i), 2));
                        coluna = j;
                        linha = i;
                    }
                }
            }
        }

        std::cout<<"Obstaculo mais proximo encontrado em: ["<<linha<<", "<<coluna<<"]"<<std::endl;
        std::cout<<"Distancia Euclidiana: "<<std::fixed<<std::setprecision(2)<<dist<<std::endl;

    } else {
        std::cout<<"Destino Invalido: Obstaculo Detectado."<<std::endl;
    }


}