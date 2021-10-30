#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

long solve(long n1, long n2, long m) {
	long res = 1;

	while (n2 > 0) {
		if (n2 & 1) res = (res * n1) % m;
		
        n1 = (n1 * n1) % m;
		n2 = n2 >> 1;
	}

	return res;
}

int main () {
	long R;
	cin >> R;
    long modulo = 2147483647;

    long res = solve(3, R, modulo);
	cout << res << '\n';

	return 0;
}
