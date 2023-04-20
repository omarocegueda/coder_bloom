#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
const int DRow[4] = {-1, 0, 1, 0};
const int DCol[4] = {0, 1, 0, -1};

int ConsumeRegion(std::vector<std::string>& A, int r, int c) {
  if(r<0 || c<0 || r>=A.size() || c>=A[0].size()) {
    return 0;
  }
  if(A[r][c] != 'C') {
    return 0;
  }
  A[r][c] = '.';
  int consumed = 1;
  for(int dir = 0; dir<4;++dir) {
    consumed += ConsumeRegion(A, r+DRow[dir], c+DCol[dir]);
  }
  return consumed;
}

int Solve(const std::vector<std::string>& A_in) {
  std::vector<std::string> A = A_in;
  int max_size = 0;
  for(int i=0;i<A.size();++i) {
    for(int j=0;j<A[0].size();++j) {
      int opt = ConsumeRegion(A, i, j);
      if(opt > max_size) {
        max_size = opt;
      }
    }
  }
  return max_size;
}

void SolveSingle() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> A(N, std::string(M,'.'));
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << Solve(A) << std::endl;
}

void Expand(std::vector<std::string>& A, int r, int c, int depth) {
  if(depth <=0) {
    return;
  }
  if(r<0 || c<0 || r>=A.size() || c>=A[0].size()) {
    return;
  }
  if(A[r][c] != '.') {
    return;
  }
  A[r][c] = 'C';
  for(int dir = 0; dir<4;++dir) {
    bool do_expand = rand()%100 < 50;
    if(do_expand) {
      Expand(A, r+DRow[dir], c+DCol[dir], depth-1);
    }  
  }
}


void GenerateCase(int case_index, int N, int M, int n_regions, int depth) {
  std::vector<std::string> A(N, std::string(M,'.'));
  for(int i=0;i<n_regions;++i) {
    int r =rand() % N;
    int c =rand() % M;
    Expand(A, r, c, depth);
  }
  const int max_size = Solve(A);
  for(int i=0;i<N;++i) {
    printf("%s\n", A[i].c_str());
  } 
  printf("MaxSize=%d", max_size);
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE* F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, M);
    for(int i=0;i<N;++i) {
      fprintf(F, "%s\n", A[i].c_str());
    }
    fclose(F);
  }
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE* F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", max_size);
    fclose(F);
  }
}


void GenerateCases() {
  srand(time(NULL));
  GenerateCase(0, 10, 10, 3, 3);
  GenerateCase(1, 10, 10, 3, 5);
  GenerateCase(2, 20, 15, 4, 4);
  GenerateCase(3, 20, 15, 4, 7);
  GenerateCase(4, 17, 21, 5, 4);
  GenerateCase(5, 17, 21, 5, 6);
  GenerateCase(6, 32, 35, 6, 5);
  GenerateCase(7, 32, 35, 6, 9);
  GenerateCase(8, 43, 39, 10, 8);
  GenerateCase(9, 43, 39, 10, 12);
  GenerateCase(10, 55, 61, 13, 7);
  GenerateCase(11, 55, 61, 13, 20);
  GenerateCase(12, 65, 57, 20, 8);
  GenerateCase(13, 65, 57, 20, 21);
  GenerateCase(14, 70, 81, 200, 3);
  GenerateCase(15, 1, 81, 15, 30);
  GenerateCase(16, 85, 1, 10, 20);
  GenerateCase(17, 85, 78, 30, 40);
  GenerateCase(18, 97, 88, 25, 15);
  GenerateCase(19, 97, 88, 25, 42);
}

int main() {
  GenerateCases();
  return 0;
}
