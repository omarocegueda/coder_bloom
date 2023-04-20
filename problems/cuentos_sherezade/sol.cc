#include <iostream>
#include <cassert>
int64_t kMaxStories = 100;
int64_t kMaxInterest = 100;
const int64_t kMod = 1000000007;

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

int main() {
  int64_t N, A, I0, Imax;-
  std::cin >> N >> A >> I0 >> Imax;
  assert(0<=N && N <=kMaxStories);
  assert(0<=Imax && Imax <=kMaxInterest);
  assert(0<=A && A <=N);
  assert(0<=I0 && I0 <=Imax);
  std::cout << SolveDP(N, A, I0, Imax) << std::endl;  
  return 0;
}




