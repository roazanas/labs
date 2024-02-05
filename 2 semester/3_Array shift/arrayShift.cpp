#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int N = 20;
    int r, k=1;
    int a[N];
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        a[i] = rand() % 101 - 50;
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i=0; i<k; i++) {
        r = a[0];
        for (int j=0; j<(N-1); j++) {
            a[j] = a[j+1];
        }
        a[N-1] = r;
    }
    for (int i=0; i<N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
