#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    int i = 1;
    double x, S = 0, U = 1;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите n: ";
    cin >> n;
    while (i <= n) {
        S += U;
        U *= x/i;
        ++i;
    }
    cout << "Значение функции y при этих данных = " << S << endl;
    return 0;
}
