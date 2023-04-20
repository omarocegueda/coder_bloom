#include<iostream>
const int kMaxN = 1001;
const int kMod = 1000000007;

int64_t Choose(int n, int k) {
  int64_t M[2][kMaxN];
  M[1][0] = M[1][1] = 1;
  int done = 1;
  for(int i=2;i<=n;++i) {
    int current = 1-done;
    M[current][0] = M[current][i] = 1;
    for(int j=1; j<i; ++j) {
      M[current][j] = (M[done][j-1] + M[done][j]) % kMod;
    }
    done = current;
  }
  return M[done][k];
}

int main() {
  int M, N;
  std::cin >> M >> N;
  std::cout << Choose(M, N) << std::endl;
  return 0;
}
