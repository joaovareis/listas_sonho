#include <cmath>
#include <iostream>

class Junta {

    private:

    std::string identificador;

    public:
    
    Junta(std::string nome) : 
    identificador{nome} {}

    virtual ~Junta() {};

    const std::string& getIdentificador() const {return identificador;}

    virtual double calcularTorque () const = 0;

    virtual void imprimir(std::ostream& os) const {
        os << "Junta " << identificador;
    }

    friend std::ostream& operator<< (std::ostream& os, const Junta& junta) {
        junta.imprimir(os);
        return os;
    }
};

class JuntaRotacional : public Junta{

    private:

    double forca;
    double comprimentoBraco;
    double anguloGraus;

    public:

    JuntaRotacional(std::string nome, double strenght, double arm_lenght, double angle) : 
    Junta(nome),
    forca{strenght},
    comprimentoBraco{arm_lenght},
    anguloGraus{angle} {};

    ~JuntaRotacional() {}

    const double& getForca() const {return forca;}

    JuntaRotacional& setForca (const double& nova_forca) {
        if (nova_forca > 0) {
            this->forca = nova_forca;

        } else {
            std::cout<<"Forca invalida, deve ser maior que zero"<<std::endl;

        }

        return *this;
    }

    double calcularTorque () const override {

        double torque = forca * comprimentoBraco * std::sin((anguloGraus * M_PI) / 180);
        return torque;
    }

    JuntaRotacional& operator+= (const double& valor) {

        if (valor > 0) {

            this->forca += valor;
            return *this;

        }

        std::cout<<"Forca invalida, deve ser maior que zero"<<std::endl;

        return *this;
    }

    void imprimir(std::ostream& os) const override {
        os << "JuntaRotacional " << getIdentificador()
           << ", forca " << forca << " N"
           << ", braco " << comprimentoBraco << " m"
           << ", angulo " << anguloGraus << " graus"
           << ", torque " << calcularTorque() << " N.m";
    }
};

int main() {

    JuntaRotacional ombro("J-OMBRO", 50.0, 0.4, 90.0);
    JuntaRotacional cotovelo("J-COTOVELO", 30.0, 0.3, 45.0);

    std::cout << ombro << std::endl;
    std::cout << cotovelo << std::endl;

    Junta* maiorTorque;

    if (cotovelo.calcularTorque() < ombro.calcularTorque()) {
        maiorTorque = &ombro;

    } else {
        maiorTorque = &cotovelo;

    }

    std::cout << "Junta com maior torque: " << maiorTorque->getIdentificador() << std::endl;

    ombro += 10.0;
    std::cout << "Apos incremento de forca: " << std::endl << ombro << std::endl;

    ombro.setForca(-5.0);

    return 0;
}
