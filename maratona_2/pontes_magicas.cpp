// pontes magicas - uri 1706

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>

void dfs(int vertex, const std::vector<std::vector<int> > &graph,
         std::vector<int> &expanded, std::vector<bool> &towers) {
  expanded[vertex] = 1;
  for (int i = 0; i < graph[vertex].size(); i++) {
    int adjacent = graph[vertex][i];
    if (towers[vertex] || towers[adjacent]) {
      towers[vertex] = !(towers[vertex]);
      towers[adjacent] = !(towers[adjacent]);
    }
    if (expanded[adjacent] == 0) {
      dfs(adjacent, graph, expanded, towers);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int tower_count, bridges;
  while (std::cin >> tower_count >> bridges) {
    std::vector<std::vector<int>> graph(tower_count);
    std::vector<int> expanded(tower_count, 0);
    std::vector<bool> towers(tower_count);
    for (int i = 0; i < tower_count; i++) {
      char tower;
      std::cin >> tower;
      towers[i] = (tower == 'A') ? false : true;
    }

    for (int i = 0; i < bridges; i++) {
      int t0, t1;
      std::cin >> t0 >> t1;
      t0--;
      t1--;
      if (t0 < t1)
        graph[t0].push_back(t1);
      else
        graph[t1].push_back(t0);
    }

    std::vector<bool>::iterator it = std::find(towers.begin(), towers.end(), true);
    std::vector<int>::iterator exp_it = std::find(expanded.begin(), expanded.end(), 0);
    int vertex = it - towers.begin();
    while (vertex != -1 && vertex < towers.size()) {
      dfs(vertex, graph, expanded, towers);
      vertex = -1;
      for (int i = 0; i < towers.size(); i++) {
        if (expanded[i] == 0 && towers[i]) {
          vertex = i;
        }
      }
    }

    if (std::find(towers.begin(), towers.end(), true) == towers.end()) {
      std::cout << "Y\n";
    } else {
      std::cout << "N\n";
    }
  }

  return 0;
}
