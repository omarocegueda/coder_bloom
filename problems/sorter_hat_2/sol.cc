#include <iostream>
#include <vector>
#include <cassert>

const int64_t kMod = 1000000007;

void Print(std::vector<int64_t>& v) {
  for(int64_t x : v) {
    if(x == 0) {
      break;
    }
    std::cout << x << ",\t";
  }
  std::cout << std::endl;
}


int64_t BinPow(int64_t x, int64_t n) {
  if(n==0) {
    return 1;
  }
  if(n==1) {
    return x;
  }
  int64_t partial = BinPow(x, n/2);
  partial = (partial * partial) % kMod;
  if(n%2==0) {
    return partial;
  }
  return (partial* x) %kMod;
} 

int64_t InvMult(int64_t x) {
  int64_t inv = BinPow(x, kMod-2);
  assert((inv * x)%kMod == 1);
  return inv;
}

int64_t Comb(int64_t N, int64_t C) {
  C = std::max(C, N-C);
  
  int64_t sol = 1;
  for(int64_t i = C+1; i<=N; ++i) {
    sol = (sol*i)%kMod;
  }
  for(int64_t i = 2; i<=N-C; ++i) {
    sol = (sol*InvMult(i))%kMod;
  }
  return sol;
}

int64_t SolveFast(int64_t N, int64_t C) {
  return Comb(N+C-1, C-1);
}

int main() {
  int64_t N, C;
  std::cin >> N >> C;
  std::cout << SolveFast(N, C) << std::endl;
  return 0;
}
