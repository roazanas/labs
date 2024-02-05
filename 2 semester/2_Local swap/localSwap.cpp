#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int N = 20;
    int r;
    int a[N];
    int i=1, j=5;
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        a[i] = rand() % N - N/2;
        cout << a[i] << ' ';
    }
    cout << '\n';
    while (i < j) {
        r = a[i];
        a[i] = a[j];
        a[j] = r;
        i++;
        j--;
    }
    for (int i=0; i<N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
