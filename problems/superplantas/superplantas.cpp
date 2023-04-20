#include <iostream>
#include <vector>
int Solve(const int N, const int C, int L,
          const std::vector<int>& T, const std::vector<int>& A) {
  int absorved = 0;
  for (int i=N-1; i>=0; --i) {
    if(L >= T[i]) {
      const int days = (L - T[i] + 1 + (C -1)) / C;
      L -= days * C;
      absorved += days * A[i];
    }
  }
  return absorved;
}

int main() {
  int N, C, L;
  std::cin >> N >> C >> L;
  std::vector<int> T(N);
  std::vector<int> A(N);
  for(int i=0;i<N;++i) {
    std::cin >> T[i] >> A[i];
  }
  std::cout << Solve(N, C, L, T, A) << std::endl;
  return 0;  
}
