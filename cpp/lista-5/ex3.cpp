#include <iostream>

float termica_isolada[5][5] = {
{20.5, 21.0, 22.2, 21.0, 20.8},
{21.2, 25.0, 30.5, 24.8, 21.5},
{22.0, 31.2, 88.5, 30.1, 22.1},
{21.5, 24.5, 30.2, 25.0, 21.0},
{20.8, 21.2, 22.0, 21.5, 20.5}
};

float termica_quente[5][5] = {
{82.1, 85.0, 81.2, 84.5, 83.0},
{80.5, 92.1, 88.4, 90.2, 81.5},
{84.2, 89.5, 95.0, 88.1, 85.3},
{81.0, 87.2, 89.4, 86.5, 82.2},
{83.5, 84.1, 82.0, 85.3, 84.0}
};

float termica_frio[5][5] = {
{15.2, 16.5, 15.8, 17.1, 16.0},
{14.8, 15.5, 16.2, 15.9, 15.1},
{16.1, 15.9, 17.5, 16.3, 15.8},
{15.5, 16.0, 15.2, 15.7, 16.2},
{16.3, 15.1, 16.4, 15.5, 15.9}
};

int main() {

    int seletor;
    int x;
    int y;
    float max;

    std::cout<<"Digite a matriz a ser utilizada:"<<std::endl;
    std::cout<<"1 -> Isolada"<<std::endl;
    std::cout<<"2 -> Quente"<<std::endl;
    std::cout<<"3 -> Fria"<<std::endl;

    std::cin>>seletor;

    switch(seletor){
        case 1:
            for(int i = 0; i < 5; i++) {

                for(int j = 0; j<5; j++) {

                    if (termica_isolada[i][j] > max) {

                        max = termica_isolada[i][j];

                        x = j; 
                        y = i;
                    }
                }
            }

            break;

        case 2:
            for(int i = 0; i < 5; i++) {

                for(int j = 0; j<5; j++) {

                    if (termica_quente[i][j] > max) {

                        max = termica_quente[i][j];

                        x = j; 
                        y = i;
                    }
                }
            }

            break;
        
        case 3:
            for(int i = 0; i < 5; i++) {

                for(int j = 0; j<5; j++) {

                    if (termica_frio[i][j] > max) {

                        max = termica_frio[i][j];

                        x = j; 
                        y = i;
                    }
                }
            }
            
            break;

        default: 

            std::cout<<"Valor inválido"<<std::endl;
            break;
    }

    std::cout<<"Analise Termica Concluida"<<std::endl;
    std::cout<<"Temperatura Maxima: "<<max<<" *C"<<std::endl;
    std::cout<<"Localizacao: Pixel ["<<y<<"]["<<x<<"]"<<std::endl;

    if(max > 80) {
        std::cout<<"STATUS: [ALERTA DE SUPERAQUECIMENTO]"<<std::endl;
    } else {
        std::cout<<"STATUS: Tudo certo"<<std::endl;
    }

    return 0;
}