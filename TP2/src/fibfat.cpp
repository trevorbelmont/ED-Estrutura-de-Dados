#include "fibfat.hpp"

// using namespace std;

unsigned long long rFat(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    } else {
        return n * rFat(n - 1);
    }
}

unsigned long long iFat(int n) {
    long int x = n;

    if (n == 0) {
        return 1;
    }

    for (int i = n - 1; i > 0; i--) {
        x *= i;
    }
    return x;
}

unsigned long long rFib(int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    } else if (n > 2) {
        return rFib(n - 1) + rFib(n - 2);
    } else {
        return 0;
    }
}

unsigned long long iFib(int n) {
    if (n > 0 && n <= 2) {
        return 1;

    } else {
        long int f1, f2, x;
        f1 = f2 = 1;

        for (long int i = 3; i <= n; i++) {
            x = f1 + f2;
            f2 = f1;
            f1 = x;
        }
        return x;
    }
}
