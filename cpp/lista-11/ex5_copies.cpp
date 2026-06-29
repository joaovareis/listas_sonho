#include <iostream>
#include <vector>

class RoboMovel {

    friend class ControlCenter;

    private:

    std::string identificador;
    std::string tipo_chassi;
    float nivel_bateria;
    float pos_atual;
    std::string *historico;
    int capacidade_historico;
    int num_operacoes;

    public:

    RoboMovel (std::string id, std::string chassi, float bateria_inicial, float pos_inicial, int cap_historico)
     :  identificador{id},
        tipo_chassi{chassi},
        nivel_bateria(bateria_inicial),
        pos_atual{pos_inicial},
        capacidade_historico{cap_historico},
    
        num_operacoes{0}{

        historico = new std::string[cap_historico];
    }

    RoboMovel (const RoboMovel &source) //Construtor de Cópia Profunda
     :  identificador{source.identificador},
        tipo_chassi{source.tipo_chassi},
        nivel_bateria(source.nivel_bateria),
        pos_atual{source.pos_atual},
        capacidade_historico{source.capacidade_historico},
        num_operacoes{source.num_operacoes}
        {

        historico = new std::string[num_operacoes];

        for (int i = 0; i < num_operacoes; i++) {
            historico[i] = source.historico[i];
        }

        std::cout<<"[Copia Profunda] "<< source.identificador<<std::endl;
    }

    RoboMovel (RoboMovel &&source) noexcept //Construtor de Movimento
     :  identificador{source.identificador},
        tipo_chassi{source.tipo_chassi},
        nivel_bateria(source.nivel_bateria),
        pos_atual{source.pos_atual},
        capacidade_historico{source.capacidade_historico},
        historico{source.historico}
        {
        
        source.historico = nullptr;
        source.num_operacoes = 0;
        std::cout<<"[Movimento] "<< source.identificador<<std::endl;
    }

    ~RoboMovel () {
        if (historico != nullptr) {
            delete[] historico;
        }
    }  

    void receber_comando(std::string comando) {
        if (num_operacoes < capacidade_historico) {
            historico[num_operacoes] = comando;
            num_operacoes++;
        }
    }

    std::string getIdentificador() { return identificador; }
    std::string getTipoChassi() { return tipo_chassi; }
    float getNivelBateria() { return nivel_bateria; }
    float getPosAtual() { return pos_atual; }


};

class ControlCenter {
public:
    void gerar_relatorio(const RoboMovel& robo) {
        std::cout<<"Identificador: "<< robo.identificador<<std::endl;
        std::cout<<"Comandos recebidos: "<< robo.num_operacoes<<std::endl;
        std::cout<<"Capacidade do historico: "<< robo.capacidade_historico<<std::endl;
    }
};

int main() {
    RoboMovel rm01("RM-01", "Tacahama", 100.0, 0.0, 5);
    rm01.receber_comando("Mover Norte");
    rm01.receber_comando("Coletar Caixa");

    RoboMovel rm02{rm01}; 

    std::vector<RoboMovel> frota;
    frota.push_back(RoboMovel{"RM-03", "Lagarta", 85.0, 10.5, 5}); 

    ControlCenter centro;
    centro.gerar_relatorio(rm01);

    return 0;
}