#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int N = 10000;
    int max, S, j;
    int a[N];
    for (int i=0; i<=(N-1); i++) {
        a[i] = rand() % N - N/2;
    }
    max = a[0];
    for (int i=0; i<=(N-1); i++) {
        if (a[i] > max) {
            max = a[i];
            S = 1;
            j = i;
        } else {
            if (a[i] == max) S++;
        }
    }
    for (int i=0; i<=(N-1); i++) {
        cout << a[i] << " ";
    }
    cout << "\nМакс. элемент | Кол-во | Номер" << endl;
    cout << max << " | " << S << " | " << (j+1) << endl;
}