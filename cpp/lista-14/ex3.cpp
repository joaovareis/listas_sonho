#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <array>

struct imu {
    std::vector<std::array<double, 7>> raw;
    std::vector<std::array<double, 3>> filtered;

    double acc_max;
    double acc_min;
    double acc_media;

    double vel_min;
    double vel_max;
    double vel_media;
};

struct point_cloud {
    std::vector<std::array<double, 2>> raw;
    std::vector<double> filtered;

    double max;
    double min;
    double media;

};

struct lidar {
    std::vector<double> data;

    double max;
    double min;
    double media;

};

struct sensores {
    imu imu;
    lidar lidar;
    point_cloud point_cloud;

};

class InvalidDataException : public std::exception {
public:
    const char *what() const noexcept override {
        return "O valor de dado lido é inválido";
    }
};

class Processamento {
    public:

    void process_lidar(sensores& entrada) {

        if (entrada.lidar.data.empty()) {

            std::cout<<"O arquivo não foi encontrado"<<std::endl;
            return;
        }

        int tamanho = entrada.lidar.data.size();
        double sum = 0; 
        double min = entrada.lidar.data[0];
        double max = entrada.lidar.data[0];

        for (int i = 0; i < tamanho; i++) {

            sum += entrada.lidar.data[i];

            if (entrada.lidar.data[i] > max ){
                max = entrada.lidar.data[i];

            } else if (entrada.lidar.data[i] < min) {

                min = entrada.lidar.data[i];
            }
        }

        entrada.lidar.max = max;
        entrada.lidar.min = min;
        entrada.lidar.media = sum / tamanho;
    }

    void process_imu(sensores& entrada) {

        if (entrada.imu.raw.empty()) {

            std::cout<<"O arquivo não foi encontrado"<<std::endl;
            return;
        }
        
        int tamanho = entrada.imu.raw.size();

        double sum_ma = 0; 
        double sum_mw = 0;

        double ma = std::pow(std::pow(entrada.imu.raw[0][1], 2) + std::pow(entrada.imu.raw[0][2], 2) + std::pow(entrada.imu.raw[0][3], 2), 0.5);
        double acc_min = ma;
        double acc_max = ma;

        double mw = std::pow(std::pow(entrada.imu.raw[0][4], 2) + std::pow(entrada.imu.raw[0][5], 2) + std::pow(entrada.imu.raw[0][6], 2), 0.5);
        double vel_min = mw;
        double vel_max = mw;

        for (int i = 0; i < tamanho; i++) {

            ma = std::pow(std::pow(entrada.imu.raw[i][1], 2) + std::pow(entrada.imu.raw[i][2], 2) + std::pow(entrada.imu.raw[i][3], 2), 0.5);
            mw = std::pow(std::pow(entrada.imu.raw[i][4], 2) + std::pow(entrada.imu.raw[i][5], 2) + std::pow(entrada.imu.raw[i][6], 2), 0.5);

            if (ma > acc_max){
                acc_max = ma;
            }

            if (ma < acc_min) {
                acc_min = ma;
            }

            if (mw > vel_max) {
                vel_max = mw;
            }

            if (mw < vel_min) {
                vel_min = mw;
            }

            double time = entrada.imu.raw[i][0];

            entrada.imu.filtered.push_back({time, ma, mw});

            sum_ma += ma;
            sum_mw += mw;

        }

        entrada.imu.acc_max = acc_max;
        entrada.imu.acc_min = acc_min;
        entrada.imu.acc_media = sum_ma / tamanho;

        entrada.imu.vel_max = vel_max;
        entrada.imu.vel_min = vel_min;
        entrada.imu.vel_media = sum_mw / tamanho;
    }

    void process_pointcloud(sensores& entrada) {

        if (entrada.point_cloud.raw.empty()) {

            std::cout<<"O arquivo não foi encontrado"<<std::endl;
            return;
        }

        int tamanho = entrada.point_cloud.raw.size();

        double sum = 0;
        double min = std::pow(std::pow(entrada.point_cloud.raw[0][0], 2) + std::pow(entrada.point_cloud.raw[0][1], 2), 0.5);
        double max = min;

        for (int i = 0; i < tamanho; i++) {

            double d = std::pow(std::pow(entrada.point_cloud.raw[i][0], 2) + std::pow(entrada.point_cloud.raw[i][1], 2), 0.5);

            if (d > max) {
                max = d;

            } else if (d < min) {
                min = d;
            }

            sum += d;
            entrada.point_cloud.filtered.push_back(d);
        }

        entrada.point_cloud.max = max;
        entrada.point_cloud.min = min;
        entrada.point_cloud.media = sum / tamanho;
    }

