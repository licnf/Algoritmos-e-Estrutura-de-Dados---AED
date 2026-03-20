#include <iostream>

using namespace std;

int fatorial(int a) {
    if(a > 0)
        return a * fatorial(a - 1);
    else
        return 1;
}

int main() {
    unsigned long long int a;
    cin >> a;
    a = fatorial(a);
    cout << "Resultado: " << a << "\n";

    return 0;
}