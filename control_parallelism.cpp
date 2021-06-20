/**
 * Algoritmo paralelo usando threads para o Crivo de Eratóstenes.
 * JOHNATA DAVI TEIXEIRA SILVA
 */
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <atomic>

using namespace std;

typedef vector<thread> vetorTh;
typedef unsigned long long ll;
typedef unsigned int uint;

int contar(bool *v, int t) {
    int c = 0;
    for (int i = 0; i < t; i++)
        if (v[i]) c++;
    return c;
}

void crivo(bool *numeros, ll tam, atomic<uint> &primo) {
    ll raiz = (ll) sqrt(tam);
    for (ll primoThread = primo; primoThread <= raiz; primoThread = primo++)
        if (numeros[primoThread])
            for (ll j = primoThread * primoThread; j <= tam; j += primoThread)
                numeros[j] = false;
}

int main() {
    ll tam = 0;
    uint nThreads = 0;

    cout << "Numero de threads disponiveis no sistema: "
         << thread::hardware_concurrency() << endl;
    cout << "Digite o numero de threads:";
    cin >> nThreads;
    cout << "Digite valor limite:";
    cin >> tam;

    vetorTh threads(nThreads);
    bool *numeros = new bool[tam + 1];
    for (int i = 0; i < tam + 1; i++) {
        numeros[i] = true;
    }
    atomic<uint> primo(2);

    auto t1 = chrono::high_resolution_clock::now();

    for (auto &t: threads)
        t = thread(crivo, numeros, tam, ref(primo));

    for (auto &t: threads)
        t.join();

    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> ms_double = t2 - t1;

    cout << "Primos: " << contar(numeros, tam + 1) - 2 << endl;
    cout << "Tempo: " << ms_double.count() << "ms\n";

    return 0;
}
