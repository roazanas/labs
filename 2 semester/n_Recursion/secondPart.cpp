#include <iostream>
#include <map>
using namespace std;
map<unsigned long, unsigned long> cacheTable;

unsigned long cache(int n) {
    if (cacheTable.count(n) == 1) {
        return cacheTable[n];
    } else {
        return -1;
    }
}

unsigned long fib(int n) {
    if (n <= 0) {
        cout << "Некорректное значение n!";
        return NAN;
    }
    unsigned long cacheResult = cache(n);
    if (cacheResult != -1) {
        return cacheResult;
    }
    switch (n) {
        case 1:
            return 0;
            break;
        case 2:
            return 1;
            break;
        default:
            unsigned long result = fib(n-1) + fib(n-2);
            cacheTable[n] = result;
            return result;
            break;
    }
}
 
int main() {
    setlocale(LC_ALL, "Russian");
    for (int i=1; i<=1000; i++) {
        cout << fib(i) << ' ';
    }
    return 0; 
}