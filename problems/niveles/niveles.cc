
#include <iostream>
const int kMaxScore = 100000;
int32_t best[2][kMaxScore+1];

void Precompute() {
  best[0][0] = 0;
  best[1][0] = 0;
  for(int score=1;score<=kMaxScore;++score) {
    best[0][score] = best[0][score-1];
    best[1][score] = best[1][score-1];
    int a = 1;
    int b = 0;
    for(int s=score; s>0; s/=10) {
      int d = s%10;
      a *= d;
      b += d*d;
    }
    
    if(a > b) {
      best[0][score] += 1;
    } else if (b > a) {
      best[1][score] += 1;
    }
  }
}

int main() {
  Precompute();
  int N;
  std::cin >> N;
  for(int i=0;i<N;++i) {
    int a, b;
    std::cin >> a >> b;
    std::cout << (best[1][b] - best[1][a-1]) << " " << (best[0][b] - best[0][a-1]) << std::endl;
  }
  return 0;
}