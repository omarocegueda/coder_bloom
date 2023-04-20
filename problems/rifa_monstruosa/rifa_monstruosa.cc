#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>


std::pair<int64_t, int64_t> Solve(int N, int K, const std::vector<int>& A_) {
  std::vector<int> A = A_;
  std::sort(A.begin(), A.end());
  int64_t total = 1;
  int64_t loosing = 1;
  for(int i=0;i<N;++i) {
    total *= (A[i] + (i<K)); // Total results
    loosing *= A[i]; // Results where we do not win anything.
  }
  return {total-loosing, total};
}

void GenerateCase(int index, int N, int K) {
  std::vector<int> A;
  for(int i=0;i<N;++i) {
    A.push_back(1 + rand()%10);
  }
  std::pair<int64_t, int64_t> sol = Solve(N, K, A);
  {
    std::ostringstream os;
    os << "case_"<<index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, K);
    for(int i=0;i<N;++i) {
      fprintf(F, "%d ", A[i]);
    }
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "case_"<<index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", sol.first, sol.second);
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(NULL));
  GenerateCase(0, 4, 2);
  GenerateCase(1, 5, 3);
  GenerateCase(2, 6, 4);
  GenerateCase(3, 6, 2);
  GenerateCase(4, 10, 7);
  GenerateCase(5, 10, 1);
  GenerateCase(6, 13, 9);
  GenerateCase(7, 13, 5);
  GenerateCase(8, 15, 7);
  GenerateCase(9, 15, 15);
}

int main() {
  GenerateCases();
  return 0;
  int N, K;
  std::cin >> N >> K;
  std::vector<int> A(N, 0);
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  const auto&[winning, total] = Solve(N, K, A);
  //std::cout << winning << " " << total << std::endl;
  printf("%d %d\n", winning, total);
  return 0;
}

