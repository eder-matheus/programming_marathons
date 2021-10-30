#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int mdc(int n1, int n2) {
	int r = n1 % n2;
	while (r > 0) {
		n1 = n2;
		n2 = r;
		r = n1 % n2;
	}

	return n2;
}

int mmc(int n1, int n2){
    int res = (n1 / mdc(n1, n2)) * n2;
    return res;
}

int main() {
	int N, A, B;

	while (cin >> N >> A >> B) {
        if (N > 0) cout << ((N/A) + (N/B)) - N / mmc(A, B) << endl;
        else break;
    }

	return 0;
}
