#include <iostream>
#include <iomanip>

int main() {

    int n;

    std::cout<<"Digite o numero: ";
    std::cin>>n;

    for(int i = 0; i < n+1; i++) {

        for(int j = 0; j < i; j++) {
            std::cout<<"*";

        }

        std::cout<<std::endl;

    }

    for(int i = 0; i < n+1; i++) {

        for(int j = n - i; j > 0; j--) {
            std::cout<<" ";

        }

        for(int j = 0; j < i; j++) {
            std::cout<<"*";

        }

        std::cout<<std::endl;

    }

    for(int i = 0; i < n+1; i++) {

        for(int j = n - i; j > 0; j--) {
            std::cout<<" ";
        }

        for(int k = 1; k <= 2*i-1; k++) {
            std::cout<<"*";
        }

        std::cout<<std::endl;

    }

    return 0;
}