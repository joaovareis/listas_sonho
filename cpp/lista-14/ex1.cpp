#include <iostream>
#include <fstream>
#include <string>

double converter_linha (std::string& linha){

    if (linha != "inf") {
        return std::stod(linha);

    } else {
        throw 0;
    } 
}

void calcular_media (std::ifstream& arquivo, int& validas, int& invalidas, double& media, double& min, double& max) {

    std::string linha;
    double somatorio;
    double leitura;

    while (std::getline(arquivo, linha)) {

        try {
            leitura = converter_linha(linha);
            validas++;
            somatorio += leitura;

            if (leitura < min) {
                min = leitura;

            } else if (leitura > max) {
                max = leitura;
            }
        }
        catch(int& e){
            invalidas++;
        }
    }

    media = somatorio / validas;
}

int main() {
    
    std::ifstream lidar_csv;
    std::string linha;

    double max = 0;
    double min = 1000;
    double media;
    int validas = 0;
    int invalidas = 0;

    lidar_csv.open("cpp/lista-14/data/input/lidar_data.csv", std::ios::in);
    std::getline(lidar_csv, linha);

    calcular_media(lidar_csv, validas, invalidas, media, min, max);

    lidar_csv.close();

    std::cout<<"Minima, "<<min<<std::endl;
    std::cout<<"Maxima, "<<max<<std::endl;
    std::cout<<"Media, "<<media<<std::endl;
    std::cout<<"Total de leituras, "<<(invalidas + validas)<<std::endl;
    std::cout<<"Leituras invalidas descartadas, "<<invalidas<<std::endl;
    std::cout<<"Leituras validas, "<<validas<<std::endl;

    return 0;
}