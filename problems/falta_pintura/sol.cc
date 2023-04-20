#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>

uint64_t Solve(const uint64_t N) {
  return N*N;
}

uint64_t SolveSlow(const int N) {
  uint64_t sol = 0;
  for(int i=0;i<N;++i) {
    sol += 2*i+1;
  }
  return sol;
}

int SolveSlowWrong(const int N) {
  int sol = 0;
  for(int i=0;i<N;++i) {
    sol += 2*i+1;
  }
  return sol;
}

void SolveSingle() {
  uint64_t N;
  std::cin >> N;
  std::cout << Solve(N) << std::endl; 
}


int main(){
  SolveSingle();
  return 0;
}
