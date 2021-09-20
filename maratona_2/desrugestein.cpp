// desrugestein - uri 1111

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

void floydWarshal(int dim, std::vector<std::vector<int>> &graph) {
  for (int w = 0; w < dim; w++) {
    for (int u = 0; u < dim; u++) {
      for (int v = 0; v < dim; v++) {
        if (graph[u][w] + graph[w][v] < graph[u][v]) {
          graph[u][v] = graph[u][w] + graph[w][v];
        }
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int dim;
  int north, south, west, east;
  while (std::cin >> dim) {
    if (dim == 0) {
      return 0;
    }

    std::vector<std::vector<int>> graph(dim*dim);
    for (int i = 0; i < dim * dim; i++) {
      graph[i].resize(dim * dim, INF);
      graph[i][i] = 0;
    }

    for (int i = dim - 1; i >= 0; i--) {
      for (int j = 0; j < dim; j++) {
        std::cin >> north >> south >> west >> east;
        if (north == 1) {
          graph[i * dim + j][(i + 1) * dim + j] = 1;
        }
        if (south == 1) {
          graph[i * dim + j][(i - 1) * dim + j] = 1;
        }
        if (west == 1) {
          graph[i * dim + j][i * dim + j - 1] = 1;
        }
        if (east == 1) {
          graph[i * dim + j][i * dim + j + 1] = 1;
        }
      }
    }

    floydWarshal(dim * dim, graph);

    int queries;
    std::cin >> queries;
    for (int i = 0; i < queries; i++) {
      int x0, y0, x1, y1;
      std::cin >> x0 >> y0 >> x1 >> y1;
      int p0 = x0 + (y0 * dim);
      int p1 = x1 + (y1 * dim);
      if (graph[p0][p1] != INF) {
        std::cout << graph[p0][p1] << "\n";
      } else {
        std::cout << "Impossible\n";
      }
    }
    std::cout << "\n";
  }

  return 0;
}
