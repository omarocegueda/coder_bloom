#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

std::vector<std::vector<int64_t>> C;
void PrecomputePascalTriangle(const int N) {
  if(N<0) {
    return;
  }
  C.resize(N+1);
  C[0] = {1};
  if(N<1) {
    return;
  }
  C[1] = {1, 1};
  if(N<2) {
    return;
  }
  for(int n=2; n<=N; ++n) {
    C[n].resize(n+1);
    C[n][0] = C[n][n] = 1;
    for(int k=1; k<n; ++k) {
      C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
  }
}

// Returns the k-th combination, in lexicographical order, of N=last-first+1 elements choose M. 
void GetCombination(const int first, const int last, const int M, const int64_t k, int *out) {
  const int N = last - first + 1;
  assert(1 <= N && N <= 60);
  assert(1 <= M && M <= N);
  assert(1 <= k && k <=C[N][M]);
  if(k==1) {
    for(int i=0;i<M;++i){
      out[i] = first + i;
    }
    return;
  }
  if(k <= C[N-1][M-1]) {
    // The first C[N-1][M-1] combinations contain `first` as first element.
    out[0] = first;
    GetCombination(first+1, last, M-1, k, out+1);
    return;
  } else {
    // Discard the first C[N-1][M-1] combinations. The next C[N-1][M] combinations do not contain `first`.
    return GetCombination(first+1, last, M, k - C[N-1][M-1], out);
  }
}

void Solve(const int N, const int M, const int64_t k) {
  int *combination = new int[M];
  GetCombination(1, N, M, k, combination);
  for(int i=0;i<M;++i) {
    std::cout << combination[i] << " ";
  }
  std::cout << std::endl;
  delete[] combination;
}

void GenerateCases() {
  PrecomputePascalTriangle(60);
  auto engine = std::default_random_engine(time(nullptr));
  std::cerr<<"C[60][30]=" << C[60][30]<< std::endl;
  std::uniform_int_distribution<int64_t> distribution(1, C[60][30]);
  
  auto generate_case = [&](const int case_index, const int N){
    const int M = 1 + distribution(engine) % N;
    const int64_t k = 1 + distribution(engine) % C[N][M];
    int *combination = new int[M];
    std::cerr << N<<", "<<M<<", "<<k<<std::endl;
    GetCombination(1, N, M, k, combination);
    // Write input
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << N<<" "<<M<<" "<<k<<std::endl;
      F.close();
    }
    // Write output
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".out";
      
      std::ofstream F;
      F.open (os.str());
      for(int i=0;i<M;++i) {
        F << combination[i] << " ";
      }
      F << std::endl;
      F.close();
    }
    delete[] combination;
  };
  
  generate_case(0, 5);
  generate_case(1, 8);
  generate_case(2, 12);
  generate_case(3, 17);
  generate_case(4, 30);
  generate_case(5, 39);
  generate_case(6, 42);
  generate_case(7, 47);
  generate_case(8, 53);
  generate_case(9, 60);
}

int main() {
  GenerateCases();
  return 0;
  int N, M;
  int64_t k;
  std::cin >> N >> M >> k;
  PrecomputePascalTriangle(N);
  Solve(N, M, k);
  return 0;
}
