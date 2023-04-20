#include <string>
#include <iostream>

const int64_t kMaxN = 1000; 
const int64_t kMaxM = 1000;

int64_t N, M;
std::string A[kMaxN+1];
std::string T[kMaxN+1];

int64_t SolveSlow() {
  int64_t min_dist = -1;
  for(int i=0; i<N;++i) {
    for(int j=0;j<M;++j) {
      if(T[i][j] == 'T') {
        int64_t opt = 0; 
        for(int ii=0;ii<N;++ii) {
          for(int jj=0;jj<M;++jj) {
            if(A[ii][jj] == 'A') {
              opt += std::abs(i-ii)+std::abs(j-jj);
            }
          }
        }
        if(min_dist <0 || opt < min_dist) {
          min_dist = opt;
        }
      }
    }
  }
  return min_dist;
}

int main() {
  std::cin >> N >> M;
  for(int i=0; i<N;++i) {
    std::cin >> A[i];
  }
  for(int i=0; i<N;++i) {
    std::cin >> T[i];
  }
  std::cout << SolveSlow() << std::endl;
  return 0;
}

