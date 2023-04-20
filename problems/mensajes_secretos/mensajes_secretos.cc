#include <iostream>
#include <vector>
const int64_t kMod = 29;
int Pow(const int64_t x, const int64_t n) {
  if(n==0) {
    return 1;
  }
  if(n==1) {
    return x;
  }
  int64_t y = Pow(x, n/2);
  if(n&1) {
    return (y*y*x)%kMod;
  }
  return (y*y)%kMod;
}

void Solve(const std::vector<int64_t>& P, const int64_t a) {
  for(int64_t p : P) {
    int m = Pow(a, p);
    std::cout << char('A' + char(m - 2));
  }
  std::cout << std::endl;
}

int main() {
  int64_t n, a;
  std::cin >> n >> a;
  std::vector<int64_t> P(n);
  for(int i=0;i<n;++i) {
    std::cin >> P[i];
  }
  Solve(P, a);
  return 0;
}
