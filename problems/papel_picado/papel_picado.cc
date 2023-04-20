#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <sstream>
#include <stdlib.h>
#include <time.h>

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

void GenerateCase(int index, int N, int M, int D, int p) {
  std::vector<std::string> A(N, "");
  for(int i=0;i<N;++i) {
    A[i].resize(M);
    for(int j=0;j<M;++j) {
      A[i][j] = (rand()%100)<p?'X':'.';
    }
  }
  std::string fold;
  fold.resize(D);
  for(int i=0;i<D;++i) {
    fold[i] = "><V^"[rand()%4];
  }

  {
    std::ostringstream os;
    os << "case_"<<index<<".in";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, M);
    for(int i=0;i<N;++i) {
      fprintf(F, "%s\n", A[i].c_str());
    }
    fprintf(F,"%d\n%s\n", D, fold.c_str());
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "case_"<<index<<".out";
    FILE *F=fopen(os.str().c_str(), "w");
    
    int RR=N;
    int CC=M;
    for(const char c : fold) {
      UnfoldLimits(c, &RR, &CC);
    }
    for(int i=0;i<RR;++i) {
      for(int j=0;j<CC;++j) {
        Point P(i, j);
        P.Fold(RR, CC, fold);
        fprintf(F, "%c", A[P.i][P.j]);
      }
      fprintf(F, "\n");
    }
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(NULL));
  GenerateCase(0, 3, 3, 1, 50);
  GenerateCase(1, 10, 1, 4, 50);
  GenerateCase(2, 1, 10, 4, 50);
  GenerateCase(3, 8, 12, 3, 50);
  GenerateCase(4, 10, 11, 5, 20);
  GenerateCase(5, 11, 4, 6, 50);
  GenerateCase(6, 12, 7, 7, 50);
  GenerateCase(7, 13, 17, 8, 50);
  GenerateCase(8, 15, 10, 9, 50);
  GenerateCase(9, 20, 20, 10, 50);
}


int main() {
  GenerateCases();
  return 0;
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

