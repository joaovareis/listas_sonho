#include <iostream>

class Vetor2D {
    private:

    double x, y;

    public: 

    Vetor2D (double valor_x, double valor_y):
    x{valor_x},
    y{valor_y}
    {}

    Vetor2D operator+ (const Vetor2D &other) {
        return Vetor2D(x + other.x, y + other.y);
    }

    Vetor2D operator- (const Vetor2D &other) {
        return Vetor2D(x - other.x, y - other.y);
    }

    Vetor2D operator- () {
        return Vetor2D(-x, -y);
    }

    Vetor2D operator* (const double &escalar) {
        return Vetor2D(x * escalar, y * escalar);
    }

    Vetor2D operator/ (const double &escalar) {
        return Vetor2D(x / escalar, y / escalar);
    }

    Vetor2D& operator+= (const Vetor2D &other) {
        x += other.x;
        y += other.y; 

        return *this;
    }

    bool operator== (const Vetor2D &other) const {
        return (this->x == other.x and this->y == other.y);
    }

    bool operator!= (const Vetor2D &other) const {
        return (this->x != other.x or this->y != other.y);
    }

    friend std::ostream& operator<<(std::ostream &os, const Vetor2D &vector);

};

std::ostream& operator<< (std::ostream &os, const Vetor2D &vector) {
    os << "("<< vector.x<<", "<<vector.y<<")";
    return os;
}

int main() {
    Vetor2D forcaMotorEsquerdo(3.0, 4.0);
    Vetor2D forcaMotorDireito(1.0, 2.0);

    Vetor2D forcaResultante = forcaMotorEsquerdo + forcaMotorDireito;
    std::cout << "Forca resultante, " << forcaResultante << std::endl;

    Vetor2D forcaComMargem = forcaResultante * 1.5;
    std::cout << "Forca com margem de seguranca, " << forcaComMargem << std::endl;

    Vetor2D diferenca = forcaMotorEsquerdo - forcaMotorDireito;
    std::cout << "Diferenca entre os motores, " << diferenca << std::endl;

    Vetor2D forcaMotorEsquerdoRepetida(3.0, 4.0);

    std::cout << std::boolalpha;
    std::cout << "Motor esquerdo e igual a si mesmo? " << (forcaMotorEsquerdo == forcaMotorEsquerdoRepetida) << std::endl;
    std::cout << "Motor esquerdo e diferente do direito? " << (forcaMotorEsquerdo != forcaMotorDireito) << std::endl;

    Vetor2D forcaDividida = forcaResultante / 2.0;
    std::cout << "Forca resultante dividida entre dois atuadores, " << forcaDividida << std::endl;

    Vetor2D forcaReacao = -forcaResultante;
    std::cout << "Forca de reacao, " << forcaReacao << std::endl;

    Vetor2D acumulador(0.0, 0.0);
    acumulador += forcaMotorEsquerdo;
    acumulador += forcaMotorDireito;
    std::cout << "Acumulador apos += dos dois motores, " << acumulador << std::endl;

    return 0;
}

