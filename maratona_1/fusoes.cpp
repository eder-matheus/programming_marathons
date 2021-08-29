// fusoes - uri 2380

#include <iostream>
#include <vector>

const char FUSION = 'F';
const char QUERY = 'C';

void buildBanks(int banks_count, std::vector<int> &banks,
                std::vector<int> &bank_size) {
  banks.clear();
  bank_size.clear();

  banks.resize(banks_count);
  bank_size.resize(banks_count);
  for (int i = 0; i < banks_count; i++) {
    banks[i] = i;
    bank_size[i] = 1;
  }
}

int searchBank(int bank, std::vector<int> &banks) {
  if (bank != banks[bank]) {
    banks[bank] = searchBank(banks[bank], banks);
  }

  return banks[bank];
}

void joinBanks(int b0, int b1, std::vector<int> &banks,
               std::vector<int> &bank_size) {
  int top0 = searchBank(b0, banks);
  int top1 = searchBank(b1, banks);

  if (top0 != top1) {
    if (bank_size[top0] >= bank_size[top1]) {
      banks[top1] = top0;
      bank_size[top0] += bank_size[top1];
    } else {
      banks[top0] = top1;
      bank_size[top1] += bank_size[top0];
    }
  }
}

int main() {
  int banks_count;
  int op_count;

  std::vector<int> banks;
  std::vector<int> bank_size;

  std::cin >> banks_count >> op_count;

  buildBanks(banks_count, banks, bank_size);
  for (int i = 0; i < op_count; i++) {
    char op;
    int b0, b1;
    std::cin >> op >> b0 >> b1;
    b0--; // testcase begin in 1, not zero
    b1--; // testcase begin in 1, not zero
    if (op == FUSION) {
      joinBanks(b0, b1, banks, bank_size);
    } else if (op == QUERY) {
      if (searchBank(b0, banks) == searchBank(b1, banks)) {
        std::cout << "S\n";
      } else {
        std::cout << "N\n";
      }
    } else {
      std::cout << "[ERROR] Invalid operation\n";
    }
  }

  return 0;
}
