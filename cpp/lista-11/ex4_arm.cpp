#include <iostream>

class Roboarm {

    public:

    std::string nome_do_braco;
    float ang_atual_base;
    float ang_atual_cotov;
    float vel_movimento;
    bool esta_calibrado;
    float lim_curso_junta_base;
    float lim_curso_junta_cotov;

    Roboarm (std::string nome, float lim_junta_base, float lim_junta_cotov) :

        nome_do_braco{nome},
        lim_curso_junta_base{lim_junta_base},
        lim_curso_junta_cotov{lim_junta_cotov},
        
        ang_atual_base{0.0},
        ang_atual_cotov{0.0},
        vel_movimento{0.0},
        esta_calibrado{false}{
    }

    Roboarm& setAngJuntaBase (float ang) {
        this->ang_atual_base = ang; 
        return *this;
    }

    Roboarm& setAngJuntaCotovelo (float ang) {
        this->ang_atual_cotov = ang; 
        return *this;
    }

    Roboarm& setVelocidade (float vel) {
        this->vel_movimento = vel; 
        return *this;
    }

    Roboarm& setCalibracao (bool cal) {
        this->esta_calibrado = cal; 
        return *this;
    }

    void mover_para (float ang_base, float ang_cotov) {

        if (ang_base > lim_curso_junta_base) {

            std::cout<<nome_do_braco<<": movimento recusado, junta da base excederia o limite de "<<lim_curso_junta_base<<" graus";

        } else if (ang_cotov > lim_curso_junta_cotov) {

            std::cout<<nome_do_braco<<": movimento recusado, junta do cotovelo excederia o limite de "<<lim_curso_junta_cotov<<" graus";

        } else {

            float delta_base = std::abs(ang_base - ang_atual_base);
            float delta_cotov = std::abs(ang_cotov - ang_atual_cotov);

            float maior_delta = std::max(delta_base, delta_cotov);
            float tempo = maior_delta/vel_movimento;

            std::cout<<nome_do_braco<<": moveu para base = "<<ang_base<<", cotovelo = "<<ang_cotov<<" em "<<tempo<<"s"<<std::endl;
        }

        return;
    }
};

int main () {

    Roboarm rb1 {"BracoA", 90, 120};

    rb1.setVelocidade(2.5).setCalibracao(true);

    rb1.mover_para(45, 30);

    rb1.mover_para(150, 0);

    return 0;
}