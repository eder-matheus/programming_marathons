#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

long mdc(long n1, long n2) {
	long r = n1 % n2;
	while (r != 0) {
		n1 = n2;
		n2 = r;
		r = n1 % n2;
	}
	return n2;
}

int main() {
	long res = 1;
	long t, buraco, num_buracos;
    long buracos_vector[105];

	cin >> num_buracos;

	for (long i = 1; i <= num_buracos; i++)
		cin >> buracos_vector[i];
    
	for (long i = 1; i <= num_buracos; i++){
		t = 1;
		buraco = buracos_vector[i];

		while (buraco != i) {
			t++;
			buraco = buracos_vector[buraco];
		}
		res = (t*res) / mdc(res, t);
	}
	cout << res << endl;
}