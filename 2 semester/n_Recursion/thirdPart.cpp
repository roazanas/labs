#include <iostream>
using namespace std;

void hanoi(int n, int s, int e) {
    cout << "hanoi("<<n<<", "<<s<<", "<<e<<")\n";
    if (n == 1)
    cout << "����������� 1 ����� � "<<s<<" �� "<<e<<endl;
    else {
        int t = 6-s-e;
        hanoi(n-1, s, t);
        cout << "����������� "<<n<<" ����� � "<<s<<" �� "<<e<<endl;
        hanoi(n-1, t, e);
    }
}

int main() {
    int n, s, e;
    setlocale(LC_ALL, "Russian");
    cout << "���-�� �����: "; cin >> n;
    cout << "����� ���������� �������: "; cin >> s;
    cout << "����� ��������� �������: "; cin >> e;
    hanoi(n, s, e);
    return 0;
}