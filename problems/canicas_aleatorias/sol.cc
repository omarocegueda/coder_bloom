#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <map>
#include <fstream>

std::pair<int, int> Solve(const int N, const int C, const int k, const std::vector<int>& v) {
  const int g = std::__gcd(N, k);
  std::map<int, int> M;
  for(int p : v) {
    M[(p-1)%g]++;
  }
  std::vector<std::pair<int, int>> counts;
  for(const auto&[mod, count] : M) {
    counts.push_back({count, mod});
  }
  std::sort(counts.rbegin(), counts.rend());
  std::pair<int, int> sol = {0,0};
  for(int i=0; i<counts.size(); ++i) {
    if(i%2==0) {
      sol.first+=counts[i].first;
    } else {
      sol.second+=counts[i].first;
    }
  }
  return sol;
}


void SolveSingle() {
  int64_t N, C, k;
  std::cin >> N >> C >> k;
  std::vector<int> v(C);
  for(int i=0;i<C;++i) {
    std::cin >> v[i];
  }
  const std::pair<int, int> actual = Solve(N, C, k, v);
  std::cout << actual.first<<" "<<actual.second<<std::endl;
}

int main(){
  SolveSingle();
  return 0;
}
