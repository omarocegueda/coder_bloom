#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

uint64_t Solve(const uint64_t N) {
  return N*N*N - N;
}

void GenerateCase(const int case_index, const int64_t N) {
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    assert(1<=N && N<=1000);
    F << N << std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    F << Solve(N) << std::endl;
    F.close();
  }
}

void GenerateCases() {
  GenerateCase(0, 1);
  GenerateCase(1, 22);
  GenerateCase(2, 50);
  GenerateCase(3, 61);
  GenerateCase(4, 74);
  GenerateCase(5, 136);
  GenerateCase(6, 381);
  GenerateCase(7, 573);
  GenerateCase(8, 892);
  GenerateCase(9, 1000);
}

int main(){
  GenerateCases();
  return 0;
  uint64_t N;
  std::cin >> N;
  std::cout << Solve(N) << std::endl;
}


