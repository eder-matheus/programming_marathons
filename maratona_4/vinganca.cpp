// triangulo trinomial, a vinganca - uri 1807

#include <cmath>
#include <iostream>

unsigned long long solve(unsigned long long n1, unsigned long long n2, long m) {
  unsigned long long res = 1;

  while (n2 > 0) {
    if (n2 & 1)
      res = (res * n1) % m;

    n1 = (n1 * n1) % m;
    n2 = n2 >> 1;
  }

  return res;
}

int main() {
  unsigned long long R;
  std::cin >> R;
  long modulo = 2147483647;

  unsigned long long res = solve(3, R, modulo);
  std::cout << res << '\n';

  return 0;
}
