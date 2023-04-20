#include <assert.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>
#include <sstream>
const int MAX_N=1000001;
const int MAX_M=10001;

int SolveFast(int M, int B[], int N, int A[]){
  int lookup[MAX_M];
  for(int i=0;i<M;++i) {
    lookup[B[i]] = i;
  }
  int32_t longest = 0;
  for(int i=0;i<N;++i) {
    int j=lookup[A[i]];
    int32_t opt = 0;
    int ii = i;
    while(j<M && ii<N && B[j]==A[ii]){
      ++opt;
      ++j;
      ++ii;
    }
    longest = std::max(opt, longest);
  }
  return longest;
}

int SolveSlow(int M, int B[], int N, int A[]){
  int32_t longest = 0;
  for(int i=0;i<N;++i) {
    int j=0;
    while(B[j]!=A[i]){
      ++j;
    }
    int32_t opt = 0;
    int ii=i;
    while(j<M && ii<N && B[j]==A[ii]){
      ++opt;
      ++j;
      ++ii;
    }
    longest = std::max(opt, longest);
  }
  return longest;
}

void Generate(int case_index, const int m, const int n) {
  assert(m>1);
  assert(n>1);
  // Generate a random permutation.
  int perm[MAX_M];
  for(int i=0;i<m;++i) {
    perm[i] = i;
  }
  for(int i=0;i<m;++i) {
    const int j = i+rand()%(m-i);
    std::swap(perm[i], perm[j]);
  }
  
  // Initialize with a valid schedule. 
  int schedule[MAX_N];
  for(int i=0;i<n;++i) {
    schedule[i] = rand()%m;
  }
  // Override multiple times with a subarray of perm.
  for(int r=0;r<10;++r) {
    const int len = rand()%(std::min(m, n)/2);
    const int p0 = rand()%(1+m-len);
    const int s0 = rand()%(1+n-len);
    for(int i=0;i<len;++i) {
      schedule[s0+i] = perm[p0+i];
    }
  }
  
  // Write to text file.
  std::ostringstream input_filename;
  input_filename<<"case_"<<case_index<<".in";
  FILE *F = fopen(input_filename.str().c_str(), "w");
  fprintf(F, "%d\n", m);
  for(int i=0;i<m;++i){
    fprintf(F, "%d ", perm[i]);
  }
  fprintf(F, "\n%d\n", n);
  for(int i=0;i<n;++i){
    fprintf(F, "%d ", schedule[i]);
  }
  fprintf(F, "\n");
  fclose(F);
  
  // Solve.
  int sol = SolveFast(m, perm, n, schedule);
  std::ostringstream output_filename;
  output_filename << "case_" <<case_index<<".out";
  F=fopen(output_filename.str().c_str(), "w");
  fprintf(F, "%d\n", sol);
}

void GenerateCases() {
  srand(time(NULL));
  Generate(0,  10,    20);
  Generate(1,  20,    10);
  Generate(2,  15,    30);
  Generate(3,  30,    15);
  Generate(4,  20,    50);
  Generate(5,  50,    20);
  Generate(6,  100,   300);
  Generate(7,  300,   100);
  Generate(8,  1000,  5000);
  Generate(9,  5000,  1000);
  Generate(10, 100,   10000);
  Generate(11, 300,   50000);
  Generate(12, 500,   100000);
  Generate(13, 1000,  500000);
  Generate(14, 2000,  600000);
  Generate(15, 3000,  700000);
  Generate(16, 5000,  800000);
  Generate(17, 7000,  900000);
  Generate(18, 9000,  950000);
  Generate(19, 10000, 1000000);
}

int main(){
  GenerateCases();
  /*int N, M;
  int A[MAX_N];
  int B[MAX_M];
  int ret=scanf("%d", &M);
  for(int i=0;i<M;++i){
    ret=scanf("%d", &B[i]);
  }
  ret=scanf("%d", &N);
  for(int i=0;i<N;++i){
    ret=scanf("%d", &A[i]);
  }
  int sol = SolveSlow(M, B, N, A);
  printf("%d\n", sol);*/
  return 0;
}

