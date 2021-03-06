#include <iostream>
#include <thread>
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
    // Programas para cada benchmark

    // CPU: Encontrar los primeros 50000 números primos con 10 hilos.
    int N = 50000, H = 10, rango = N/H;
    thread hilos[H];
    for (int i = 0; i < H; i++)
        hilos[i] = thread(encontrar_primos, 1 + rango*i, rango);
    for (int i = 0; i < H; i++)
        hilos[i].join();

    // CPU: Encontrar los primeros 250000 dígitos de pi.
    // CPU: Encontrar la salida del laberinto con X hilos.
    // Disco: Duración de escritura (archivo generado) y lectura y de archivos de 1, 10, 100, 500 y 1000 MB.
    // Disco: Medición de cuantos archivos de 4 Kb puede copiar de una carpeta a otra en X segundos.
    // RAM: Iterar sobre diferentes cantidades (hasta 2 Gb) de datos aleatorios

    return 0;
}
