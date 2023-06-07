#include <cmath>
#include "ehPrimo.h"

bool ehPrimo(int n) {
    if (n <= 1) {
        return false;
    }

    int limite = sqrt(n);
    for (int i = 2; i <= limite; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int proximoPrimo(int n) {
    if (n <= 1) {
        return 2;
    }

    int proximo = n + 1;
    while (!ehPrimo(proximo)) {
        proximo++;
    }

    return proximo;
}
