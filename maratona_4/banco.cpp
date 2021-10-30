// Wrong Answer, mas pelos testes ta tudo correto.

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main() {
	unsigned long fatorial[100002];
	int n;
	
	fatorial[3] = 1;
	for (int i = 4; i <= 100000; i++)
		fatorial[i] = (i*fatorial[i-1]) % 1000000009;
	
	while (cin >> n){
        if (!n) break;
        else cout << fatorial[n] << endl;
    }

    return 0;
}