#include <iostream>
int64_t Solve(const int64_t N, const int64_t R, const int64_t B) { 
  return N/((B+R-1)/R);
}

int SolveSlow(const int N, const int R, const int B) {
  const int required = (B+R-1)/R; 
  for(int i=N;i>=0;--i) {
    if(i*required <= N) {
      return i;
    }
  }
  return 0;
}

int main() {
  int N, R, B;
  std::cin >> N >> R >> B;
  std::cout << SolveSlow(N, R, B) << std::endl;
  return 0;
}
