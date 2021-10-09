#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int MAX = 2010;
int memo[MAX][MAX];
int custo[MAX];
int preco[MAX];

int N, M, P;

int calculate(int i, int idade) {
    if (i == N) 
        memo[i][idade] = 0;
    else if (memo[i][idade] != -1)
        memo[i][idade] = memo[i][idade];
    else if (idade == M)
        memo[i][idade] = calculate(i+1, 1) + P - preco[idade-1] + custo[0];
    else {
        int calc_1 = calculate(i+1, 1) + P - preco[idade-1] + custo[0];
        int calc_2 = calculate(i+1, idade+1) + custo[idade];
        memo[i][idade] = min(calc_1, calc_2);
    }

    return memo[i][idade];
}

int main() {
    int I;
    while (cin >> N >> I >> M >> P) {

        for (int i = 0; i < M; i++)
            cin >> custo[i];
        for (int i = 0; i < M; i++)
            cin >> preco[i];
    
        memset(memo, -1, sizeof memo);
        cout << calculate(0, I) << endl;
        int x = I;

        vector<int> vetor;
        for (int i = 0; i < MAX; i++)
            memo[N][i] = 0;
        
        int i = 0;
        while (i < N) {
            if (x == M) {
                vetor.push_back(i+1);
                x = 1;
            } else {
                int calc_1 = memo[i+1][1] + P - preco[x-1] + custo[0];
                int calc_2 = memo[i+1][x+1] + custo[x];

                if (calc_1 <= calc_2) {
                    x = 1;
                    vetor.push_back(i+1);
                } else {
                    x++;
                }
            }
            i++;
        }

        int len = vetor.size();

        if (len == 0) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < len; i++) {
            if (i) 
                cout << ' ' << vetor[i];
            else 
                cout << vetor[i];
        }

        cout << endl;

    }

  return 0;
}