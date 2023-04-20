#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

void GenerateCase(const int case_index,
                  std::default_random_engine& generator,
                  std::uniform_int_distribution<int64_t>& distribution) {
  const int64_t A = distribution(generator) % 1000000000;
  const int64_t B = distribution(generator) % 1000000000;    
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    F << A << " " << B << std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    
    std::ofstream F;
    F.open (os.str());
    F << "NO EXISTE" << std::endl;
    F.close();
  }
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int64_t> distribution(0,0x0FFFFFFFFFFFFFFF);
  for(int i=0;i<10;++i) {
    GenerateCase(i, generator, distribution);
  }
}

int main(){
  GenerateCases();
  return 0;
}
