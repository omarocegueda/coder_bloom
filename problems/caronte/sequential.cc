#include <iostream>
#include <sstream>
const int kMaxN = 1000;
int N, K;
int A[kMaxN]; 

bool Feasible(int P) {
  bool F[kMaxN+1];
  F[N] = true; // Crossing an empty set is feasible.
  for(int i=N-1;i>=0;--i) {
    int sum = 0;
    F[i] = false;
    for(int k=1;k<=K && i+k<=N;++k) {
      sum += A[i+k-1];
      if(sum >= P && F[i+k]) {
        // The group {i, i+1, ..., i+k-1} has at least P coins and 
        // the list starting at i+k is able to cross.
        F[i]  = true;
        break;
      }
    }
  }
  return F[0];
}

int Solve() {
  int b = 1;
  for(int i=0; i<K;++i) {
    b += A[i];
  }
  while(!Feasible(b)) {
    --b;
  }
  return b;
}


int main() {
  std::cin >> N >> K;
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << Solve() << std::endl;
  return 0;
}
