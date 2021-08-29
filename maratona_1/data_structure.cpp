// data structure - uri 1340

#include <iostream>
#include <string>
#include <stack>
#include <queue>

#define ADD_ELEMENT 1
#define REMOVE_ELEMENT 2

int main() {
  int cmd_count;
  int cmd, param;

  while (std::cin >> cmd_count) {
    bool is_stack = true;
    bool is_queue = true;
    bool is_prior_queue = true;
    std::stack<int> stack;
    std::queue<int> queue;
    std::priority_queue<int> priority_queue;

    for (int i = 0; i < cmd_count; i++) {
      std::cin >> cmd >> param;

      if (cmd == ADD_ELEMENT) {
        stack.push(param);
        queue.push(param);
        priority_queue.push(param);
      } else if (cmd == REMOVE_ELEMENT) {
        if (stack.top() != param) {
          is_stack = false;
        }
        stack.pop();

        if (queue.front() != param) {
          is_queue = false;
        }
        queue.pop();

        if (priority_queue.top() != param) {
          is_prior_queue = false;
        }
        priority_queue.pop();
      } else {
        std::cout << "[ERROR] Invalid command\n";
        exit(1);
      }
    }
    int possible_structs = 0;
    std::string data_struct;
    if (is_stack) {
      data_struct = "stack";
      possible_structs++;
    }

    if (is_queue) {
      data_struct = "queue";
      possible_structs++;
    }

    if (is_prior_queue) {
      data_struct = "priority queue";
      possible_structs++;
    }

    if (possible_structs == 1) {
      std::cout << data_struct << "\n";
    } else if (possible_structs > 1) {
      std::cout << "not sure\n";
    } else {
      std::cout << "impossible\n";
    }
  }

  return 0;
}
