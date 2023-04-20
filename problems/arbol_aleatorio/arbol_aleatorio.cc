#include <iostream>
const int64_t a = 16807;
const int64_t b = 48271;
const int64_t c = 1;
const int64_t m = 44497;

bool Seen(int64_t n, int64_t k, int64_t root) {
  if(k==1) {
    return n==root;
  }
  int64_t left = (a * root + c) % m;
  int64_t right = (b * root + c) % m;
  return (n==root) || Seen(n, k-1, left) ||  Seen(n, k-1, right);
}

int main() {
  int64_t n, k, x1;
  std::cin >> n >> k >> x1;
  std::cout << (Seen(n, k, x1)?"Si":"No") << std::endl;
  return 0;
}
