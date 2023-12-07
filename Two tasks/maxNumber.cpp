#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int N, S=1, a, max, i=1, j=1;
    cout << "Введите число N: ";
    cin >> N;
    cout << "Введите первое число: ";
    cin >> a;
    max = a;
    while (i < N) {
        cout << "Введите число: ";
        cin >> a;
        ++i;
        if (a > max) {
            max = a;
            S = 1;
            j = i;
        } else {
            if (a == max) ++S;
        }
    }
    cout << "Максимальное число последовательности: " << max << endl;
    cout << "Совпадают с максимальным: " << S << endl;
    cout << "Номер первого вхождения максимального числа: " << j << endl;
    return 0;
}
