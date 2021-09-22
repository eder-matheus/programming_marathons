// jogo da memoria - uri 1928

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

int dfs(int vertex, const std::vector<std::vector<int>> &graph,
        std::vector<int> &expanded, std::vector<int> &cards, int distance) {
  int dist = distance;
  expanded[vertex] = 1;
  for (int i = 0; i < graph[vertex].size(); i++) {
    int adjacent = graph[vertex][i];
    if (expanded[adjacent] == 0) {
      dist++;
      dfs(adjacent, graph, expanded, cards, dist);
    }
  }
  return dist;
}

int bfsForDistance(int source, int target, const std::vector<std::vector<int>> &graph,
                   std::vector<int> &cards) {
  std::list<int> expand;
  std::vector<int> expanded(cards.size(), 0);
  std::vector<int> distance(graph.size(), 0);

  expand.push_back(source);
  expanded[source] = 1;
  distance[source] = 0;
  while (!expand.empty()) {
    int v = expand.front();
    expand.pop_front();
    for (int i = 0; i < graph[v].size(); i++) {
      int adj = graph[v][i];
      if (expanded[adj] == 0) {
        expand.push_back(adj);
        expanded[adj] = 1;
        distance[adj] = distance[v] + 1;
        if (cards[adj] == card) {
          target = adj;
          break;
        }
      }
    }
  }

  return distance[target];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num_cards;
  std::cin >> num_cards;

  std::vector<vector<int>> cards(num_cards/2);
  std::vector<std::vector<int>> graph(num_cards);

  for (int i = 0; i < num_cards; i++) {
    int c;
    std::cin >> c;
    c--;
    cards[c].push_back(i);
  }

  for (int i = 0; i < num_cards - 1; i++) {
    int p0, p1;
    std::cin >> p0 >> p1;
    p0--;
    p1--;
    graph[p0].push_back(p1);
    graph[p1].push_back(p0);
  }

  int points = 0;
  for (int i = 0; i < cards.size(); i++) {
    std::vector<int>::iterator it = std::find(cards.begin(), cards.end(), i);
    int source = it - cards.begin();
    points += bfsForDistance(source, graph, cards);
  }

  std::cout << points << "\n";

  return 0;
}
