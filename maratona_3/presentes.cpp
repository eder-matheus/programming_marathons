#include <stdio.h>
#include <iostream>
#include <stdlib.h>

const int MAX = 10000;

using namespace std;

int main() {
    int T, N;
    int presentes[MAX];
    bool dp[11][MAX];
	cin >> T;

	for (int c = 0; c < T; c++) {
        cin >> N;
		
        for(int i = 0; i < N; i++)
		    cin >> presentes[i];

		for(int i = N; i >= 0; i--) {
			for(int j = 0; j < 11; j++) {
				if ((i == N) or ((j+presentes[i] < 11) and (dp[j+presentes[i]][i+1])) or ((j-presentes[i] >= 0) and (dp[j-presentes[i]][i+1])))
                    dp[j][i] = true;
                else 
                    dp[j][i] = false;
			}
		}

        if (dp[5][0]) cout <<  "Feliz Natal!" << endl;
        else cout <<  "Ho Ho Ho!" << endl;
	}
}
