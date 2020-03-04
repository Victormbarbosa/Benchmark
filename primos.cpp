#include <thread>
#include <iostream>
#include <math.h>
using namespace std;

void encontrar_primos(int comienzo, int rango) {
    string salida;
    for(int n = comienzo; n < comienzo+rango; n++) {
        if (n == 1)
            goto no_primo;
        else for (int k = 2; k <= sqrt(n); k++)
            if (n%k == 0)
                goto no_primo;

        salida = to_string(n) + "\n";
        cout << salida;
        no_primo:;
    }
}

int main() {
    int N = 50000, H = 10, rango = N/H;
    thread hilos[H];

    for (int i = 0; i < H; i++)
        hilos[i] = thread(encontrar_primos, 1 + rango*i, rango);

    for (int i = 0; i < H; i++)
        hilos[i].join();

    return 0;
}
