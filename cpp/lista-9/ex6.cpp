#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

bool isValid(char* arr);
void extractMsg(char* input, char* msg);
void extractCmd(char* msg, char* cmd);
void extractParam(char* msg, char* cmd, std::vector<double> &params);
void publishMsg(char* cmd, std::vector<double> params);

int main() {
    char entrada[100];
    char msg[100];
    char cmd[20];

    std::vector<double> params;

    std::cout<<"Digite o comando: ";
    std::cin.getline(entrada, 100);

    if(not isValid(entrada)) {
        std::cout<<"ERRO: formato invalido. Esperado <COMANDO ...>"<<std::endl;
        return 0;
    }

    extractMsg(entrada, msg);

    extractCmd(msg, cmd);

    extractParam(msg, cmd, params);

    publishMsg(cmd, params);

    return 0;
}

bool isValid(char* arr) {
    if (*(arr) != '<' or *(arr + strlen(arr) - 1) != '>') {
        return false;

    } else {
        return true;
    }
}

void extractMsg(char* input, char* msg) {
    int input_size = strlen(input);

    for(int i = 0; i < input_size - 2; i++) {
        *(msg + i) = *(input + 1 + i);
    }

    *(msg + input_size - 2) = '\0';
}

void extractCmd(char* msg, char* cmd) {
    int msg_size = strlen(msg);
    int index = 0;

    while(*(msg + index) != ' ') {
        *(cmd + index) = *(msg + index);
        index++;

        if (*(msg + index) == '\0'){
            break;
        }
    }

    *(cmd + index) = '\0';
}

void extractParam(char* msg, char* cmd, std::vector<double> &params) {
    std::vector<int> pos_args;
    int msg_size = strlen(msg);
    
    if (strcmp(cmd, "MOTORSON\0") == 0 or strcmp(cmd, "MOTORSOFF\0") == 0) {
        return;
    } else if (strcmp(cmd, "D2W\0") == 0) {

        for(int i = 0; i < msg_size; i++) {
            if(*(msg + i) == ' ') {
                pos_args.push_back(i);
            }
        }

        char param1[8];
        for(int i = pos_args[0] + 1; i < pos_args[1]; i++) {
            *(param1 + i - pos_args[0] - 1) = *(msg + i);
        }
        *(param1 + pos_args[1] - pos_args[0] - 1) = '\0';
        params.push_back(std::stof(param1));

        char param2[8];
        for(int i = pos_args[1] + 1; i < msg_size; i++) {
            *(param2 + i - pos_args[1] - 1) = *(msg + i);
        }
        *(param2 + msg_size - pos_args[1] - 1) = '\0';
        params.push_back(std::stof(param2));

    } else if (strcmp(cmd, "D4W\0") ==  0 or strcmp(cmd, "OMN\0") ==  0) {

        for(int i = 0; i < msg_size; i++) {
            if(*(msg + i) == ' ') {
                pos_args.push_back(i);
            }
        }

        char param1[8];
        for(int i = pos_args[0] + 1; i < pos_args[1]; i++) {
            *(param1 + i - pos_args[0] - 1) = *(msg + i);
        }
        *(param1 + pos_args[1] - pos_args[0] - 1) = '\0';
        params.push_back(std::stof(param1));

        char param2[8];
        for(int i = pos_args[1] + 1; i < pos_args[2]; i++) {
            *(param2 + i - pos_args[1] - 1) = *(msg + i);
        }
        *(param2 + pos_args[2] - pos_args[1] - 1) = '\0';
        params.push_back(std::stof(param2));

        char param3[8];
        for(int i = pos_args[2] + 1; i < pos_args[3]; i++) {
            *(param3 + i - pos_args[2] - 1) = *(msg + i);
        }
        *(param3 + pos_args[3] - pos_args[2] - 1) = '\0';
        params.push_back(std::stof(param3));

        char param4[8];
        for(int i = pos_args[3] + 1; i < msg_size; i++) {
            *(param4 + i - pos_args[3] - 1) = *(msg + i);
        }
        *(param4 + msg_size - pos_args[3] - 1) = '\0';
        params.push_back(std::stof(param4));

    } else if (strcmp(cmd, "AKM\0") ==  0) {
        for(int i = 0; i < msg_size; i++) {
            if(*(msg + i) == ' ') {
                pos_args.push_back(i);
            }
        }

        char param1[8];
        for(int i = pos_args[0] + 1; i < pos_args[1]; i++) {
            *(param1 + i - pos_args[0] - 1) = *(msg + i);
        }
        *(param1 + pos_args[1] - pos_args[0] - 1) = '\0';
        params.push_back(std::stof(param1));

        char param2[8];
        for(int i = pos_args[1] + 1; i < pos_args[2]; i++) {
            *(param2 + i - pos_args[1] - 1) = *(msg + i);
        }
        *(param2 + pos_args[2] - pos_args[1] - 1) = '\0';
        params.push_back(std::stof(param2));

        char param3[8];
        for(int i = pos_args[2] + 1; i < msg_size; i++) {
            *(param3 + i - pos_args[2] - 1) = *(msg + i);
        }
        *(param3 + msg_size - pos_args[2] - 1) = '\0';
        params.push_back(std::stof(param3));
    }
}

void publishMsg(char* cmd, std::vector<double> params) {

    if (strcmp(cmd, "MOTORSON\0") == 0) {
        std::cout<<"Tipo: Motores LIGADOS"<<std::endl;

    } else if(strcmp(cmd, "MOTORSOFF\0") == 0) {
        std::cout<<"Tipo: Motores DESLIGADOS"<<std::endl;

    } else if(strcmp(cmd, "D2W\0") == 0) {
        std::cout<<"Tipo: DiffDrive 2 rodas"<<std::endl;

        std::cout<<"m1 = "<<params[0]<<" rad/s"<<std::endl;
        std::cout<<"m2 = "<<params[1]<<" rad/s"<<std::endl;

    } else if(strcmp(cmd, "D4W\0") == 0){
        std::cout<<"Tipo: DiffDrive 4 rodas"<<std::endl;

        std::cout<<"m1 = "<<params[0]<<" rad/s"<<std::endl;
        std::cout<<"m2 = "<<params[1]<<" rad/s"<<std::endl;
        std::cout<<"m3 = "<<params[2]<<" rad/s"<<std::endl;
        std::cout<<"m4 = "<<params[3]<<" rad/s"<<std::endl;

    } else if(strcmp(cmd, "OMN\0") == 0) {
        std::cout<<"Tipo: Omnidirecional"<<std::endl;

        std::cout<<"m1 = "<<params[0]<<" rad/s"<<std::endl;
        std::cout<<"m2 = "<<params[1]<<" rad/s"<<std::endl;
        std::cout<<"m3 = "<<params[2]<<" rad/s"<<std::endl;
        std::cout<<"m4 = "<<params[3]<<" rad/s"<<std::endl;

    } else if(strcmp(cmd, "AKM\0") == 0) {
        std::cout<<"Tipo: Ackerman"<<std::endl;

        std::cout<<"m1 = "<<params[0]<<" rad/s"<<std::endl;
        std::cout<<"m2 = "<<params[1]<<" rad/s"<<std::endl;
        std::cout<<"angulo = "<<params[2]<<" rad"<<std::endl;

    } else {
        std::cout<<"[ERRO] Comando invalido"<<std::endl;
    }

}