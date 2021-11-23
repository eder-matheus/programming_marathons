// comparacao de substring - uri 2842

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int solution(const std::string &w1, const std::string &w2, std::vector<std::vector<int>> &table) {
  int sol = 0;

  for (int i = 0; i <= w1.size(); i++) {
    for (int j = 0; j <= w2.size(); j++) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else if (w1[i - 1] == w2[j -1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
        sol = std::max(table[i][j], sol);
      } else {
        table[i][j] = 0;
      }
    }
  }

  return sol;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string w1, w2;
  while (true) {
    std::getline(std::cin, w1);
    std::getline(std::cin, w2);
    if (!std::cin)
      break;
    std::vector<std::vector<int>> table(w1.size() + 1);
    for (std::vector<int> &v : table) {
      v.resize(w2.size() + 1, 0);
    }

    std::cout << solution(w1, w2, table) << "\n";
    table.clear();
  }

  return 0;
}
