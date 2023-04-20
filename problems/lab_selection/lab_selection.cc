#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>

int64_t SolveSlow(const std::vector<std::string>& A) {
  std::vector<std::pair<int, int>> labs;
  for(int i=0;i<A.size();++i) {
    for(int j=0;j<A[0].size();++j) {
      if(A[i][j]=='L') {
        labs.push_back({i, j});
      }
    }
  }
  assert(!labs.empty());
  int64_t best = -1;
  std::pair<int, int> best_lab = {-1, -1};
  for(const std::pair<int, int>& lab : labs) {
    int64_t dist = 0;
    for(int i=0;i<A.size();++i) {
      for(int j=0;j<A[0].size();++j) {
        if(A[i][j]=='C') {
          dist += std::abs(i-lab.first) + std::abs(j-lab.second);
        }
      }
    }
    if(best == -1 || dist < best) {
      best = dist;
      best_lab = lab;
    }
  }
  return best;
}


int64_t SolveFast(const std::vector<std::string>& A) {
  std::vector<int> Nv(A.size());
  std::vector<int> Nh(A[0].size());
  std::vector<std::vector<uint64_t>> sol(A.size(), std::vector<uint64_t>(A[0].size(), 0));
  // Precompute Nv
  std::cerr << "JOOG: 1" <<std::endl;
  int64_t c_count = 0;
  for(int j=0; j < A[0].size(); ++j) {
    if(A[0][j] == 'C') {
      ++Nv[0];
      ++c_count;
      sol[0][0] += j; // Manhattan distance from (0, 0) to (0, j)
    }
  }
  std::cerr << "JOOG: 2" <<std::endl;
  for(int i=1; i < A.size(); ++i) {
    Nv[i] = Nv[i-1];
    for(int j=0; j < A[0].size(); ++j) {
      if(A[i][j] == 'C') {
        ++Nv[i];
        ++c_count;
        sol[0][0] += i + j; //Manhattan distance from (0, 0) to (i, j)
      }
    }
  }
  std::cerr << "JOOG: 3" <<std::endl;
  // Precompute Nh
  for(int i=0;i<A.size();++i) {
    Nh[0] += (A[i][0] == 'C');
  }
  for(int j=1;j<A[0].size();++j) {
    Nh[j] = Nh[j-1];
    for(int i=0;i<A.size();++i) {
      Nh[j] += (A[i][j]=='C');
    }
  }
  std::cerr << "JOOG: 4" <<std::endl;
  // DP. First row.
  for(int j=1; j<A[0].size(); ++j) {
    sol[0][j] = sol[0][j-1] + Nh[j-1] - (c_count - Nh[j-1]);
  }
  std::cerr << "JOOG: 5" <<std::endl;
  // FP. Rest of rows.
  for(int i=1;i<A.size();++i) {
    for(int j=0; j<A[0].size(); ++j) {
      sol[i][j] = sol[i-1][j] + Nv[i-1] - (c_count - Nv[i-1]);
    }
  }
  std::cerr << "JOOG: 6" <<std::endl;
  
  int64_t best = -1;
  for(int i=0;i<A.size();++i) {
    for(int j=0;j<A[0].size();++j) {
      if(A[i][j] != 'L') {
        continue;
      }
      if(best == -1 || sol[i][j]<best) {
        best = sol[i][j];
      }
    }
  }
  std::cerr << "JOOG: 7" <<std::endl;
  return best;
}

void SolveSingle() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> A(N, std::string(M, '.'));
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << SolveSlow(A) << std::endl;
}

void GenerateCase(int case_index, int N, int M, int pc, int pl) {
  std::vector<std::string> A(N, std::string(M, '.'));
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      if(1 + rand()%100 <= pc) {
        A[i][j] = 'C';
      }
    }
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      if(1 + rand()%100 <= pl) {
        A[i][j] = 'L';
      }
    }
  }
  int64_t expected = SolveSlow(A);
  int64_t actual = SolveFast(A);
  if(N<50 && M<50) {
  // Print to stdout for visualization purposes.
    for(const std::string& s : A) {
      std::cout << s << std::endl;
    }
  }
  
  std::cout << "Expected: " << expected << ". Actual: "<< actual << std::endl;

  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, M);
    for(const std::string& s : A) {
      fprintf(F, "%s\n", s.c_str());
    }
    fclose(F);
  }
  
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", expected);
    fclose(F);
  }

}

void GenerateCases() {
  srand(time(NULL));
  GenerateCase(0, 10, 10, 1, 1);
  GenerateCase(0, 50, 50, 100, 50);
  GenerateCase(0, 100, 100, 100, 50);
}


int main() {
  //SolveSingle();
  GenerateCases();
  return 0;
}

