#include <iostream>

class Record {

    public:

    const std::string cod_serie;
    std::string modelo;
    float horas_acumuladas;
    std::string status;
    float nivel_desgaste;
    float lim_desgaste;

    Record(std::string serial, std::string name, float wear_lim)
     :  cod_serie(serial),
        modelo(name),
        horas_acumuladas(0.0),
        status("ligado"),
        nivel_desgaste(0.0),
        lim_desgaste(wear_lim){
    }

    std::string getCodigoDeSerie() {return cod_serie;}
    std::string getModelo() {return modelo;}
    float getHorasAcumuladas() {return horas_acumuladas;}
    std::string getStatus() {return status;}
    float getNivelDesgaste() {return nivel_desgaste;}
    float getLimiteDesgaste() {return lim_desgaste;}

    void ligar() {
        status = "ligado";
        std::cout<<cod_serie<<" ligado com sucesso"<<std::endl;
        return;
    }

    void desligar(){
        status = "desligado";
        std::cout<<cod_serie<<" desligado com sucesso"<<std::endl;
        return;
    }

    void operar(float horas) {

        if (status == "desligado") {
            std::cout<<cod_serie<<" esta desligado, nao pode operar"<<std::endl;
            return;

        } else if (nivel_desgaste >= lim_desgaste) {
            std::cout<<"Nao pode operar. O nivel de desgaste de "<<cod_serie<<" esta no limite!"<<std::endl;
            return;

        } else {
            float incremento_hora = 0.5 * (1.0 + nivel_desgaste / 100.0);
            float incremento_total = horas * incremento_hora;
            nivel_desgaste += incremento_total;
            std::cout<<"Incremento de desgaste: "<<incremento_total<<" | Desgaste atual: "<<nivel_desgaste<<std::endl;
            return;
        }
    }

    void enviar_manutencao(Record& robo) {

        if (this->cod_serie == robo.cod_serie) {
            std::cout<<"Nao e possivel enviar manutencao de um robo para ele mesmo"<<std::endl;
            return;

        } else {
            nivel_desgaste = 0;
            std::cout<<"Nivel de desgaste zerado"<<std::endl;
            return;
        }
    }
};

int main () {

        Record rb1{"RB-001", "Alfredo", 50};
        rb1.operar(10);
        rb1.operar(20);

        Record rb2{"RB-002", "Timoteo", 50};
        rb2.desligar();
        rb2.operar(5);

        rb1.enviar_manutencao(rb1);

    return 0;
}