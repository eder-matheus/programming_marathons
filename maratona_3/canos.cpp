// cortando canos - uri 1798

#include <iostream>
#include <vector>

int solutionIter(const std::vector<int> &comprimentos,
                 const std::vector<int> &valores, int tamanho,
                 std::vector<std::vector<int>> &tabela) {
  int atual = 0;
  for (int cano = comprimentos.size() - 1; cano >= 0; cano--) {
    atual = 1 - atual;
    for (int tam = 0; tam <= tamanho; tam++) {
      int solucao = tabela[1 - atual][tam];
      for (int i = 1; i * comprimentos[cano] <= tam; i++) {
        if (solucao < i * valores[cano] +
                          tabela[1 - atual][tam - i * comprimentos[cano]]) {
          solucao = i * valores[cano] +
                    tabela[1 - atual][tam - i * comprimentos[cano]];
        }
      }
      tabela[atual][tam] = solucao;
    }
  }

  return tabela[atual][tamanho];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num_canos, tamanho;
  while (std::cin >> num_canos >> tamanho) {
    std::vector<int> comprimentos(num_canos);
    std::vector<int> valores(num_canos);
    std::vector<std::vector<int>> tabela(2);
    for (int i = 0; i < tabela.size(); i++) {
      tabela[i].resize(tamanho + 1, 0);
    }
    for (int i = 0; i < num_canos; i++) {
      std::cin >> comprimentos[i] >> valores[i];
    }

    std::cout << solutionIter(comprimentos, valores, tamanho, tabela) << "\n";
  }

  return 0;
}
