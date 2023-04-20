#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

int GetMaxContentSlow(const std::vector<int>& C, const std::vector<int>&A, int target) {
  const int N = C.size();
  int total_transported = 0;
  int min_cap = C[target];
  for(int i=target-1; i >= 0; --i) {
    min_cap = std::min(min_cap, C[i]);
    total_transported+= std::min(A[i], min_cap);
  }
  min_cap = C[target];
  for(int i=target+1; i < N; ++i) {
    min_cap = std::min(min_cap, C[i]);
    total_transported+= std::min(A[i], min_cap);
  }
  return std::min(C[target], A[target] + total_transported);
}

int SolveSlow(const std::vector<int>& C, const std::vector<int>&A) {
  const int N = C.size();
  int best = 0;
  for(int target = 0; target < N; ++target) {
    best = std::max(best, GetMaxContentSlow(C, A, target));
  }
  return best;
}

int SolveWrong(const std::vector<int>& C, const std::vector<int>&A) {
  const int N = C.size();
  int target = 0;
  // Select the container with the largest content
  for(int i=1;i<N;++i) {
    if(A[target] < A[i]) {
      target = i;
    }
  }
  return GetMaxContentSlow(C, A, target);
  
}

void Generate(const int N, int case_index) {
  const int kSmallCapacity = 100;
  const int kLargeCapacity = 1000000 - kSmallCapacity;
  
  std::vector<int> C(N);
  std::vector<int> A(N);
  
  // Initialize all capacities to a small value
  for(int i=0;i<N;++i) {
    C[i] = 1+rand() % kSmallCapacity;
    A[i] = rand() % C[i];
  }
  // Increase capacity of a small number of containers
  const int new_capacity = kSmallCapacity + rand() % kLargeCapacity;
  const int new_content = 1 + rand() % new_capacity;
  int last_container = -1;
  while(last_container<N-1) {
    const int delta = 2 + rand()%4;
    last_container += delta;
    if(last_container<N) {
      C[last_container] = new_capacity;
      A[last_container] = new_content;
    }
  }
  
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", N);
    for(int i=0;i<N;++i) {
      fprintf(F, "%d ", C[i]);
    }
    fprintf(F, "\n");
    for(int i=0;i<N;++i) {
      fprintf(F, "%d ", A[i]);
    }
    fprintf(F, "\n");
    fclose(F);
  }
  {
    int correct = SolveSlow(C,A);
    int incorrect = SolveWrong(C,A);
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", correct);
    fclose(F);
    printf("%d. Correct: %d. Incorrect: %d.\n", correct==incorrect, correct, incorrect);
  }
}

void GenerateCases() {
  Generate(10, 0);
  Generate(24, 1);
  Generate(39, 2);
  Generate(43, 3);
  Generate(55, 4);
  Generate(57, 5);
  Generate(71, 6);
  Generate(85, 7);
  Generate(99, 8);
  Generate(950, 9);
  Generate(1500, 10);
  Generate(2570, 11);
  Generate(3360, 12);
  Generate(3840, 13);
  Generate(4740, 14);
  Generate(5890, 15);
  Generate(7150, 16);
  Generate(7440, 17);
  Generate(8960, 18);
  Generate(10000, 19);
}

int main() {
  srand(time(nullptr));
  GenerateCases();
  return 0;
  int N;
  scanf("%d", &N);
  std::vector<int> C(N+2, 1000000);
  std::vector<int> A(N+2, 0);
  for(int i=0;i<N;++i) {
    scanf("%d", &C[i+1]);
  }
  for(int i=0;i<N;++i) {
    scanf("%d", &A[i+1]);
  }
  const int sol = SolveSlow(C, A);
  printf("%d\n", sol);
  return 0;
}

