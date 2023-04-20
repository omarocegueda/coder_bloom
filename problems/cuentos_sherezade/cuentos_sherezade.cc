#include <stdio.h>
#include <string.h>


#include <iostream>
#include <cassert>
#include <sstream>
int64_t kMaxStories = 100;
int64_t kMaxInterest = 100;
const int64_t kMod = 1000000007;

int64_t SolveBruteForce(const int64_t N, const int64_t A, const int64_t I0, const int64_t Imax) {
  if(I0==0) {
    return 0;
  }
  int64_t ways = 0;
  for(int mask=0;mask<(1<<N); ++mask) {
    int64_t a = 0;
    for(int i=0;i<N;++i) {
      if(mask&(1<<i)) {
        ++a;
      }
    }
    if(a!=A) {
      continue;
    }
    
    int64_t I = I0;
    for(int i=0;i<N;++i) {
      if(mask&(1<<i)) {
        I = std::min(I+1, Imax);  
      } else {
        I = std::max(I-1, static_cast<int64_t>(0));
      }
      if (I<=0) {
        break;
      }
    }
    if(I>0) {
      for(int i=0;i<N;++i) {
        if(mask&(1<<i)) {
          std::cout << "^";
        }else {
          std::cout << "v";
        }
      }
      std::cout << std::endl;
      ++ways;
    }
  }
  return ways;
}

int64_t SolveDP(const int64_t N, const int64_t A, const int64_t I0, const int64_t Imax) {
  int64_t M[kMaxStories+1][kMaxStories+1][kMaxInterest+1];
  // M[n][a][i] = the number of ways to survive when `n` stories remain, `a` (`a` <= `n`) of them are interesting and current interest is `i`
  M[0][0][0] = 0;
  for(int i=1;i<=Imax;++i) {
    M[0][0][i] = 1;
  }
  
  for(int n=1; n<=N; ++n) { 
    for(int a=0; a<=n; ++a) {
      M[n][a][0] = 0;
      for(int64_t i=1; i<=Imax; ++i) {
        M[n][a][i] = 0;
        if(a > 0) { // At least one interesting story remaining
          M[n][a][i] = (M[n][a][i] + M[n-1][a-1][std::min(i+1, Imax)])%kMod; // Tell an interesting story
        }
        if (a < n) { // At least one non-interesting story remaining
          M[n][a][i] = (M[n][a][i] + M[n-1][a][std::max(i-1, static_cast<int64_t>(0))])%kMod;
        }
      }
    }
  }
  return M[N][A][I0];
}

void GenerateCase(const int32_t case_index, const int32_t N, const int32_t A, const int32_t I0, const int32_t Imax) {
  const int sol = SolveDP(N, A, I0, Imax);
  {
    std::ostringstream os;
    os << "case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d %d %d\n", N, A, I0, Imax);
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}

void GenerateCases() {
  GenerateCase(0, 20, 10, 2, 2);
  GenerateCase(1, 20, 10, 1, 2);
  GenerateCase(2, 22, 21, 1, 1);
  GenerateCase(3, 23, 23, 1, 1);
  GenerateCase(4, 19, 0, 20, 20);
  GenerateCase(5, 100, 50, 2, 2);
  GenerateCase(6, 100, 50, 1, 1);
  GenerateCase(7, 100, 99, 1, 1);
  GenerateCase(8, 100, 100, 1, 1);
  GenerateCase(9, 99, 0, 100, 100);
  
  GenerateCase(10, 10, 5, 11, 12);
  GenerateCase(11, 21, 3, 22, 32);
  GenerateCase(12, 33, 10, 30, 35);
  GenerateCase(13, 42, 12, 20, 90);
  GenerateCase(14, 55, 25, 12, 100);
  GenerateCase(15, 68, 35, 8, 10);
  GenerateCase(16, 73, 30, 30, 30);
  GenerateCase(17, 87, 55, 5, 60);
  GenerateCase(18, 91, 76, 11, 15);
  GenerateCase(19, 100, 50, 45, 88);

}


void Validate() {
  for(int n=20;n<=20;++n) {
    for(int a=0;a<=n;++a) {
      for(int imax=0;imax<=20;++imax) {
        for(int i=0;i<=imax;++i) {
          int64_t sol_dp = SolveDP(n,a,i,imax);
          int64_t sol_bf = SolveBruteForce(n,a,i,imax);
          if(sol_dp != sol_bf) {
            std::cout<<"Diff: n="<<n<<", a="<<a<<", i="<<i<<", imax="<<imax<<". DP="<<sol_dp<<". BF="<<sol_bf<<std::endl;
            return;
          }
        }
      }
    }
  }
}

int main() {
  GenerateCases();
  return 0;
  int64_t N, A, I0, Imax;
  std::cin >> N >> A >> I0 >> Imax;
  std::cout << SolveDP(N, A, I0, Imax) << std::endl;
  std::cout << SolveBruteForce(N, A, I0, Imax) << std::endl;
  
  return 0;
}




