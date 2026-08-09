#include <iostream>
#include <memory>
#include <utility>

class BaseOperacional;

class Drone {

    private:
    std::string identificador;
    std::weak_ptr<BaseOperacional> base;

    public:
    Drone(std::string nome, const std::weak_ptr<BaseOperacional>& ptr_base) : 
    identificador{nome},
    base{ptr_base} {}

    ~Drone() {
        std::cout<<"[Drone "<<identificador<<" desativado]"<<std::endl;
    }

    const std::string& getIdentificador() const {return identificador;}

    Drone& enviarDados(const std::string& dados);
    
};

class BaseOperacional {

    private:
    std::string identificador;
    std::shared_ptr<Drone> drone;

    public:
    BaseOperacional(std::string nome) : 
    identificador{nome}{}

    ~BaseOperacional() {
        std::cout<<"[Base "<<identificador<<" desativada]"<<std::endl;
    }

    BaseOperacional& conectarDrone (const std::shared_ptr<Drone>& ptr_drn) {
        drone = ptr_drn;

        std::cout<<"Drone "<<ptr_drn->getIdentificador()<<" conectado a base "<<identificador<<"."<<std::endl;

        return *this;
    }

    BaseOperacional& processarTelemetria (const std::string& nome_drone, const std::string& dados) {

        std::cout<<"["<<identificador<<"] Telemetria de "<<nome_drone<<": "<<dados<<std::endl;

        return *this;
    }
};

Drone& Drone::enviarDados(const std::string& dados) {

    std::shared_ptr<BaseOperacional> ptr_temp = base.lock();

    if (ptr_temp != nullptr) {
        ptr_temp->processarTelemetria(identificador, dados);

    } else {
        std::cout<<"Falha no envio: Base offline. Drone "<<identificador<<" operando em modo autonomo."<<std::endl;
    }

    return *this;
}

int main() {
    auto base = std::make_shared<BaseOperacional>("BASE-ALFA");

    std::cout << "Referencias da base apos criacao: " << base.use_count() << std::endl;

    auto drone = std::make_shared<Drone>("DRN-01", base);

    std::cout << "Referencias da base apos criar drone: " << base.use_count() << std::endl << std::endl;

    base->conectarDrone(drone);

    drone->enviarDados("Setor sul limpo e seguro.");

    std::cout << "\n[Simulacao] Destruindo a base de forma forcada..." << std::endl;

    base.reset();

    drone->enviarDados("Movimentacao suspeita detectada!");

    std::cout << std::endl;

    return 0;
}