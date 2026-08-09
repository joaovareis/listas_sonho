#include <iostream>
#include <memory>
#include <utility>

class Bateria {

    private:

    std::string identificador;
    double cap_max;
    double potencia_aloc = 0;

    public:

    Bateria(std::string nome, double cap) :
    identificador{nome},
    cap_max{cap} {}

    ~Bateria() {
        std::cout<<"[Bateria "<<identificador<<" desligada]"<<std::endl;
    }

    const std::string&  getIdentificador () const {return identificador;}
    const double&       getCapacidadeMaxima () const {return cap_max;}
    const double&       getPotenciaAlocada() const {return potencia_aloc;}

    bool alocarPotencia (const double& pot_solicitada) {

        if (this->potencia_aloc + pot_solicitada > cap_max) {
            std::cout<<"Bateria "<<identificador<<" recusou alocar "<<pot_solicitada<<" W, excederia a capacidade maxima de "<<cap_max<<" W"<<std::endl;

            return 0;

        } else {
            this->potencia_aloc += pot_solicitada;
            std::cout<<"Bateria "<<identificador<<" alocou "<<pot_solicitada<<" W. Total alocado: "<<potencia_aloc<<" W"<<std::endl;

            return 1;
        }
    }
};

class Motor {
    private:

    std::string identificador;
    double pot_nominal;
    const double coef_aquecimento = 0.3;

    std::unique_ptr<double> temp_acumulada;
    std::shared_ptr<Bateria> bateria;

    public:

    Motor(std::string name, double pot, const std::shared_ptr<Bateria>& bat) :
    identificador{name},
    pot_nominal{pot},
    temp_acumulada{std::make_unique<double>(25.0)},
    bateria{bat} {
        
        std::cout<<"[Motor "<<identificador<<" conectado], referencias da bateria: "<<bateria.use_count()<<std::endl;
    }

    ~Motor() {
        std::cout<<"[Motor "<<identificador<<" desconectado]"<<std::endl;
    }

    bool ligar() {

        bool ativacao_sucedida = bateria->alocarPotencia(pot_nominal);

        if (ativacao_sucedida) {
            *temp_acumulada += pot_nominal * coef_aquecimento;
            std::cout<<"Motor "<<identificador<<", temperatura apos ligar, "<<*temp_acumulada<<" C"<<std::endl;

            if (*temp_acumulada >= 80.0) {
                std::cout<<"Aviso: Motor "<<identificador<<" em superaquecimento!"<<std::endl;
            }
        }

        return ativacao_sucedida;
    }


};

int main() {

    auto bateria = std::make_shared<Bateria>("BAT01", 300.0);
    std::cout << "Referencias iniciais da bateria: " << bateria.use_count() << std::endl;

    {
        Motor motorEsquerdo("M-ESQ", 40.0, bateria);
        Motor motorDireito("M-DIR", 190.0, bateria);
        std::cout << "Referencias com dois motores: " << bateria.use_count() << std::endl;

        motorEsquerdo.ligar();
        motorDireito.ligar();

        Motor motorGarra("M-GARRA", 80.0, bateria);
        motorGarra.ligar(); // Deve ser recusado, excede a capacidade (40 + 190 + 80 > 300)
    }

    std::cout << "Referencias depois que os motores sumiram: " << bateria.use_count() << std::endl;
    std::cout << "Potencia final alocada na bateria: " << bateria->getPotenciaAlocada() << " W" << std::endl;
    return 0;
}