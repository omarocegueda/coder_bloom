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

inline int32_t BitCount(uint32_t x) {
  int32_t cnt = 0;
  while(x) {
    cnt+=(1&x);
    x>>=1;
  }
  return cnt;
}

std::string PrintSubset(const uint32_t mask) {
  std::ostringstream os;
  os << "["<<mask<<"]"<<"{";
  for(int i=0;i<kMaxSwimmers;++i) {
    if(mask&(static_cast<uint32_t>(1)<<i)) {
      os << i <<" ";
    }
  }
  os << "}";
  return os.str();
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
        const uint32_t subset_size = BitCount(local_subset);
        uint32_t global_subset = 0;
        for(int i=0;i<N;++i) {
          if(local_subset&(1<<i)) {
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

void Print(const std::vector<std::string>& A) {
  for(const std::string&s : A) {
    std::cerr << s << std::endl;
  }
}

void WriteCase(const int32_t case_index, const int32_t N, const int32_t T, const std::vector<std::string>& M) {
  {
    // Write input 
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    std::ofstream F;
    F.open(os.str());
    F << N << " "<<T<< std::endl;
    for(const std::string& s : M) {
      F << s << std::endl;
    }
    F.close();
  }
  const std::pair<int32_t, int32_t> sol = Solve(N, T, M);
  {
    // Write output
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open(os.str());
    F << sol.first <<" "<<sol.second <<std::endl;
    F.close();
  }

}

std::vector<int32_t> RandomPermutation(const int32_t N, const int32_t k, std::default_random_engine& generator) {
  assert(k<=N);
  assert(k>=1);
  std::vector<int32_t> perm(N);
  for(int i=0;i<N;++i) {
    perm[i] = i;
  }
  std::vector<int32_t> ret(k);
  for(int i=0;i<k;++i) {
    std::uniform_int_distribution<int32_t> uniform(i,N-1);
    const int32_t r = uniform(generator);
    assert(r>=0);
    assert(r<N);
    std::swap(perm[i], perm[r]);
    ret[i] = perm[i];
  }
  return ret;
}

void MutateSubset(const std::vector<int32_t>& swimmers, const int32_t start, const int32_t end, std::default_random_engine& generator,
                  std::vector<std::string>& M) {
  std::uniform_int_distribution<char> uniform_char('A', 'Z');
  for(int t=start; t<=end; ++t) {
    const char c = uniform_char(generator);
    for(int i=0;i<swimmers.size();++i) {
      M[swimmers[i]][t] = c;
    }
  }
}

void GenerateCase(const int32_t case_index, const int32_t N, const int32_t T, const int32_t min_sync_swimmers, const int32_t min_sync_segment,
                  std::default_random_engine& generator) {
  std::cerr << "Generating case "<< case_index<<std::endl;
  assert(min_sync_swimmers <= N);
  assert(min_sync_segment <= T);
  std::uniform_int_distribution<char> uniform_char('A', 'Z');
  std::uniform_int_distribution<int32_t> uniform_swimmer(0,N-1);
  std::uniform_int_distribution<int32_t> uniform_time(0,T-1);
  std::vector<std::string> M(N, std::string(T, 'A'));
  for(int i=0;i<N;++i) {
    for(int j=0;j<T;++j) {
      M[i][j] = uniform_char(generator);
    }
  }
  // Synchronize a few smaller random subsets
  const int32_t kNumIter = 10;
  for(int iter = 0; iter < kNumIter; ++iter) {
    const int32_t small_subset_size = 1 + uniform_swimmer(generator);
    std::vector<int32_t> perm = RandomPermutation(N, small_subset_size, generator);
    assert(min_sync_segment/2>0);
    const int seg_size=uniform_time(generator)%(min_sync_segment/2);
    assert(T-seg_size > 0);
    const int seg_start = uniform_time(generator)%(T-seg_size);
    const int seg_end = seg_start + seg_size;
    MutateSubset(perm, seg_start, seg_end, generator, M);
  }
  // Select a subset of synchronized swimmers
  std::vector<int32_t> perm = RandomPermutation(N, min_sync_swimmers, generator);
  assert(T-min_sync_segment>0);
  const int seg_start = uniform_time(generator)%(T-min_sync_segment);
  const int seg_end = seg_start + min_sync_segment;
  MutateSubset(perm, seg_start, seg_end, generator, M);
  WriteCase(case_index, N, T, M); 
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());

  GenerateCase(0, 6, 10, 2, 6, generator);
  GenerateCase(1, 7, 20, 6, 8, generator);
  GenerateCase(2, 8, 30, 5, 14, generator);
  GenerateCase(3, 9, 50, 3, 20, generator);
  GenerateCase(4, 10, 60, 9, 40, generator);
  GenerateCase(5, 11, 70, 3, 60, generator);
  GenerateCase(6, 12, 85, 8, 40, generator);
  GenerateCase(7, 13, 90, 11, 55, generator);
  GenerateCase(8, 14, 95, 10, 40, generator);
  GenerateCase(9, 15, 100, 12, 85, generator);
  GenerateCase(10, 15, 100, 13, 85, generator);
  GenerateCase(11, 15, 100, 14, 85, generator);
  GenerateCase(12, 15, 100, 15, 85, generator);
  GenerateCase(13, 15, 100, 10, 85, generator);
  GenerateCase(14, 15, 100, 9, 85, generator);
  GenerateCase(15, 15, 100, 8, 85, generator);
  GenerateCase(16, 15, 100, 7, 85, generator);
  GenerateCase(17, 15, 100, 6, 85, generator);
  GenerateCase(18, 15, 100, 5, 85, generator);
  GenerateCase(19, 15, 100, 4, 85, generator);

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
  GenerateCases();
  return 0;
}