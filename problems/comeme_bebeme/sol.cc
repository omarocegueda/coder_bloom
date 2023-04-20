#include <numeric>
#include <iostream>
#include <cassert>

const int64_t kMaxVal = 1000000000;

bool Solve(const int64_t A, const int64_t B, const int64_t C, const int64_t N) {
  assert(1<=A);
  assert(1<=B);
  assert(1<=C);
  assert(1<=N);
  assert(A<=kMaxVal);
  assert(B<=kMaxVal);
  assert(C<=kMaxVal);
  assert(N<=kMaxVal);
  return ((N-A)%std::gcd(B, C)) == 0;
}

int main(){
  int64_t A, B, C, N;
  std::cin >> A >> B >> C >> N;
  const bool sol = Solve(A, B, C, N);
  std::cout << (sol?"SI":"NO") << std::endl;
  return 0;
}

