#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

void Fill(std::vector<std::string>& dest, const char c,
          const std::size_t i0, const std::size_t j0,
          const std::size_t i1, const std::size_t j1) {
  for(std::size_t i=i0;i<i1;++i) {
    for(std::size_t j=j0;j<j1;++j) {
      dest[i][j] = c;
    }
  }
}

void Solve(const std::size_t N, std::vector<std::string>& dest, const std::size_t i0, std::size_t j0) {
  if(N==1) {
    dest[i0][j0] = '.';
  } else {
    const uint64_t k = N/3;
    
    for(int ii=0;ii<3;++ii) {
      for(int jj=0; jj<3;++jj) {
        if(ii==1 && jj==1) {
          Fill(dest, 'X', i0+k, j0+k, i0+2*k, j0+2*k);
        } else {
          Solve(k, dest, i0+ii*k, j0+jj*k);
        }
      }
    }
  }
}


void GenerateCase(const int case_index, const std::size_t N) {
  std::cerr << "Generating case "<< case_index<< std::endl;
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
    std::vector<std::string> sol(N, std::string(N, ' '));
    Solve(N, sol, 0, 0);
    for(int i=0;i<sol.size();++i) {
      F << sol[i] <<std::endl;  
    }
    F.close();
  }
}

void GenerateCases() {
  srand(time(nullptr));
  GenerateCase(0, 1);
  GenerateCase(1, 3);
  GenerateCase(2, 9);
  GenerateCase(3, 27);
  GenerateCase(4, 81);
  GenerateCase(5, 243);
  GenerateCase(6, 729);
}

int main(){
  //SolveSingle();
  GenerateCases();
  return 0;
}
