#include <iostream>
#include <vector>
#include <string>

const int64_t kMod = 1000000007;

int64_t Solve(const std::vector<std::string>& A, int N, int M) {
  std::vector<std::vector<int64_t>> C(N, std::vector<int64_t>(M));
  C[0][0] = (A[0][0] == '.');
  for(int j=1;j<M;++j) {
    C[0][j] = (A[0][j]=='.') && (C[0][j-1]>0);
  }
  for(int i=1;i<N;++i) {
    C[i][0] = (A[i][0]=='.') && (C[i-1][0]>0);
  }
  for(int i=1;i<N;++i) {
    for(int j=1;j<M;++j) {    
      if(A[i][j]=='F') {
        C[i][j] = 0;
        continue;
      }
      C[i][j] = (C[i-1][j] + C[i][j-1]) % kMod;
    }
  }
  return C[N-1][M-1];
}


int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> A(N);
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << Solve(A, N, M) << std::endl;
  return 0;
}


