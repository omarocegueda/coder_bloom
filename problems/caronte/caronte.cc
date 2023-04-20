#include <iostream>
#include <sstream>
const int kMaxN = 1000;
int N, K;
int A[kMaxN]; 

bool Feasible(int P) {
  bool F[kMaxN+1];
  F[N] = true; // Crossing an empty set is feasible.
  for(int i=N-1;i>=0;--i) {
    int sum = 0;
    F[i] = false;
    for(int k=1;k<=K && i+k<=N;++k) {
      sum += A[i+k-1];
      if(sum >= P && F[i+k]) {
        // The group {i, i+1, ..., i+k-1} has at least P coins and 
        // the list starting at i+k is able to cross.
        F[i]  = true;
        break;
      }
    }
  }
  return F[0];
}

int Solve() {
  int a = 1; // P=a is feasible.
  int b = 1;
  for(int i=0; i<K;++i) {
    b += A[i];
  }
  // Now P=b is infeasible.
  
  while(a+1 < b) {
    int mid = (a + b) / 2;
    if(Feasible(mid)) {
      a = mid;
    } else {
      b = mid;
    }
  }
  return a;
}


void GenerateCase(int index, int N_, int K_) {
  N=N_;
  K=K_;
  for(int i=0;i<N;++i) {
    A[i] = 1 + rand()%1000; 
  }
  int sol = Solve();
  {
    std::ostringstream os;
    os << "case_" << index << ".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, K);
    for(int i=0;i<N;++i) {
      fprintf(F, "%d ", A[i]);
    }
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "case_" << index << ".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(NULL));
  GenerateCase(0, 11, 3);
  GenerateCase(1, 24, 24);
  GenerateCase(2, 38, 100);
  GenerateCase(3, 42, 31);
  GenerateCase(4, 56, 55);
  GenerateCase(5, 62, 5);
  GenerateCase(6, 71, 35);
  GenerateCase(7, 80, 41);
  GenerateCase(8, 95, 50);
  GenerateCase(9, 102, 65);
  GenerateCase(10, 118, 59);
  GenerateCase(11, 244, 120);
  GenerateCase(12, 385, 190);
  GenerateCase(13, 428, 200);
  GenerateCase(14, 572, 100);
  GenerateCase(15, 629, 210);
  GenerateCase(16, 716, 350);
  GenerateCase(17, 798, 490);
  GenerateCase(18, 950, 855);
  GenerateCase(19, 999, 500);
}

int main() {
  GenerateCases();
  return 0;
}
