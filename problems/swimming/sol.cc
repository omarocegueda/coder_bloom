#include <string.h>

#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>
const int32_t kMaxLen = 100;
const int32_t kMaxSwimmers = 15;
const int32_t kMaxSwimmerSets = 1<<kMaxSwimmers;

int32_t B[kMaxLen+1][kMaxSwimmerSets];

std::vector<int32_t> GetSynchronized(const std::vector<std::string>& M, const int32_t t, const char c) {
  std::vector<int32_t> sync;
  for(int32_t i=0;i<M.size();++i) {
    if(M[i][t] == c) {
      sync.push_back(i);
    }
  }
  return sync;
}

std::pair<int32_t, int32_t> Solve(const int32_t N, const int32_t T, const std::vector<std::string>& M) {
  memset(B, 0, sizeof(B));
  int32_t best = 0;
  int32_t best_size = 0;
  for(int32_t t=1; t<=T; ++t) {
    for(char c = 'A'; c<='Z'; ++c) {
      const std::vector<int32_t> sync = GetSynchronized(M, t-1, c);
      const uint32_t n_subsets = static_cast<uint32_t>(1)<<(sync.size());
      for(uint32_t local_subset = 0; local_subset < n_subsets; ++local_subset) {
        uint32_t subset_size = 0;
        uint32_t global_subset = 0;
        for(int i=0;i<sync.size();++i) {
          if(local_subset&(1<<i)) {
            ++subset_size;
            global_subset |= (1 << sync[i]);
          }
        }
        B[t][global_subset] = B[t-1][global_subset] + subset_size;
        if((best < B[t][global_subset]) || (best == B[t][global_subset] && best_size<subset_size)) {
          best = B[t][global_subset];
          best_size = subset_size;
        } 
      }
    }
  }
  return std::make_pair(best, best_size);
}

void Solve() {
  int32_t N, T;
  std::cin >> N >> T;
  std::vector<std::string> M(N);
  for(int32_t i=0;i<N;++i) {
    std::cin >> M[i]; 
  }
  std::pair<int32_t, int32_t> sol = Solve(N, T, M); 
  std::cout << sol.first << " " <<sol.second << std::endl;
}

int main() {
  Solve();
  return 0;
}