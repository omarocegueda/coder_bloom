#define GEN_CASES
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

int Solve(int N, int R) {
  if(N <= R) {
    return R-N+1;
  }
  return 0;
}

void GenerateCases(const int n_cases) {
  srand (time(NULL));
  for(int i=0;i<n_cases;++i) {
    int R = rand()%1000000+1;
    int N = rand()%(R+1);
    {
      std::ostringstream oss;
      oss<<"case"<<i<<".in";
      FILE *F = fopen(oss.str().c_str(),"w");
      fprintf(F, "%d %d\n", N, R);
      fclose(F);
    }
    {
      std::ostringstream oss;
      oss<<"case"<<i<<".out";
      FILE *F = fopen(oss.str().c_str(),"w");
      fprintf(F, "%d\n", Solve(N, R));
      fclose(F);
    }
  }
}

void Solve() {
  int N, R;
  scanf("%d%d", &N, &R);
  printf("%d", Solve(N, R));
}

int main(){
  //GenerateCases(20);
  Solve();
  return 0;
}

