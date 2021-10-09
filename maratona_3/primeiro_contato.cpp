// primeiro contato - uri 1970

#include <algorithm>
#include <iostream>
#include <vector>

int solucao(const std::vector<int> &musicas, int tamanho,
            std::vector<std::vector<int>> &tabela, std::vector<bool> &usadas) {
  for (int item = musicas.size() - 1; item >= 0; item--) {
    for (int tam = 0; tam <= tamanho; tam++) {
      int sol = tabela[item + 1][tam];
      if (musicas[item] <= tam && !usadas[item] &&
          sol < musicas[item] + tabela[item + 1][tam - musicas[item]]) {
        sol = musicas[item] + tabela[item + 1][tam - musicas[item]];
      }
      tabela[item][tam] = sol;
    }
  }

  // percorre a tabela na direcao contraria ao seu preenchimento
  // para verificar quais itens foram usados na solucao otima
  int i = 0;
  int j = tamanho;
  while (i < musicas.size() && j >= 0) {
    if(tabela[i][j] != tabela[i+1][j]) {
      usadas[i] = true;
      j = j - musicas[i];
      i = i + 1;
    }
    else {
      i = i + 1;
    }
  }

  return tabela[0][tamanho];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num_musicas, num_cartuchos;
  std::cin >> num_musicas >> num_cartuchos;
  std::vector<int> musicas(num_musicas);
  std::vector<int> cartuchos(num_cartuchos);
  std::vector<int> combinacoes(num_cartuchos);

  for (int i = 0; i < num_musicas; i++) {
    std::cin >> musicas[i];
  }

  for (int i = 0; i < num_cartuchos; i++) {
    std::cin >> cartuchos[i];
    combinacoes[i] = i;
  }

  int sol = -1;
  do {
    std::vector<bool> usadas(num_musicas, false);
    int temp = 0;
    for (int i = 0; i < num_cartuchos; i++) {
      std::vector<std::vector<int>> tabela(num_musicas + 1);
      for (int t = 0; t < tabela.size(); t++) {
        tabela[t].resize(51, 0);
      }
      temp += solucao(musicas, cartuchos[combinacoes[i]], tabela, usadas);
    }
    sol = std::max(sol, temp);
  } while (std::next_permutation(combinacoes.begin(), combinacoes.end()));

  std::cout << sol << "\n";

  return 0;
}
