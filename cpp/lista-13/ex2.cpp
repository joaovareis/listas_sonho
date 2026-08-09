#include <iostream>
#include <cmath>

constexpr double c = 299792458.0;

class Sensor {

    private:

    std::string identificador;
    double      leituraBruta;
    double      fatorCalibracao;
    
    public:

    Sensor(std::string nome, double bruto, double calibragem) :
    identificador{nome},
    leituraBruta{bruto},
    fatorCalibracao{calibragem} {}

    const std::string&  getIdentificador    () const {return identificador;}
    const double&       getLeituraBruta     () const {return leituraBruta;}
    const double&       getFatorCalibracao  () const {return fatorCalibracao;}

    Sensor& setLeitura (double nova_leitura) {
        this->leituraBruta = nova_leitura;
        return *this;
    }

    virtual double calcularDistancia () const {
        double distancia = 0.0;
        return distancia;
    }

    Sensor& calibrar (const double& novo_valor) {
        
        if (novo_valor > 0) {
            this->fatorCalibracao = novo_valor;

        } else {
            std::cout<<"Fator de calibracao invalido para "<<identificador<<std::endl;
        }

        return *this;
    }
};

class SensorUltrassonico : public Sensor {

    private:

    double temperatura;

    public:

    SensorUltrassonico(std::string nome, double bruto, double calibragem, double temp) :
    Sensor(nome, bruto, calibragem),
    temperatura{temp} {}

    double calcularDistancia () const override {

        double velocidade = 343.0 + (0.6 * (temperatura - 20));

        double distancia = (getLeituraBruta() * velocidade * getFatorCalibracao()) / (2 * 1000000);

        return distancia;

    }
};

class SensorInfravermelho : public Sensor {

    private:

    double coefA;
    double coefB;

    public:

    SensorInfravermelho(std::string nome, double bruto, double calibragem, double a, double b) :
    Sensor(nome, bruto, calibragem),
    coefA{a},
    coefB{b} {}

    double calcularDistancia () const override {

        double distancia = (coefA * getFatorCalibracao()) / (getLeituraBruta() - coefB);

        return distancia;
    }
};

class SensorLidar : public Sensor {

    private:

    double frequenciaModulacao;

    public:

    SensorLidar(std::string nome, double bruto, double calibragem, double freq) :
    Sensor(nome, bruto, calibragem),
    frequenciaModulacao{freq} {}

    double calcularDistancia () const override {

        double comp_onda = c / frequenciaModulacao;

        double distancia = (getLeituraBruta() * comp_onda * getFatorCalibracao()) / (4 * M_PI);

        return distancia;
    }
};

int main() {
    Sensor* sensores[3];
    sensores[0] = new SensorUltrassonico("US001", 4500.0, 1.0, 35.0);
    sensores[1] = new SensorInfravermelho("IR001", 2.4, 1.0, 0.52, 1.1);
    sensores[2] = new SensorLidar("LSR001", 1.2, 1.0, 10000000.0);

    std::cout<<"=== Leituras ==="<<std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout<<"["<<sensores[i]->getIdentificador()<<"] Distancia: "<<sensores[i]->calcularDistancia()<<" m"<<std::endl;
    }

    double nova_calib = 1.05;

    std::cout<<std::endl;

    std::cout<<"=== Apos calibracao (Fator "<<nova_calib<<") ==="<<std::endl;

    for (int i = 0; i < 3; i++) {
        sensores[i]->calibrar(nova_calib);
        std::cout<<"["<<sensores[i]->getIdentificador()<<"] Distancia: "<<sensores[i]->calcularDistancia()<<" m"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"=== Tentando uma calibracao invalida ==="<<std::endl;

    sensores[2]->calibrar(-1.0);

    return 0;

}