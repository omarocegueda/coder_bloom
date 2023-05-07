#include <iostream>
#include <vector>
int main() {
  int N, S;
  std::cin >> N >> S;
  std::vector<int> A(N);
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  for(int mask = 0; mask<(1<<N); ++mask) {
    int sum = 0;
    for(int i=0;i<N;++i) {
      if(mask&(1<<i)) {
        sum += A[i];
      }
    }
    if(sum == S) {
      for(int i=0;i<N;++i) {
        if(!(mask&(1<<i))) {
          std::cout << A[i] << " ";
        }
      }
      std::cout << std::endl;
      return 0;
    }
  }
  return 0;
}