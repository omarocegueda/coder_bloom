#include <assert.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdint>
#include <sstream>
const int MAX_N=1000001;
const int MAX_M=10001;

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


int main(){
  int N, M;
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
  printf("%d\n", sol);
  return 0;
}

