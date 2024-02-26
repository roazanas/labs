#include <iostream>
#include <cmath> 
using namespace std;
 
int fact(int n) { 
    if (n == 0 || n == 1) {
        return 1;
    } else { 
        return n * fact(n-1);
    } 
} 
 
double f_n(double x, int n) { 
    return pow(x, 2*n + 1) / fact(2*n + 1); 
} 

double s(double x, int n) { 
    if (n == 0) {
        return x;
    } else {
        return s(x, n-1) + f_n(x, n);
    } 
} 
 
int main() {
    setlocale(LC_ALL, "Russian");
    double x;
    int n;
    cout << "¬ведите значени€ х и n: "; 
    cin >> x >> n;
    double result = s(x, n);
    cout << "«начение р€да S(" << x << ", " << n << ") приближенно равно: " << result << endl; 
    return 0; 
}
