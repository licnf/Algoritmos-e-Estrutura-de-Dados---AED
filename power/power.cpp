#include <stdio.h>
#include <iostream>

#define SUCCESS 0

using namespace std;

int mult(int base, int exp) {
    if(exp > 0) 
        return mult(base, --exp) * base;
    if(exp == 0) 
        return 1;
    return 0;
}

int main() {
    int base, exp, answer;
    cout << "Digite a base e o expoente inteiros: ";
    cin >> base;
    cin >> exp;

    answer = mult(base, exp);
    cout << "Resultado: " << answer << "\n";

}