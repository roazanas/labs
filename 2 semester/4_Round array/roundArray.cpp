#include <iostream>
#include <ctime>
using namespace std;

int main() {
    const int N = 20;
    int fN = N; // fake N - для "удаления" элементов из массива
    int a[N];
    int k = 3;
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        a[i] = rand() % 101 - 50;
    }
    // циклический вывод
    for (int i=k; i<=(k+1+fN); i++) {
        cout << a[i%fN] << ' ';
    }
    cout << '\n';
    // сортировка вставкой
    for (int i=1; i<fN; i++) {
        int j = i;
        while ((j>0) && (a[j-1] < a[j])) {
            int tmp = a[j];
            a[j] = a[j-1];
            a[j-1] = tmp;
            j--;
        }
    }
    // удаление нечётных элементов
    int cor = 0;
    for (int i=0; i<N; i++) {
        int fi = i + cor;
        if (a[fi] % 2 != 0) {
            for (int j=fi; j<(fN-1); j++) {
                a[j] = a[j+1];
            }
            fN--;
            cor--;
        }
    }
    for (int i=k; i<=(k+1+fN); i++) {
        cout << a[i%fN] << ' ';
    }
    cout << '\n';
    return 0;
}
