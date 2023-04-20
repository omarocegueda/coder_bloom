#include <iostream>
#include <sstream>
const int kMaxN = 1000;
int N, K;
int A[kMaxN]; 

bool Feasible(int P) {
  int sum = 0;
  for(int i=0;i<N;i+=K) {
    for(int j=0;j<K && i+j<N;++j) {
      sum += A[i+j];
    }
    if(sum<P) {
      return false;
    }
  }
  return true;
}

int Solve() {
  int a = 1; // P=a is feasible.
  int b = 1;
  for(int i=0; i<K;++i) {
    b += A[i];
  }
  // Now P=b is infeasible.
  
  while(a+1 < b) {
    int mid = (a + b) / 2;
    if(Feasible(mid)) {
      a = mid;
    } else {
      b = mid;
    }
  }
  return a;
}


int main() {
  std::cin >> N >> K;
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << Solve() << std::endl;
  return 0;
}
