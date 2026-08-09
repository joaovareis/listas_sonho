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
    double coef_aquecimento = 0.3;

    std::unique_ptr<double> temp_acumulada;
    std::shared_ptr<Bateria> bateria;

    public:

    Motor(std::string name, double pot, double coef, const std::shared_ptr<Bateria>& bat) :
    identificador{name},
    pot_nominal{pot},
    coef_aquecimento{coef},
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

            if (*temp_acumulada >= 90.0) {
                std::cout<<"Motor "<<identificador<<", temperatura apos ligar: "<<*temp_acumulada<<" C (ALERTA: Superaquecimento!)"<<std::endl;

            } else {
                std::cout<<"Motor "<<identificador<<", temperatura apos ligar: "<<*temp_acumulada<<" C"<<std::endl;
            }
        }

        return ativacao_sucedida;
    }
};

int main() {
    auto bateria = std::make_shared<Bateria>("BAT01", 150.0);
    std::cout << "Referencias iniciais da bateria: " << bateria.use_count() << std::endl << std::endl;
    {
        Motor motorEsquerdo("M-ESQ", 50.0, 0.8, bateria);
        Motor motorDireito("M-DIR", 50.0, 0.6, bateria);
        std::cout << "Referencias com dois motores: " << bateria.use_count() << std::endl << std::endl;
        motorEsquerdo.ligar(); // Primeiro ciclo, esquenta
        motorEsquerdo.ligar(); // Segundo ciclo, acumula mais calor e aciona o alerta
        motorDireito.ligar(); // Primeiro ciclo
        std::cout << std::endl;
        Motor motorGarra("M-GARRA", 60.0, 0.5, bateria);
        motorGarra.ligar(); // Deve ser recusado, bateria sem margem
        std::cout << std::endl;
    }
    std::cout << "\n=== Status Final do Sistema ===" << std::endl;
    std::cout << "Referencias ativas da bateria: " << bateria.use_count() << std::endl;
    std::cout << "Carga final da bateria: " << bateria->getPotenciaAlocada() << " W / " << bateria->getCapacidadeMaxima() << " W"<<std::endl;
    return 0;
}