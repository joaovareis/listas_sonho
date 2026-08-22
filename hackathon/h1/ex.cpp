#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

struct Pose2D {
    float x;
    float y;
    float theta;

    friend std::ostream& operator<<(std::ostream& os, const Pose2D& pose) {
        os<<pose.x<<", "<<pose.y<<", "<< pose.theta;
        return os;
    }
};

struct SE2{

    float mat[3][3];

    SE2 () {
        for(int i = 0; i<3; i++){
            for (int j = 0; j<3; j++){
                if (j != i) {
                    mat[i][j] = 0.0;
                } else {
                    mat[i][j] = 1.0;
                }
            }
        }
    }

    Pose2D to_pose2d () {

        Pose2D pose;

        pose.x = mat[0][2];
        pose.y = mat[1][2];

        pose.theta = std::atan2(mat[1][0], mat[0][0]);

        return pose;
    }

    SE2 operator*(const SE2& other) const {

        SE2 resultado;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                resultado.mat[i][j] = 0.0;

                for (int k = 0; k < 3; k++) {
                    resultado.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                }
            }
        }
        return resultado;
    }
};

class Link2D{
    public:

    char type;
    float l;

    Link2D (char tipo, float comprimento) :
    type{tipo},
    l{comprimento} {}

    SE2 operator()(float q) const {
        char t = std::toupper(type);
        SE2 transformacao;

        if (t == 'P') {
            transformacao.mat[0][0] = 1.0; 
            transformacao.mat[0][1] = 0.0; 
            transformacao.mat[0][2] = l + q;

            transformacao.mat[1][0] = 0.0; 
            transformacao.mat[1][1] = 1.0; 
            transformacao.mat[1][2] = 0.0;

            transformacao.mat[2][0] = 0.0; 
            transformacao.mat[2][1] = 0.0; 
            transformacao.mat[2][2] = 1.0;
        
        } else if (t == 'R') {

            transformacao.mat[0][0] = std::cos(q); 
            transformacao.mat[0][1] = - std::sin(q); 
            transformacao.mat[0][2] = l * std::cos(q);

            transformacao.mat[1][0] = std::sin(q); 
            transformacao.mat[1][1] = std::cos(q); 
            transformacao.mat[1][2] = l * std::sin(q);

            transformacao.mat[2][0] = 0.0; 
            transformacao.mat[2][1] = 0.0; 
            transformacao.mat[2][2] = 1.0;
        }
        return transformacao;
    }
};

class Manipulator2D{
    public:

    std::vector<Link2D> links;

    Manipulator2D (std::vector<Link2D>& l) : 
    links{l} {}

    Pose2D forward_kinematics(const std::vector<float>& q) {
        SE2 final;

        for(int i = 0; i < links.size(); i++) {
            final = final * links[i](q[i]);
        }

        return final.to_pose2d();
    }

    unsigned int get_dof() const {
        return static_cast<unsigned int>(links.size());
    }
};

int main() {

    std::ifstream input("hackathon/h1/input.csv");
    std::ofstream output("hackathon/h1/output.csv");

    std::string header;
    std::getline(input, header);
    output<<header<<std::endl;

    std::vector<Link2D> links;

    size_t pos = 0;
    while (pos < header.length()) {

        while (header[pos] == ' ' or header[pos] == ','){
            pos++;
        }

        char type = header[pos];

        pos = header.find(',', pos);
        pos++;

        while (header[pos] == ' ') {
            pos++;
        }

        size_t next_comma = header.find(',', pos);
        std::string comp_str;

        if (next_comma != std::string::npos) {
            comp_str = header.substr(pos, next_comma - pos);
            pos = next_comma + 1;
        } else {
            comp_str = header.substr(pos);
            pos = header.length();
        }

        float length = std::stof(comp_str);
        links.push_back(Link2D(type, length));
    }

    Manipulator2D robot(links);

    std::string linha;
    while (std::getline(input, linha)) {

        std::vector<float> q_values;
        size_t p = 0;

        while (p < linha.length()) {
            while (linha[p] == ' ' || linha[p] == ',') p++;

            size_t next_c = linha.find(',', p);
            std::string val_str;

            if (next_c != std::string::npos) {
                val_str = linha.substr(p, next_c - p);
                p = next_c + 1;
                
            } else {
                val_str = linha.substr(p);
                p = linha.length();
            }

            q_values.push_back(std::stof(val_str));
        }

        Pose2D pose_final = robot.forward_kinematics(q_values);
        output << pose_final << std::endl;
        std::cout << pose_final << std::endl;
    }

    input.close();
    output.close();

    return 0;
}