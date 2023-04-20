#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

const int64_t kMaxN = 10000000;


bool SolveIncorrect(const int64_t N, const int64_t A, const int64_t B) {
  assert(N<=kMaxN);
  assert(A<=N);
  assert(B<=N);
  return N%std::__gcd(A, B) == 0;
}

bool Solve(const int64_t N, const int64_t A, const int64_t B) {
  if(A < B) {
    return Solve(N, B, A);
  }
  for(int64_t spent = 0;spent <= N; spent+=A) {
    if ((N - spent) % B) {
      continue;
    }
    return true;
  }
  return false;
}

void SolveSingle() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;
  std::cout << (Solve(N, A, B)?"SI":"NO") << std::endl;
}

int main(){
  SolveSingle();
  return 0;
}
