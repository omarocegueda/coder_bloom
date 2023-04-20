#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

uint64_t Solve(const uint64_t N) {
  return N*N;
}

uint64_t SolveSlow(const int N) {
  uint64_t sol = 0;
  for(int i=0;i<N;++i) {
    sol += 2*i+1;
  }
  return sol;
}

int SolveSlowWrong(const int N) {
  int sol = 0;
  for(int i=0;i<N;++i) {
    sol += 2*i+1;
  }
  return sol;
}

void SolveSingle() {
  uint64_t N;
  std::cin >> N;
  std::cout << Solve(N) << std::endl; 
}


void GenerateCase(const int case_index, const uint64_t N) {
  std::cerr << "Generating case "<< case_index<< std::endl;
  const int64_t expected_sol = N * N;
  std::cerr << "Correct: "<<Solve(N) << ", Slow: "<<SolveSlow(N) << ", SlowWrong: "<<SolveSlowWrong(N)<<std::endl;
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    F << N << std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    
    std::ofstream F;
    F.open (os.str());
    F << expected_sol <<std::endl;
    F.close();
  }
}

void GenerateCases() {
  srand(time(nullptr));
  GenerateCase(0,         0);
  GenerateCase(1,         1);
  GenerateCase(2,       543);
  GenerateCase(3,      1123);
  GenerateCase(4,      3231);
  GenerateCase(5,      5231);
  GenerateCase(6,      8121);
  GenerateCase(7,      9213);
  GenerateCase(8,     10000);
  GenerateCase(9,   1001001);
  GenerateCase(10,  1111111);
  GenerateCase(11,  1111231);
  GenerateCase(12,  1192312);
  GenerateCase(13,  2340922);
  GenerateCase(14,  3902302);
  GenerateCase(15,  4234902);
  GenerateCase(16,  8134210);
  GenerateCase(17, 12384028);
  GenerateCase(18, 73294022);
  GenerateCase(19,999999999);
}

int main(){
  //SolveSingle();
  GenerateCases();
  return 0;
}
