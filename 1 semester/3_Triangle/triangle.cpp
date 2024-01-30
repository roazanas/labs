#include <iostream>
using namespace std;

int main() {
    int N, p, z=1;
    cout << "Введите нечётное число N >= 3: ";
    cin >> N;
    if ((N % 2 == 1) && (N >= 3)) {
        p=(N-1)/2;
        for (int i = 1; i <= (N+1)/2; i++) {
            cout << endl;
            for (int j = 1; j <= p; j++) {
                cout << ' ';
            }
            p -= 1;
            for (int j = 1; j <= z; j++) {
                cout << '*';
            }
            z += 2;
        }
    }
}
