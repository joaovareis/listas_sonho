#include <iostream>

int main() {

    float dt = 0.0;
    float v = 0.0;
    float w = 0.0;

    float pos[2] = {0.0, 0.0};

    std::cout<<"Digite a posicao inicial em x: ";
    std::cin>>pos[0];

    std::cout<<"Digite a posicao inicial em y: ";
    std::cin>>pos[1];

    while (dt >= 0) {

        std::cout<<"Digite o dt: ";
        std::cin>>dt;

        if (dt >= 0) {
            std::cout<<"Digite a velocidade v: ";
            std::cin>>v;

            std::cout<<"Digite a velocidade w: ";
            std::cin>>w;

            pos[0] += dt * v;
            pos[1] += dt * w;
        }

        std::cout<<"A posicao do robo eh (x, y): ("<<pos[0]<<", "<<pos[1]<<") m"<<std::endl;
    }

    return 0;
}