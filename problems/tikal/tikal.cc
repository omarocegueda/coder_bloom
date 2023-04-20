#include <iostream>

int A[100][100];
int I[100][100];
int r,c;

int Bin(int v) {
  return v>=250;
}

int Eval(int i, int j) {
  if(i<0 || j<0) {
    return 0;
  }
  return I[i][j];
}

void PrecomputeIntegral() {
  I[0][0] = A[0][0];
  for(int j=1;j<c;++j) {
    I[0][j] = I[0][j-1] + A[0][j]; 
  }

  for(int i=1;i<r;++i) {
    I[i][0] = I[i-1][0] + A[i][0];
    for(int j=1;j<c;++j) {
      I[i][j] = I[i-1][j] + I[i][j-1] - I[i-1][j-1] + A[i][j]; 
    }
  }
}

int GetIntegral(int i, int j, int ii, int jj) {
  return Eval(ii, jj) - Eval(i-1, jj) - Eval(ii, j-1) + Eval(i-1, j-1);  
}

int GetArea(int i, int j, int ii, int jj) {
  return (ii - i + 1) * (jj - j + 1);
}

int Solve() {
  int sol = 0;
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      for(int ii=i;ii<r;++ii) {
        for(int jj=j;jj<c;++jj) {
          int integral = GetIntegral(i, j, ii, jj);
          int area = GetArea(i,j,ii,jj);
          if(2 * integral >= area) {
            sol = std::max(sol, area);
          }
        }
      }
    }
  }
  return sol;
}


int main() {
  std::cin >> r>>c;
  for(int i=0;i<r;++i) {
    for(int j=0;j<c;++j) {
      std::cin >> A[i][j];
      A[i][j] = Bin(A[i][j]);
    }
  }
  PrecomputeIntegral();
  std::cout << Solve() << std::endl;
  return 0;
}

