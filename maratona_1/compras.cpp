// compras em fdi - uri 2531

#include <iostream>
#include <string>
#include <vector>

const int QUERY = 2;
const int CHANGE = 1;
const bool MIN = true;
const bool MAX = false;

void buildSegTree(std::vector<int> &seg_tree, const std::vector<int> &vec,
                  int node, int begin, int end, bool min) {
  if (begin == end) {
    seg_tree[node] = vec[end];
  } else {
    int middle = (begin + end) / 2;
    buildSegTree(seg_tree, vec, 2 * node, begin, middle, min);
    buildSegTree(seg_tree, vec, 2 * node + 1, middle + 1, end, min);
    seg_tree[node] = min ? std::min(seg_tree[2 * node], seg_tree[2 * node + 1])
                         : std::max(seg_tree[2 * node], seg_tree[2 * node + 1]);
  }
}

int getMinMax(std::vector<int> &seg_tree, int first, int last, int node,
              int begin, int end, bool min) {
  if (first > last) {
    int min_max = min ? std::numeric_limits<int>::max() : -1;
    return min_max;
  }

  if (begin == first && end == last) {
    return seg_tree[node];
  }

  int middle = (begin + end) / 2;
  int min_max =
      min ? std::min(getMinMax(seg_tree, first, std::min(middle, last),
                               2 * node, begin, middle, min),
                     getMinMax(seg_tree, std::max(first, middle + 1), last,
                               2 * node + 1, middle + 1, end, min))
          : std::max(getMinMax(seg_tree, first, std::min(middle, last),
                               2 * node, begin, middle, min),
                     getMinMax(seg_tree, std::max(first, middle + 1), last,
                               2 * node + 1, middle + 1, end, min));
  return min_max;
}

void updateSegTree(std::vector<int> &seg_tree, int position, int value,
                   int node, int begin, int end, bool min) {
  if (begin == end) {
    seg_tree[node] = value;
  } else {
    int middle = (begin + end) / 2;
    if (position <= middle) {
      updateSegTree(seg_tree, position, value, 2 * node, begin, middle, min);
    } else {
      updateSegTree(seg_tree, position, value, 2 * node + 1, middle + 1, end,
                    min);
    }
    seg_tree[node] = min ? std::min(seg_tree[2 * node], seg_tree[2 * node + 1])
                         : std::max(seg_tree[2 * node], seg_tree[2 * node + 1]);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int stores_cnt;

  while (std::cin >> stores_cnt) {
    std::vector<int> stores(stores_cnt);
    std::vector<int> min_stores_tree(4 * stores_cnt);
    std::vector<int> max_stores_tree(4 * stores_cnt);
    for (int i = 0; i < stores_cnt; i++) {
      std::cin >> stores[i];
    }

    buildSegTree(min_stores_tree, stores, 1, 0, stores_cnt - 1, MIN);
    buildSegTree(max_stores_tree, stores, 1, 0, stores_cnt - 1, MAX);

    int op_count;
    std::cin >> op_count;
    for (int i = 0; i < op_count; i++) {
      int op;
      std::cin >> op;
      if (op == CHANGE) {
        int store, new_value;
        std::cin >> store >> new_value;
        store--;
        updateSegTree(min_stores_tree, store, new_value, 1, 0, stores_cnt - 1,
                      MIN);
        updateSegTree(max_stores_tree, store, new_value, 1, 0, stores_cnt - 1,
                      MAX);
      } else if (op == QUERY) {
        int first, last;
        std::cin >> first >> last;
        first--;
        last--;
        int min =
            getMinMax(min_stores_tree, first, last, 1, 0, stores_cnt - 1, MIN);
        int max =
            getMinMax(max_stores_tree, first, last, 1, 0, stores_cnt - 1, MAX);
        std::cout << max - min << "\n";
      } else {
        std::cout << "[ERROR] Invalid operation\n";
        exit(1);
      }
    }
  }

  return 0;
}
