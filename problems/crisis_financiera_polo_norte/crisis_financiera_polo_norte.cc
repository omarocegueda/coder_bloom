#include <algorithm>
#include <vector>
#include <iostream>

int main() {
  int P, N;
  std::cin >> P >> N;
  std::vector<int> C(N);
  for(int i=0; i<N;++i) {
    std::cin >> C[i];
  }
  std::sort(C.begin(), C.end());
  int i=0;
  int total=0;
  while(i<N && total+C[i] <= P) {
    total+=C[i];
    ++i;
  }
  std::cout << i;
  return 0;
}
