#include <cassert>
#include <iostream>
#include <vector>
int32_t MaxExpansion(const int32_t i, const int32_t j, const std::vector<std::string>& T, const std::vector<std::vector<int32_t>>& memo) {
  if(T[i-1][j-1] != T[i][j]) {
    return 0;
  }
  if(T[i][j-1]!=T[i-1][j]) {
    return 0;
  }
  const int32_t sub_size = std::min(memo[i][j-1], std::min(memo[i-1][j-1], memo[i-1][j]));
  if(sub_size<2) {
    return 1;
  }
  // Here, we know that the three adjacent sub-squares have non-trivial chess patterns of size at least `sub_size`
  if(T[i][j-2]!=T[i][j]) {
    return 1;
  }
  if(T[i-2][j]!=T[i][j]) {
    return 1;
  }
  if(T[i-2][j-2]!=T[i][j]) {
    return 1;
  }
  return sub_size;
}

int32_t Solve(const int32_t N, const int32_t M, const std::vector<std::string>& T) {
  std::vector<std::vector<int32_t>> memo(N, std::vector<int32_t>(M, 1));
  int32_t sol = 1;
  for(int i=1; i<N;++i) {
    for(int j=1; j<M; ++j) {
      const int32_t sub_size = MaxExpansion(i, j, T, memo);
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
