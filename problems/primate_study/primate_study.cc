#include <stdlib.h>
#include <time.h>

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

uint32_t Solve(const std::vector<std::string>& map) {
  uint32_t cnt = 0;
  for(const std::string& s : map) {
    for(const char c : s) {
      cnt += (c == 'C');
    }
  }
  return cnt;
}

void SolveSingle() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> map(N);
  for(int i = 0; i < N; ++i) {
    std::cin >> map[i];
  }
  std::cout << Solve(map) << std::endl;
}

void GenerateCase(int case_index, int N, int M) {
  const uint32_t kPrimatePercent = 15;
  std::vector<std::string> input(N);
  for(std::string& s : input) {
    for(int i=0;i<M;++i) {
        const char c = (rand()%100 < kPrimatePercent)?'C':'.';
        s = s + c;  
    }
  }

  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", input.size(), input[0].size());
    for(const std::string s : input) {
      fprintf(F, "%s\n", s.c_str());
    }
    fclose(F);
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", Solve(input));
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(nullptr));
  GenerateCase(0, 1, 8);
  GenerateCase(1, 7, 9);
  GenerateCase(2, 11, 14);
  GenerateCase(3, 17, 22);
  GenerateCase(4, 19, 30);
  GenerateCase(5, 23, 44);
  GenerateCase(6, 26, 51);
  GenerateCase(7, 28, 68);
  GenerateCase(8, 39, 73);
  GenerateCase(9, 44, 96);
  GenerateCase(10, 49, 1);
  GenerateCase(11, 51, 13);
  GenerateCase(12, 58, 22);
  GenerateCase(13, 62, 38);
  GenerateCase(14, 67, 49);
  GenerateCase(15, 70, 50);
  GenerateCase(16, 75, 79);
  GenerateCase(17, 83, 86);
  GenerateCase(18, 92, 99);
  GenerateCase(19, 98,100);
}


int main() {
  SolveSingle();
  //GenerateCases();
  return 0;
}
