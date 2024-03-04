#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double getLenght(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double square(double x1, double y1, double x2, double y2, double x3, double y3) {
	return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;
}

double square1(double n, ...) {
	n *= 2;
	double* cords = new double[n];
	double* pn = &n+1;
	for (int i=0; i<n; i++) {
		double elem = *pn;
		cords[i] = elem;
		pn++;
	}
	double maxL = 0;
	int maxI=0, maxJ=0;
	for (int i=0; i<n; i+=2) {
		for (int j=i+2; j<n; j+=2) {
			double l = getLenght(cords[i], cords[i+1], cords[j], cords[j+1]);
			if (l > maxL) {
				maxL = l; 
				maxI = i; maxJ = j;
			} 
		}
	}
	int randI = rand() % static_cast<int>(n/2) * 2;
	while ((randI == maxI) || (randI == maxJ)) {
		randI = rand() % static_cast<int>(n/2) * 2;
	}
	double triangleS = square(cords[maxI],  cords[maxI+1], 
	                          cords[maxJ],  cords[maxJ+1],
							  cords[randI], cords[randI+1]);
	delete[] cords;
	return triangleS;
}

int main() {
	const int N = 5;
	srand(time(NULL));
	double C[N*2] = {1.47, -0.1, 2.43, 3.75, -1, 2, -1.18, 0.87, -0.24, -0.82};
	cout << square1(N, C[0], C[1], C[2], C[3], C[4], C[5], C[6], C[7], C[8], C[9]) << endl;
	return 0;
}