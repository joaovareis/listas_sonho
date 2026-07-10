#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

    float C;
    float i;
    float n;

    std::cout<<"Digite o valor emprestado (R$): ";
    std::cin>>C;

    std::cout<<"Digite a taxa de juros mensal (%): ";
    std::cin>>i;

    std::cout<<"Digite o numero de meses: ";
    std::cin>>n;

    float M = C * pow((1 + i/100), n);
    float J = M - C;
    float PMT = C * ( (i/100) * pow((1 + i/100), n) ) / ( pow((1 + i/100), n) - 1 );

    std::cout<<""<<std::endl;
    std::cout<<"=========================================="<<std::endl;
    std::cout<<"         Simulador de Emprestimo          "<<std::endl;
    std::cout<<"=========================================="<<std::endl;
    std::cout << std::setfill('.');
    std::cout<<std::fixed<<std::setprecision(2);

    std::cout<<std::left<<std::setw(25) <<" Capital Emprestado"<<std::right<<std::setw(8)<<" R$ "<< C<<std::endl;
    std::cout<<std::left<<std::setw(25) <<" Taxa Mensal"<<std::right<<std::setw(5)<<" "<< i<<" %"<<std::endl;
    std::cout<<std::fixed<<std::setprecision(0);
    std::cout<<std::left<<std::setw(25) <<" Numero de meses"<<std::right<<std::setw(5)<<" "<< n<<std::endl;

    std::cout<<"=========================================="<<std::endl;
    std::cout<<"                Resultados                "<<std::endl;
    std::cout<<"=========================================="<<std::endl;

    std::cout<<std::fixed<<std::setprecision(2);

    std::cout<<std::left<<std::setw(25) << std::setfill('.')<<" Montante final"<<std::right<<std::setw(8)<<" R$ "<<std::setfill(' ')<<std::right<<std::setw(8)<< M<<std::endl;
    std::cout<<std::left<<std::setw(25) << std::setfill('.')<<" Total de juros"<<std::right<<std::setw(8)<<" R$ "<<std::setfill(' ')<<std::right<<std::setw(8)<< J<<std::endl;
    std::cout<<std::left<<std::setw(25) << std::setfill('.')<<" Parcela mensal (Price)"<<std::right<<std::setw(8)<<" R$ "<<std::setfill(' ')<<std::right<<std::setw(8)<< PMT<<std::endl;
    return 0;
}