#include <iostream>

using namespace std;

struct MotorRotativo { 
    double velocidade;

};

int main() {

    MotorRotativo* variavel = new MotorRotativo();

    variavel->velocidade = 1.5;
    
    cout<<"Velocidade: "<<variavel->velocidade<<endl;

    delete variavel;

    return 0;

}