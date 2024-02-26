#include <iostream>
using namespace std;

void hanoi(int n, int s, int e) {
    cout << "hanoi("<<n<<", "<<s<<", "<<e<<")\n";
    if (n == 1)
    cout << "Перемещение 1 диска с "<<s<<" на "<<e<<endl;
    else {
        int t = 6-s-e;
        hanoi(n-1, s, t);
        cout << "Перемещение "<<n<<" диска с "<<s<<" на "<<e<<endl;
        hanoi(n-1, t, e);
    }
}

int main() {
    int n, s, e;
    setlocale(LC_ALL, "Russian");
    cout << "Кол-во колец: "; cin >> n;
    cout << "Номер начального стержня: "; cin >> s;
    cout << "Номер конечного стержня: "; cin >> e;
    hanoi(n, s, e);
    return 0;
}