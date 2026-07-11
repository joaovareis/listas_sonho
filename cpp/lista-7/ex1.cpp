#include <iostream>

void filtrar_leituras(double &leitura);

int main() {

    double leituras[] {1.0, 3.0, 2.0, 8.0, 1.5, 2.0, 3.5, 1.0};

    for(int i = 0; i < 8; i++) {

        std::cout<<"original="<<leituras[i]<<"        ";

        filtrar_leituras(leituras[i]);
    }

    return 0;
}

void filtrar_leituras(double &leitura) {

    static float lista[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    static int roleta = 0;

    lista[roleta] = leitura;
    roleta += 1;

    if (roleta > 4) {
        roleta = 0;
    }

    float sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += lista[i];
    }

    std::cout<<"Filtrada="<<sum/5<<std::endl;

}