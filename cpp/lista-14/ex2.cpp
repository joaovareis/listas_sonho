#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

class Absurd_Ma_Exception : public std::exception {
public:
    const char *what() const noexcept override {
        return "O valor de ma recebido é absurdo (maior que 30 m/s)";
    }
};

class Absurd_Mw_Exception : public std::exception {
public:
    const char *what() const noexcept override {
        return "O valor de mw recebido é absurdo (maior que 3.5 rad/s)";
    }
};

double media_movel_ma (double& leitura) {

    static double janela[30] = {0.0};
    static int roleta = 0;
    static int recebidos = 0;

    *(janela + roleta) = leitura;
    roleta++;

    if (roleta > 29) {
        roleta = 0;
    }

    if (recebidos < 30) {
        recebidos++;
    }

    double sum = 0;

    for(int i = 0; i < recebidos; i++) {
        sum += *(janela + i);
    }

    return sum/recebidos;
}

double media_movel_mw (double& leitura) {

    static double janela[30] = {0.0};
    static int roleta = 0;
    static int recebidos = 0;

    *(janela + roleta) = leitura;
    roleta++;

    if (roleta > 29) {
        roleta = 0;
    }

    if (recebidos < 30) {
        recebidos++;
    }

    double sum = 0;

    for(int i = 0; i < recebidos; i++) {
        sum += *(janela + i);
    }

    return sum/recebidos;
}

void calcular_mag_e_salvar(std::ifstream& entrada, std::ofstream& saida) {

    std::string valor;
    
    double time;
    double ax;
    double ay;
    double az;

    double vx;
    double vy;
    double vz;

    while(std::getline(entrada, valor, ',')) {

        time = std::stod(valor);

        std::getline(entrada, valor, ',');
        ax = std::stod(valor);

        std::getline(entrada, valor, ',');
        ay = std::stod(valor);

        std::getline(entrada, valor, ',');
        az = std::stod(valor);

        std::getline(entrada, valor, ',');
        vx = std::stod(valor);

        std::getline(entrada, valor, ',');
        vy = std::stod(valor);

        std::getline(entrada, valor);
        vz = std::stod(valor);

        double ma = std::pow(std::pow(ax, 2) + std::pow(ay, 2) + std::pow(az, 2), 0.5);
        double mw = std::pow(std::pow(vx, 2) + std::pow(vy, 2) + std::pow(vz, 2), 0.5);

        saida <<time<<","<<ma<<","<<mw<<std::endl;
    }
}

void calcular_media_movel_e_salvar(std::ifstream& entrada, std::ofstream& saida, int& total, int& invalidas) {

    std::string valor;
    
    double time;
    double ma;
    double mw;

    double ma_media;
    double mw_media;

    while(std::getline(entrada, valor, ',')) {

        try{

            time = std::stod(valor);

            std::getline(entrada, valor, ',');
            ma = std::stod(valor);

            std::getline(entrada, valor);
            mw = std::stod(valor);

            if (ma >= 30) {
                throw Absurd_Ma_Exception();
            }

            if (mw >= 3.5) {
                throw Absurd_Mw_Exception();
            }

            ma_media = media_movel_ma(ma);
            mw_media = media_movel_mw(mw);

            saida <<time<<","<<ma_media<<","<<mw_media<<std::endl;
        } 

        catch (const std::exception& e) {
            invalidas++;
        }

        total++;
    }
}

int main() {

    std::ifstream imu_read_csv;
    std::ofstream imu_write_csv;
    std::string linha;

    int leituras_totais = 0;
    int leituras_invalidas = 0;

    imu_read_csv.open("cpp/lista-14/data/input/imu_data.csv", std::ios::in);
    std::getline(imu_read_csv, linha);

    imu_write_csv.open("cpp/lista-14/data/output/imu_data_original.csv", std::ios::out);
    imu_write_csv<<"#timestamp, acel_linear, vel_angular"<<std::endl;

    calcular_mag_e_salvar(imu_read_csv, imu_write_csv);
    imu_write_csv.close();
    imu_read_csv.close();

    imu_read_csv.open("cpp/lista-14/data/output/imu_data_original.csv", std::ios::in);
    std::getline(imu_read_csv, linha);

    imu_write_csv.open("cpp/lista-14/data/output/imu_data_filtrado.csv", std::ios::out);
    imu_write_csv<<"#timestamp, acel_linear, vel_angular"<<std::endl;

    calcular_media_movel_e_salvar(imu_read_csv, imu_write_csv, leituras_totais, leituras_invalidas);

    imu_write_csv.close();
    imu_read_csv.close();

    std::cout<<"Total de leituras, "<<leituras_totais<<std::endl;
    std::cout<<"Leituras descartadas por ruido excessivo, "<<leituras_invalidas<<std::endl;
    std::cout<<"Leituras filtradas salvas, "<<leituras_totais - leituras_invalidas<<std::endl;

    std::ofstream relatorio;
    relatorio.open("cpp/lista-14/data/output/imu_data_resumo.txt");

    relatorio<<"Total de leituras, "<<leituras_totais<<std::endl;
    relatorio<<"Leituras descartadas por ruido excessivo, "<<leituras_invalidas<<std::endl;
    relatorio<<"Leituras filtradas salvas, "<<leituras_totais - leituras_invalidas<<std::endl;

    relatorio.close();
}