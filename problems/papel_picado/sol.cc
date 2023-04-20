#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const char LEFT = '<';
const char RIGHT = '>';
const char TOP = '^';
const char BOTTOM = 'V';

void FoldLimits(const char fold, int*R, int*C) {
  if(fold==LEFT || fold==RIGHT) {
    *C /= 2;
  }
  if(fold==TOP || fold==BOTTOM) {
    *R /= 2;
  }
}

void UnfoldLimits(const char fold, int*R, int*C) {
  if(fold==LEFT || fold==RIGHT) {
    *C *= 2;
  }
  if(fold==TOP || fold==BOTTOM) {
    *R *= 2;
  }
}

struct Point {
  int i, j;
  Point(int i_, int j_){
    i=i_;
    j=j_;
  }
  
  void Fold(int R_, int C_, char fold) {
    int R = R_ / 2;
    int C = C_ / 2;
    switch(fold) {
      case RIGHT:
        if(j < C) {
          j = C - 1 - j;
        } else {
          j -= C;
        }
      break;
      case LEFT:
        if(j >= C) {
          j = C-1-(j-C);
        }
      break;
      case BOTTOM:
        if(i<R) {
          i = R - 1 - i;
        } else {
          i -= R;
        }
      break;
      case TOP:
        if(i>=R) {
          i = R - 1 - (i-R);
        }
      break;
    }
  }
  
  void Fold(const int R_, const int C_, const std::string& fold) {
    int R = R_;
    int C = C_;
    for(const char f : fold) {
      Fold(R, C, f);
      FoldLimits(f, &R, &C);
    }
  }
};

int main() {
  int R, C, N;
  std::string fold;
  
  std::cin >> R >> C;
  std::vector<std::string> F(R,"");
  for(int i=0;i<R;++i) {
    std::cin >> F[i];
  }
  std::cin >> N;
  std::cin >> fold;
  
  int RR=R;
  int CC=C;
  for(const char c : fold) {
    UnfoldLimits(c, &RR, &CC);
  }
  for(int i=0;i<RR;++i) {
    for(int j=0;j<CC;++j) {
      Point P(i, j);
      P.Fold(RR, CC, fold);
      std::cout << F[P.i][P.j];
    }
    std::cout << std::endl;
  }
  return 0;
}

