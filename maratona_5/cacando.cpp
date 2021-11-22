#include <stdio.h>
#include <iostream>
#include <stdlib.h>

long mdc(unsigned long n1, unsigned long n2) {
  unsigned long r = n1 % n2;
  while (r != 0) {
    n1 = n2;
    n2 = r;
    r = n1 % n2;
  }
  return n2;
}

int main() {
  unsigned long res = 1;
  int buraco, num_buracos;
  int buracos_vector[105];

  std::cin >> num_buracos;

  for (int i = 1; i <= num_buracos; i++)
    std::cin >> buracos_vector[i];
    
  for (int i = 1; i <= num_buracos; i++){
    int t = 1;
    buraco = buracos_vector[i];

    while (buraco != i) {
      t++;
      buraco = buracos_vector[buraco];
    }
    res = (res / mdc(res, t)) * t;
  }
  std::cout << res << "\n";

  return 0;
}
