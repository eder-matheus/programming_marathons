// compras em fdi - uri 2531

#include <iostream>
#include <string>
#include <vector>

const int QUERY = 2;
const int CHANGE = 1;
const bool MIN = true;
const bool MAX = false;

// add struct with cheaper and most expensive price
// to avoid have two segment trees --> less runtime
struct Price {
  int cheap;
  int expensive;
};

void buildSegTree(std::vector<Price> &seg_tree, const std::vector<int> &vec,
                  int node, int begin, int end) {
  if (begin == end) {
    seg_tree[node].cheap = vec[end];
    seg_tree[node].expensive = vec[end];
  } else {
    int middle = (begin + end) / 2;
    buildSegTree(seg_tree, vec, 2 * node, begin, middle);
    buildSegTree(seg_tree, vec, 2 * node + 1, middle + 1, end);
    seg_tree[node].cheap =
        std::min(seg_tree[2 * node].cheap, seg_tree[2 * node + 1].cheap);

    seg_tree[node].expensive = std::max(seg_tree[2 * node].expensive,
                                        seg_tree[2 * node + 1].expensive);
  }
}

Price getMinMax(std::vector<Price> &seg_tree, int first, int last, int node,
                int begin, int end) {
  if (first > last) {
    Price min_max;
    min_max.cheap = std::numeric_limits<int>::max();
    min_max.expensive = -1;
    return min_max;
  }

  if (begin == first && end == last) {
    return seg_tree[node];
  }

  int middle = (begin + end) / 2;
  Price min_max_left = getMinMax(seg_tree, first, std::min(middle, last), 2 * node,
                             begin, middle);
  Price min_max_right = getMinMax(seg_tree, std::max(first, middle + 1), last,
                             2 * node + 1, middle + 1, end);

  Price min_max;
  min_max.cheap = std::min(min_max_left.cheap, min_max_right.cheap);
  min_max.expensive = std::max(min_max_left.expensive, min_max_right.expensive);

  return min_max;
}

void updateSegTree(std::vector<Price> &seg_tree, int position, int value,
                   int node, int begin, int end) {
  if (begin == end) {
    seg_tree[node].cheap = value;
    seg_tree[node].expensive = value;
  } else {
    int middle = (begin + end) / 2;
    if (position <= middle) {
      updateSegTree(seg_tree, position, value, 2 * node, begin, middle);
    } else {
      updateSegTree(seg_tree, position, value, 2 * node + 1, middle + 1, end);
    }
    seg_tree[node].cheap =
        std::min(seg_tree[2 * node].cheap, seg_tree[2 * node + 1].cheap);
    seg_tree[node].expensive = std::max(seg_tree[2 * node].expensive,
                                        seg_tree[2 * node + 1].expensive);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int stores_cnt;

  while (std::cin >> stores_cnt) {
    std::vector<int> stores(stores_cnt);
    std::vector<Price> stores_tree(4 * stores_cnt);
    for (int i = 0; i < stores_cnt; i++) {
      std::cin >> stores[i];
    }

    buildSegTree(stores_tree, stores, 1, 0, stores_cnt - 1);

    int op_count;
    std::cin >> op_count;
    for (int i = 0; i < op_count; i++) {
      int op;
      std::cin >> op;
      if (op == CHANGE) {
        int store, new_value;
        std::cin >> store >> new_value;
        store--;
        updateSegTree(stores_tree, store, new_value, 1, 0, stores_cnt - 1);
      } else {
        int first, last;
        std::cin >> first >> last;
        first--;
        last--;
        Price min_max =
            getMinMax(stores_tree, first, last, 1, 0, stores_cnt - 1);
        std::cout << min_max.expensive - min_max.cheap << "\n";
      }
    }
  }

  return 0;
}
