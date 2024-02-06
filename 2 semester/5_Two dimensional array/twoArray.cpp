#include <iostream>
#include <ctime>
using namespace std;
const int N = 4;

bool isNumGreatest(int num, int array[N]) {
    bool f = 1;
    int i = 0;
    while ((f) && (i<N)) {
        if (num <= array[i]) {f = 0;}
        i++;
    }
    return f;
}

int main() {
    int a[N][N];
    // int a[N][N] = {{5, 69, 1},
    //                {-2, 10, 100},
    //                {15, 24, 14}};
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    int diag[N];
    for (int i=0; i<N; i++) {
        diag[i] = a[i][i];
    }
    int count = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << a[i][j] <<' ';
            if (isNumGreatest(a[i][j], diag)) {count++;}
        }
        cout << '\n';
    }
    cout << count;
    return 0;
}