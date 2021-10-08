// canhao de destruicao - uri 1288

#include <iostream>
#include <vector>

int solution(const std::vector<int> &powers, const std::vector<int> &sizes,
             int total_size, std::vector<std::vector<int>> &table) {
  int curr = 0;
  for (int item = powers.size() - 1; item >= 0; item--) {
    curr = 1 - curr;
    for (int size = 0; size <= total_size; size++) {
      int sol = table[1 - curr][size];
      if (sizes[item] <= size &&
          sol < powers[item] + table[1 - curr][size - sizes[item]]) {
        sol = powers[item] + table[1 - curr][size - sizes[item]];
      }
      table[curr][size] = sol;
    }
  }

  return table[curr][total_size];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num_cases;
  std::cin >> num_cases;
  for (int i = 0; i < num_cases; i++) {
    int num_bullets;
    std::cin >> num_bullets;
    std::vector<int> bullet_power(num_bullets);
    std::vector<int> bullet_size(num_bullets);
    for (int b = 0; b < num_bullets; b++) {
      std::cin >> bullet_power[b] >> bullet_size[b];
    }

    int cannon_size, resistance;
    std::cin >> cannon_size >> resistance;

    std::vector<std::vector<int>> table(2);
    for (int t = 0; t < table.size(); t++) {
      table[t].resize(cannon_size + 1, 0);
    }

    int damage = solution(bullet_power, bullet_size, cannon_size, table);
    if (damage >= resistance) {
      std::cout << "Missao completada com sucesso\n";
    } else {
      std::cout << "Falha na missao\n";
    }
  }

  return 0;
}
