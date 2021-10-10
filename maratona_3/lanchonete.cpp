// lanchonete - uri 2089

#include <iostream>
#include <vector>

int solucao(const std::vector<int> &moedas, int custo,
            std::vector<std::vector<int>> &tabela) {
  int atual = 0;
  for (int m = moedas.size() - 1; m >= 0; m--) {
    atual = 1 - atual;
    for (int c = 0; c <= custo; c++) {
      int sol = tabela[1 - atual][c];
      if (moedas[m] <= c &&
          sol < moedas[m] + tabela[1 - atual][c - moedas[m]]) {
        sol = moedas[m] + tabela[1 - atual][c - moedas[m]];
      }
      tabela[atual][c] = sol;
    }
  }

  return tabela[atual][custo];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int custo, num_moedas;
  while (std::cin >> custo >> num_moedas) {
    if (custo == 0 && num_moedas == 0)
      break;
    std::vector<int> moedas(num_moedas);
    for (int i = 0; i < num_moedas; i++) {
      std::cin >> moedas[i];
    }

    std::vector<std::vector<int>> tabela(2);
    for (int i = 0; i < tabela.size(); i++) {
      tabela[i].resize(custo + 1, 0);
    }

    int sol = solucao(moedas, custo, tabela);
    if (sol == custo) {
      std::cout << "sim\n";
    } else {
      std::cout << "nao\n";
    }
  }

  return 0;
}
