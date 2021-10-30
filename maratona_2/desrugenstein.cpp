#include <iostream>
#include <vector>

#define MAXN 2000
#define INF 99999999

using namespace std;

int grafo[MAXN][MAXN];// matriz de adjacência do grafo (se o arco não existir o valor é INF)
int custos[MAXN][MAXN];// custo do caminho de u (linha) ate v (coluna)

void floyd_warshall(int n) {
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            custos[u][v] = grafo[u][v]; // o custo inicial de u até v é o da aresta
    
    for (int w = 0; w < n; w++) { // percorre cada possível vértice intermediário
        for (int u = 0; u < n; u++) { // percorre cada possível origem do caminho
            for (int v = 0; v < n; v++ ) { // percorre cada possível destino do caminho
                if(custos[u][w] + custos[w][v] < custos[u][v])
                    custos[u][v] = custos[u][w] + custos[w][v]; // atualiza o custo
            }
        }
    }
}

int main()
{
    int n, u, v, z, w;
    while(cin >> n)
    {
        if (n==0)
            return 0;
        
        for (int i=0; i < n*n; i++){
            grafo[i][i] = 0;
            for (int j=0; j < n*n; j++)
                grafo[i][j] = INF;
        }
        
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < n; j++)
            {
                cin >> u >> v >> z >> w;
                int x = i*n+j;
                if (u == 1) grafo[x][((i+1)*n)+j] = 1;
                if (v == 1) grafo[x][((i-1)*n)+j] = 1;
                if (z == 1) grafo[x][(i*n)+j-1] = 1;
                if (w == 1) grafo[x][(i*n)+j+1] = 1;
            }

        floyd_warshall(n*n);

        int p;
        cin >> p;
        for (int c=0; c<p; c++){
            cin >> u >> v >> z >> w;
            u += v * n;
            z += w * n;
            if (custos[u][z] != INF) 
                cout << custos[u][z] << "\n";
            else 
                cout << "Impossible" << "\n";
        }
    }
}