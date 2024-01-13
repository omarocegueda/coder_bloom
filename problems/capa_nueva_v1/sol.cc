#include <cassert>
#include <iostream>
#include <vector>

int32_t Solve(const int32_t N, const int32_t M, const std::vector<std::string>& T) {
  std::vector<std::vector<int32_t>> memo(N, std::vector<int32_t>(M, 1));
  int32_t sol = 1;
  for(int i=1; i<N;++i) {
    for(int j=1; j<M; ++j) {
      if(T[i][j]!=T[i][j-1] || T[i][j]!=T[i-1][j-1] || T[i][j]!= T[i-1][j]) {
        continue;
      }
      const int32_t sub_size = std::min(memo[i][j-1], std::min(memo[i-1][j-1], memo[i-1][j]));
      memo[i][j] = std::max(memo[i][j], sub_size+1);
      sol = std::max(sol, memo[i][j]);
    }
  }
  return sol;
}


void Solve(){
  int32_t N, M;
  std::cin >> N >> M;
  std::vector<std::string> T(N); 
  for(int i=0;i<N;++i) {
    std::cin >> T[i];
  }

  std::cout << Solve(N, M, T) << std::endl;
}

int main(){
  Solve();
  return 0;
}
