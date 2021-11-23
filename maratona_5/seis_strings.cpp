// seis strings - uri 2017

#include <iostream>
#include <string>

int main() {
  int n = 0;
  int most_equal_chars = 0;
  int pos = 0;

  std::string str_x, other_strings;
  std::cin >> str_x >> n;

  for (int j = 1; j <= 5; j++) {
    std::cin >> other_strings;
    int curr_string_eq_chars = 0;
    for (int i = 0; i < str_x.size(); i++) {
      if (str_x[i] == other_strings[i]) {
        curr_string_eq_chars++;
      }
    }
    if (curr_string_eq_chars > most_equal_chars) {
      most_equal_chars = curr_string_eq_chars;
      pos = j;
    }
  }

  if (n > str_x.size()) {
    std::cout << 1 << "\n";
    std::cout << str_x.size() <<"\n";
  } else {
    if ((str_x.size() - most_equal_chars) <= n) {
      std::cout << pos << "\n";
      std::cout << str_x.size() - most_equal_chars << "\n";
    } else {
      std::cout <<"-1\n";
    }
  }

  return 0;
}
