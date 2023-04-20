#include <stdlib.h>
#include <time.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> Solve(int C, std::vector<int>& importance) {
  std::sort(importance.rbegin(), importance.rend());
  std::vector<int> sol(C);
  for(int i=0;i<C;++i) {
    sol[i] = importance[i];
  }
  return sol;
}

void SolveSingle() {
  int C, R;
  std::cin >> C >> R;
  std::vector<int> importance(R);
  for(int i=0;i<R;++i) {
    std::cin >> importance[i];
  }
  for(const int r : Solve(C, importance)) {
    std::cout << r << " ";
  }
  std::cout << std::endl;
}

void SolveEasy() {
  int C, R;
  std::cin >> C >> R;
  std::vector<int> importance(R);
  for(int i=0;i<R;++i) {
    std::cin >> importance[i];
  }
  std::sort(importance.rbegin(), importance.rend());
  std::cout << importance[0] << std::endl;
}

void SolveMedium() {
  int C, R;
  std::cin >> C >> R;
  std::vector<int> importance(R);
  for(int i=0;i<R;++i) {
    std::cin >> importance[i];
  }
  std::sort(importance.rbegin(), importance.rend());
  std::cout << importance[0] << importance[1] << std::endl;
}


void GenerateCase(int case_index, int C, int R) {
  assert(C<=R);
  const uint32_t kMaxImportance = 10000;
  std::vector<int> input(R);
  for(int i=0;i<R;++i) {
    input[i] = 1 + rand()%kMaxImportance;
  }

  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", C, input.size());
    for(const int r : input) {
      fprintf(F, "%d ", r);
    }
    fprintf(F, "\n");
    fclose(F);
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    for(const int r : Solve(C, input)) {
      fprintf(F, "%d ", r);
    }
    fprintf(F, "\n");
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(nullptr));
  GenerateCase(0, 1, 83);
  GenerateCase(1, 1, 92);
  GenerateCase(2, 1, 134);
  GenerateCase(3, 1, 224);
  GenerateCase(4, 1, 305);
  GenerateCase(5, 1, 490);
  GenerateCase(6, 1, 512);
  GenerateCase(7, 1, 587);
  GenerateCase(8, 1, 623);
  GenerateCase(9, 1, 672);
  GenerateCase(10, 2, 446);
  GenerateCase(11, 2, 517);
  GenerateCase(12, 2, 688);
  GenerateCase(13, 2, 743);
  GenerateCase(14, 2, 967);
  GenerateCase(15, 580, 701);
  GenerateCase(16, 759, 772);
  GenerateCase(17, 834, 834);
  GenerateCase(18, 939, 989);
  GenerateCase(19, 985, 1000);
}

int main() {
  GenerateCases();
  //SolveSingle();
  return 0;
}


