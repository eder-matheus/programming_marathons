// produto do intervalo - uri 1301

#include <iostream>
#include <string>
#include <vector>

const char PRODUCT = 'P';
const char CHANGE = 'C';

void buildSegTree(std::vector<int> &seg_tree, const std::vector<int> &vec,
                  int node, int begin, int end) {
  if (begin == end) {
    seg_tree[node] = vec[end];
  } else {
    int middle = (begin + end) / 2;
    buildSegTree(seg_tree, vec, 2 * node, begin, middle);
    buildSegTree(seg_tree, vec, 2 * node + 1, middle + 1, end);
    seg_tree[node] = seg_tree[2 * node] * seg_tree[2 * node + 1];
  }
}

int getProduct(std::vector<int> &seg_tree, int first, int last, int node,
               int begin, int end) {
  if (first > last) {
    return 1;
  }

  if (begin == first && end == last) {
    return seg_tree[node];
  }

  int middle = (begin + end) / 2;
  return getProduct(seg_tree, first, std::min(middle, last), 2 * node, begin,
                    middle) *
         getProduct(seg_tree, std::max(first, middle + 1), last, 2 * node + 1,
                    middle + 1, end);
}

void updateSegTree(std::vector<int> &seg_tree, int position, int value,
                   int node, int begin, int end) {
  if (begin == end) {
    seg_tree[node] = value;
  } else {
    int middle = (begin + end) / 2;
    if (position <= middle) {
      updateSegTree(seg_tree, position, value, 2 * node, begin, middle);
    } else {
      updateSegTree(seg_tree, position, value, 2 * node + 1, middle + 1, end);
    }
    seg_tree[node] = seg_tree[2 * node] * seg_tree[2 * node + 1];
  }
}

int main() {
  int sequence_size, rounds;

  while (std::cin >> sequence_size >> rounds) {
    std::vector<int> sequence(sequence_size);
    std::vector<int> sequence_tree(4 * sequence_size);
    for (int i = 0; i < sequence_size; i++) {
      int value;
      std::cin >> value;
      if (value < 0) {
        sequence[i] = -1;
      } else if (value == 0) {
        sequence[i] = 0;
      } else {
        sequence[i] = 1;
      }
    }

    buildSegTree(sequence_tree, sequence, 1, 0, sequence_size - 1);

    for (int i = 0; i < rounds; i++) {
      char cmd;
      std::cin >> cmd;
      if (cmd == CHANGE) {
        int position, value;
        std::cin >> position >> value;
        position--;
        if (value < 0) {
          value = -1;
        } else if (value == 0) {
          value = 0;
        } else {
          value = 1;
        }
        updateSegTree(sequence_tree, position, value, 1, 0, sequence_size - 1);
      } else if (cmd == PRODUCT) {
        int first, last;
        std::cin >> first >> last;
        first--;
        last--;
        int product =
            getProduct(sequence_tree, first, last, 1, 0, sequence_size - 1);
        if (product < 0) {
          std::cout << "-";
        } else if (product == 0) {
          std::cout << "0";
        } else {
          std::cout << "+";
        }
      } else {
        std::cout << "[ERROR] Invalid command\n";
      }
    }
    std::cout << "\n";
  }

  return 0;
}
