#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <fstream>

int Solve(const int N, const int S, std::vector<int>& C) {
  int max_c = 0;
  for(int i=0;i<N;++i) {
    max_c = std::max(max_c, C[i]);
  }
  return (max_c+S-1)/S;
}

void GenerateCase(const int32_t case_index, const int32_t N, const int32_t S, std::default_random_engine& engine) {
  std::cerr << "Generating case "<< case_index<<std::endl;
  std::uniform_int_distribution<int32_t> uniform_c(1, 1000000000);
  std::vector<int> C(N);
  for(int i=0;i<N;++i) {
    C[i] = uniform_c(engine);
  }
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    F << N<<" "<<S<<std::endl;
    for(const int32_t c : C) {
      F << c << " ";
    }
    F << std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    
    const int sol = Solve(N, S, C);
    F << sol << std::endl;
    F.close();
  }
}


void GenerateCases() {
  std::random_device rd;
  std::default_random_engine engine(rd());

  GenerateCase(0, 10, 2, engine);
  GenerateCase(1, 150, 6, engine);
  GenerateCase(2, 305, 1, engine);
  GenerateCase(3, 482, 1000, engine);
  GenerateCase(4, 591, 102, engine);
  GenerateCase(5, 691, 34, engine);
  GenerateCase(6, 710, 67, engine);
  GenerateCase(7, 811, 9, engine);
  GenerateCase(8, 943, 8, engine);
  GenerateCase(9, 1000, 15, engine);
}

void Solve() {
  int N, S;
  std::cin >> N >> S;
  int max_c = 0;
  for(int i=0;i<N;++i) {
    int c;
    std::cin >> c;
    max_c = std::max(max_c, c);
  }
  std::cout << (max_c+S-1)/S << std::endl;
}

int main() {
  GenerateCases();
  return 0;
}

