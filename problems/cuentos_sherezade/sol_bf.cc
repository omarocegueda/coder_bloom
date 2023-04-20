#include <iostream>
#include <cassert>
int64_t kMaxStories = 100;
int64_t kMaxInterest = 100;

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
      ++ways;
    }
  }
  return ways;
}

int main() {
  int64_t N, A, I0, Imax;
  std::cin >> N >> A >> I0 >> Imax;
  assert(0<=N && N <=kMaxStories);
  assert(0<=Imax && Imax <=kMaxInterest);
  assert(0<=A && A <=N);
  assert(0<=I0 && I0 <=Imax);
  std::cout << SolveBruteForce(N, A, I0, Imax) << std::endl;
  return 0;
}




