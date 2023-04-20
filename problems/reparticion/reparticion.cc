#include <string.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>

const int kMaxGifts = 2000;
int M[kMaxGifts+1][kMaxGifts+1];

int Solve(const int N, const std::vector<int>& A, const std::vector<int>& B) {
  memset(M, -1, sizeof(M));
  M[1][0] = B[0]; // We only have 1 gift, and A must get exactly zero gifts ==> B will get the gift.
  M[1][1] = A[0]; // We only have 1 gift, and A must get exactly one gift ==> A will get the gift.  
  for(int n=2;n<=N;++n) {
    for(int k=0;k<=n;++k) {
      // We have n gifts, and A must get exactly k of them.
      // Option 1: A gets the last gift.
      int best = -1;
      if(k>0) { // A must be forced to get at least one gift.
        assert(M[n-1][k-1] >=0 );
        const int opt1 = A[n-1] + M[n-1][k-1];
        if(best==-1 || opt1 < best) {
          best = opt1;
        }
      }
      // Option 2: B gets the last gift.
      if(k<n) { // A must not be forced to get all gifts (so we need k<n)
        assert(M[n-1][k] >=0 );
        const int opt2 = B[n-1] + M[n-1][k];
        if(best==-1 || opt2 < best) {
          best = opt2;
        }
      }
      M[n][k] = best;
    }
  }
  return M[N][N/2];
}

int SolveGreedy(const int N, const std::vector<int>& A, const std::vector<int>& B) {
  int sol = -1;
  {
    std::vector<int> idx(N);
    for(int i=0;i<N;++i) {
      idx[i] = i;
    }
    std::sort(idx.begin(), idx.end(), [&](const int& left, const int& right){ return A[left] < A[right];});
    int sum = 0;
    for(int i=0;i<N;++i) {
      if(i*2<N) {
        sum += A[idx[i]];
      } else {
        sum += B[idx[i]];
      }
    }
    sol = sum;
  }
  {
    std::vector<int> idx(N);
    for(int i=0;i<N;++i) {
      idx[i] = i;
    }
    std::sort(idx.begin(), idx.end(), [&](const int& left, const int& right){ return B[left] < B[right];});
    int sum = 0;
    for(int i=0;i<N;++i) {
      if(i*2<N) {
        sum += A[idx[i]];
      } else {
        sum += B[idx[i]];
      }
    }
    sol = std::min(sol, sum);
  }
  return sol;
}

void FindCounterExample(const int N, const std::vector<int>& A) {
  std::vector<int> idx(N);
  for(int i=0;i<N;++i) {
    idx[i] = i;
  }
  do {
    std::vector<int> B(N);
    for(int i=0;i<N;++i) {
      B[i] = A[idx[i]];
      std::cerr<<B[i] <<",";
    }
    std::cerr<<std::endl;
    const int sol_opt = Solve(N, A, B);
    const int sol_greedy = SolveGreedy(N, A, B);
    if(sol_opt != sol_greedy) {
      std::cerr << sol_opt << "!=" <<sol_greedy<<std::endl;
    }
    
  } while(std::next_permutation(idx.begin(), idx.end()));
}

void GenerateCase(int index, int N) {
  std::vector<int> A(2*N);
  std::vector<int> B(2*N);
  for(int i=0;i<2*N;++i) {
    A[i] = 1+rand()%10000;
    B[i] = 1+rand()%10000;
  }
  const int sol = Solve(2*N, A, B);
  const int greedy = SolveGreedy(2*N, A, B);
  assert(sol<greedy); 
  std::cerr << "Optimal: "<< sol << ". Greedy: "<< greedy<<std::endl;
  {
    std::ostringstream os;
    os << "case_"<<index<<".in";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", N);
    for(int i=0;i<2*N;++i) {
      fprintf(F, "%d %d\n", A[i], B[i]);
    }
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "case_"<<index<<".out";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}

void GenerateCases() {
  GenerateCase(0,  13);
  GenerateCase(1,  32);
  GenerateCase(2,  55);
  GenerateCase(3,  95);
  GenerateCase(4,  192);
  GenerateCase(5,  212);
  GenerateCase(6,  297);
  GenerateCase(7,  361);
  GenerateCase(8,  471);
  GenerateCase(9,  500);
  GenerateCase(10, 583);
  GenerateCase(11, 691);
  GenerateCase(12, 702);
  GenerateCase(13, 753);
  GenerateCase(14, 781);
  GenerateCase(15, 801);
  GenerateCase(16, 809);
  GenerateCase(17, 862);
  GenerateCase(18, 982);
  GenerateCase(19, 1000);
}


int main() {
  GenerateCases();
  return 0;
}


