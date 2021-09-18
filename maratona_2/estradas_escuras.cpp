
#include <iostream>
#include <map>
#include <queue>
#include <list>

#define MAXN 100100

using namespace std;
typedef pair<int, pair<int, int> > aresta; // define a aresta

priority_queue< aresta, vector <aresta> , greater<aresta> > heap; // heap mínimo
list< pair<int, int> > arvore;// define a árvore como uma lista de arestas

int cjt[MAXN]; // conjunto do elemento i
int n[MAXN]; // quantidade de elementos no conjunto

void initialize() { //função que inicializa o conjunto disjunto
    for(int i = 0; i < MAXN; i++) {
        cjt[i] = i; // inicialmente o elemento está no conjunto que só o contem
        n[i] = 1; // inicialmente o conjunto somente tem um elemento
    }
}

int find(int i) { // função que procura o conjunto em que está um elemento
    if(i != cjt[i]) // verifica se é o topo do conjunto
        cjt[i] = find(cjt[i]); // se não for o topo procura o topo e comprime caminho
    return cjt[i]; // retorna o topo do conjunto
}

void join(int i, int j) { // função que une os conjuntos de dois elementos
    int si = find(i), sj = find(j); // procura o topo dos conjuntos de i e j
    if(si != sj) { // somente une se estiverem em conjuntos diferentes
        if(n[si] >= n[sj]) { // coloca o de menor quantidade no de maior
            cjt[sj] = si; // sj não é mais topo, agora o topo dele é si
            n[si] += n[sj]; // atualiza a quantidade no topo
        } else {
            cjt[si] = sj; // si não é mais topo, agora o topo dele é sj
            n[sj] += n[si]; // atualiza a quantidade no topo
        }
    }
}

int kruskal(int n) {
    int total = 0;
    initialize(); // inicia o conjunto disjunto (cada vértice separado)
    while (n > 1) { // enquanto houver mais de uma componente
        int u = heap.top().second.first; // seleciona o primeiro vértice da aresta
        int v = heap.top().second.second; // seleciona o segundo vértice da aresta
        int w = heap.top().first;
        heap.pop(); // elimina o topo
        if (find(u) != find(v)) { // se os vértices estão em componentes diferentes os une
            n--;
            arvore.push_back(make_pair(u, v)); // coloca a aresta na árvore
            join(u, v); // une as componentes pela aresta entre eles
            total += w;
        }
    }
    return total;
}

int main() {
    int n, m;
    while (true){
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        int total = 0;
        int x,y,z;
        for(int i=0; i< m; i++){
            cin >> x >> y >> z;
            heap.push(make_pair(z, make_pair(x, y)));// Adiciona a aresta ao heap
            total += z;
        }
        
        int res = kruskal(n);

        cout << total-res << "\n";
    }

    return 0;
}