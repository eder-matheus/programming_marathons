#include <cstdio>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
 
int main() {
    int qtd_vagoes;
    int array[5000];

    while((cin >> qtd_vagoes) && qtd_vagoes > 0) {
        while((cin >> array[0]) && array[0]) {
            stack<int> pilha;
            int vagao_atual = 0;

            for(int i = 1; i < qtd_vagoes; i++)
                cin >> array[i];
            for(int i = 1; i <= qtd_vagoes; i++) {
                pilha.push(i);
                while((pilha.size() > 0) && (array[vagao_atual] == pilha.top())) {
                    vagao_atual += 1;
                    pilha.pop();
                }
            }
            if (pilha.size() == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}