#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main() {
	int N, H, C, L;
    cout << fixed << setprecision(4);

	while(cin >> N) {
		cin >> H >> C >> L;

		double res = ((L * N * sqrt(pow(H,2) + pow(C,2))) / 10000.0);
        cout << res << endl;
	}
	
	return 0;
}