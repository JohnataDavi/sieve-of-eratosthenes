/**
 * Algoritmo paralelo usando OpenMP para o Crivo de Eratóstenes.
 * JOHNATA DAVI TEIXEIRA SILVA
 */
#include <iostream>
#include <omp.h>
#include <cmath>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

typedef unsigned long long ulli;
typedef unsigned int uint;
typedef vector<bool> vetor;

int main() {
    uint nThreads = 0;
    ulli tam = 0;

    cout << "Numero de cores disponiveis no sistema: " << omp_get_max_threads() << endl;
    cout << "Digite o numero de threads:";
    cin >> nThreads;
    cout << "Digite valor limite:";
    cin >> tam;

    omp_set_num_threads((int) nThreads);
    vetor numeros(tam, true);
    numeros[0] = numeros[1] = false;
    uint raiz = (uint) sqrt(tam);

    auto t1 = chrono::high_resolution_clock::now();
    for (uint i = 2; i <= raiz; i++) {

#pragma omp parallel default(none) shared(i, numeros, tam)
        {                                        // tam = 100
            uint id = omp_get_thread_num();      // 0
            uint nt = omp_get_num_threads();     // 3
            ulli size = (int) tam / nt;          // 100/3 = 33
            ulli inicio = id * size;             // 0 33 66
            ulli fim = inicio + size - 1;
            if (id == nt - 1) {
                uint resto = tam % size;
                fim += resto;
            }
            uint salto = 1;
            for (ulli m = inicio; m < (fim + 1); m += salto) {
                if (m % i == 0 && m != i) {
                    numeros[m] = false;
                    salto = i;
                }
            }
        }
    }

    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;

    cout << "Primos: " << count(numeros.begin(), numeros.end(), true) << endl;
    cout << "Tempo: " << ms_double.count() << "ms\n";

    return 0;
}
