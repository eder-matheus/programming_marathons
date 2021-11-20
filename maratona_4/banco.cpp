// fila do banco - uri 1537

#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  unsigned long long fatorial[100002];
  int n;

  fatorial[3] = 1;
  for (int i = 4; i <= 100000; i++)
    fatorial[i] = (i * fatorial[i - 1]) % 1000000009;

  while (std::cin >> n) {
    if (n == 0) {
      break;
    }

    std::cout << fatorial[n] << "\n";
  }

  return 0;
}