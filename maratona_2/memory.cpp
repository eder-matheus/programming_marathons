#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

#define MAXN 100100
#define INF 0x3f3f3f3f

typedef pair<int, int> dupla; // define uma dupla de inteiros a ser usada no heap
vector< dupla > grafo[MAXN]; // define o grafo por lista de adjacência

int predecessor[MAXN]; // define a o predecessor de cada vértice no caminho desde a fonte
int custos[MAXN];      // indica o custo do menor caminho encontrado para cada vértice

void dijkstra(int fonte)
{
    priority_queue< dupla, vector<dupla>, greater<dupla> > heap; // heap mínimo
    int adicionado[MAXN];                                                     // indica se o vértice foi adicionado ao corte que contém a fonte
    heap.push(make_pair(1, fonte));                                      // adiciona o vértice inicial no heap
    while (!heap.empty())
    {                                    // executa até ter todos vértices com o caminho mínimo calculado
        int vertice = heap.top().second; // seleciona o vértice do topo
        heap.pop();                      // elimina o topo
        adicionado[vertice] = 1;         //faz com que o vértice entre no corte que contém a fonte
        for (int i = 0; i < grafo[vertice].size(); i++)
        {                                             //Percorre os adjacentes
            int adjacente = grafo[vertice][i].second; // identifica o adjacente
            if (adicionado[adjacente] == 0 && 
                (custos[adjacente] < grafo[vertice][i].first * custos[vertice]))
            {
                custos[adjacente] = grafo[vertice][i].first * custos[vertice];
                heap.push(std::make_pair(custos[adjacente], adjacente)); // insere a dupla no heap
                predecessor[adjacente] = vertice;                        // atualiza o predecessor do adjacente.
            }
        }
    }
}
int main() {
    int n, m, a, b, p;
    cin >> n >> m; 
    for (int k = 0; k<m; k++){
        cin >> a >> b;
        p = 
        grafo[a].push_back(std::make_pair(1, b)); // Adiciona b como adjacente de a no grafo
        grafo[b].push_back(std::make_pair(1, a));
    }
    int fonte = 1;
    predecessor[fonte] = fonte; // O predecessor da fonte é ele próprio
    dijkstra(fonte);

    for (int i = 1; i <= n; i++) {
        int j = i;
        printf("Custo: %f, Caminho: %d", custos[j]*100, j);
        while(j != 1 && j!=0) {
            j = predecessor[j]; // Se movimenta para o predecessor
            printf(" <-- %d", j);
        }
        printf("\n");
    }

    printf("%.6f percent\n", (double)custos[n]*100);
    return 0;
}