    void carregar_imu (std::ifstream& entrada, sensores& saida) {

        std::string valor;
    
        double time;
        double ax;
        double ay;
        double az;

        double vx;
        double vy;
        double vz;

        while(std::getline(entrada, valor, ',')) {

            try{
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

                if (ma < 30 and mw < 3.5) {
                    saida.imu.raw.push_back({time, ax, ay, az, vx, vy, vz});
                } else {
                    throw InvalidDataException();
                }

            } catch (const InvalidDataException& e) {

            }
        }
    }

    void carregar_pointcloud (std::ifstream& entrada, sensores& saida) {

        std::string x_string;
        std::string y_string;
        
        double x;
        double y;

        while(std::getline(entrada, x_string, ',')) {

            try{
                std::getline(entrada, y_string);

                if (x_string == "inf" or x_string == "-inf" or y_string == "inf" or y_string == "-inf") {
                    throw InvalidDataException();
                }

                x = std::stod(x_string);
                y = std::stod(y_string);

                saida.point_cloud.raw.push_back({x, y});

            } catch (const InvalidDataException& e) {

            }
        }
    }

    void carregar_lidar (std::ifstream& entrada, sensores& saida) {

        std::string leitura;

        double valor;

        while(std::getline(entrada, leitura)) {

            try{

                if (leitura == "inf") {
                    throw InvalidDataException();
                }

                valor = std::stod(leitura);

                saida.lidar.data.push_back(valor);

            } catch (const InvalidDataException& e) {

            }
        }
    }
};

int main () {

    std::ifstream imu_read_csv;
    std::ifstream ptcd_read_csv;
    std::ifstream lidar_read_csv;

    std::string title;

    std::ofstream relatorio;

    imu_read_csv.open("cpp/lista-14/data/input/imu_data.csv", std::ios::in);
    std::getline(imu_read_csv, title);

    ptcd_read_csv.open("cpp/lista-14/data/input/point_cloud.csv", std::ios::in);
    std::getline(ptcd_read_csv, title);

    lidar_read_csv.open("cpp/lista-14/data/input/lidar_data.csv", std::ios::in);
    std::getline(lidar_read_csv, title);

    Processamento node;
    sensores dados;

    node.carregar_imu(imu_read_csv, dados);
    imu_read_csv.close();
    node.process_imu(dados);

    node.carregar_lidar(lidar_read_csv, dados);
    lidar_read_csv.close();
    node.process_lidar(dados);

    node.carregar_pointcloud(ptcd_read_csv, dados);
    ptcd_read_csv.close();
    node.process_pointcloud(dados);

    relatorio.open("cpp/lista-14/data/output/relatorio_robo.csv", std::ios::out);

    std::cout<<"Lidar, minima "<<dados.lidar.min<<", maxima "<<dados.lidar.max<<", media "<<dados.lidar.media<<std::endl;
    std::cout<<"Nuvem de Pontos, minima "<<dados.point_cloud.min<<", maxima "<<dados.point_cloud.max<<", media "<<dados.point_cloud.media<<std::endl;
    std::cout<<"IMU aceleracao, minima "<<dados.imu.acc_min<<", maxima "<<dados.imu.acc_max<<", media "<<dados.imu.acc_media<<std::endl;
    std::cout<<"IMU velocidade angular, minima "<<dados.imu.vel_min<<", maxima "<<dados.imu.vel_max<<", media "<<dados.imu.vel_media<<std::endl;

    int n_leituras_imu = dados.imu.filtered.size();

    for (int i = 0; i < n_leituras_imu; i++) {
        double time = dados.imu.filtered[i][0];
        double ma   = dados.imu.filtered[i][1];

        relatorio<<"IMU,"<<time<<",acc_magnitude,"<< ma <<std::endl;
    }

    for (int i = 0; i < n_leituras_imu; i++) {
        double time = dados.imu.filtered[i][0];
        double mw   = dados.imu.filtered[i][2];

        relatorio<<"IMU,"<<time<<",vel_angular_magnitude,"<<mw<<std::endl;
    }

    int n_leituras_lidar = dados.lidar.data.size();

    for (int i = 0; i < n_leituras_lidar; i++) {
        relatorio<<"LIDAR,"<<i<<",distancia,"<<dados.lidar.data[i]<<std::endl;
    }

    int n_leituras_ptcd = dados.point_cloud.filtered.size();

    for (int i = 0; i < n_leituras_ptcd; i++) {
        relatorio<<"POINT_CLOUD,"<<i<<",distancia_2d,"<<dados.point_cloud.filtered[i]<<std::endl;
    }

    relatorio.close();

}

