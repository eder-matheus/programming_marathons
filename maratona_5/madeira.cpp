// especies de madeira - uri 1260

#include <iostream>
#include <map>
#include <cstring>
#include <iomanip>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::fixed << std::setprecision(4);
  
  int num_tests;
  std::string buf;
  std::cin >> num_tests;
  getline(std::cin, buf);
  getline(std::cin, buf);

  std::map<std::string, int> num_trees;
  for (int i = 0; i < num_tests; i++) {
    std::string input;
    while (true) {
      getline(std::cin, input);
      if (input.length() == 0 || !std::cin)
        break;
      num_trees[input]++;
    }
    int total_trees = 0;
    for (const auto &[key, value] : num_trees) {
      total_trees += value;
    }
    for (const auto &[key, value] : num_trees) {
      std::cout << key << " " << ((float)value/total_trees) * 100 << "\n";
    }
    if (i < num_tests - 1)
      std::cout << "\n";
    num_trees.clear();
  }

  return 0;
}
