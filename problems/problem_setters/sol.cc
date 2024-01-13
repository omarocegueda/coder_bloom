#include <iostream>
#include <vector>

bool Feasible(const int64_t t, const int32_t N, const int64_t K, const std::vector<int64_t>& P) {
  int64_t extra = 0;
  int64_t needed = 0;
  for(int64_t p : P) {
    if(p<=t) {
      // we can do all p
      extra += (t-p)/K; // the reviewer has t-p extra hours to work, with that they can do (t-p)/K extra problems
    } else {
      needed += p-t;
    }
  }
  return extra >= needed;
}

int64_t Solve(const int32_t N, const int64_t K, const std::vector<int64_t>& P) {
  int64_t a = 0;
  int64_t b = P[0];
  for(int32_t i=1;i<N;++i) {
    b = std::max(b, P[i]);
  }

  while(a+1<b) {
    int64_t mid = (a+b)/2;
    if(Feasible(mid, N, K, P)) {
      b = mid;
    } else {
      a = mid;
    }
  }
  return b;
}

int main() {
  int32_t N;
  int64_t K;
  std::cin >> N >> K;
  std::vector<int64_t> P(N);
  for(int32_t i=0;i<N;++i) {
    std::cin >> P[i];
  }
  std::cout << Solve(N, K, P) <<std::endl;
  return 0;
}
