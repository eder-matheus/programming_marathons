#include <iostream>
#include <queue>
#include <map>

using namespace std;

int calcula(int num, int op)
{
    int res;
    if (op == 1)
        res = num * 2;
    else if (op == 2)
        res = num * 3;
    else if (op == 3)
        res = num / 2;
    else if (op == 4)
        res = num / 3;
    else if (op == 5)
        res = num + 7;
    else if (op == 6)
        res = num - 7;
    return res;
}

int bfs(int origem, int destino)
{
    int v, res;
    queue<int> fila;
    map<int, int> custo;

    fila.push(origem);
    custo[origem] = 1;

    if (origem == destino)
        return 1;

    while (!fila.empty())
    {
        v = fila.front();

        for (int op = 0; op < 7; op++)
        {
            res = calcula(v, op);

            if (custo[res] == 0)
            {
                custo[res] = custo[v] + 1;
                fila.push(res);
            }
        }
        if (custo[destino] > 0)
            return custo[destino];

        fila.pop();
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int saida = (bfs(n, m) - 1);
    cout << saida;
}