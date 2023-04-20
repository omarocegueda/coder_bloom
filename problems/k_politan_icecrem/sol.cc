#include <iostream>

int64_t SolveFast(int64_t N, int64_t K) {
  if(K==1) {
    return N;
  }
  int64_t n = K;
  int64_t n_choose_k = 1;
  while(n_choose_k < N) {
    ++n;
    n_choose_k = (n_choose_k*n)/(n-K);
  } 
  return n;
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::cout << SolveFast(N, K) <<std::endl;
  return 0;
}
