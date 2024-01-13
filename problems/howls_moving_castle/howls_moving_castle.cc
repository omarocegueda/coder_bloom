#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <sstream>
#include <fstream>

int32_t Solve(const int32_t N, const int32_t D, std::vector<int32_t> K) {
  std::sort(K.begin(), K.end());
  int32_t prev_door = K[0]-D-1;
  int32_t n_doors = 0;
  for(int32_t k: K) {
    if(std::abs(prev_door - k)<=D) {
      continue;
    }
    ++n_doors;
    prev_door = k + D;
  }
  return n_doors;
}

void WriteCase(const int32_t case_index, const int32_t N, const int32_t D, std::vector<int32_t> K, int32_t sol, std::default_random_engine& engine) {
  shuffle (K.begin(), K.end(), engine);
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    std::ofstream F;
    F.open (os.str());
    F<<N<<" "<<D<<std::endl;
    for(int i=0;i<N;++i) {
      F << K[i] << " ";
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
    F << sol << std::endl;
    F.close();
  }
}

void GenerateCase(const int32_t case_index, const int32_t N, const int64_t min_pos, const int64_t max_pos, std::default_random_engine& engine) {
  std::cerr << "Generating case "<< case_index<<std::endl;
  std::uniform_int_distribution<int64_t> uniform_pos(min_pos, max_pos);
  std::vector<int32_t> K(N);
  for(int i=0;i<N;++i) {
    K[i] = uniform_pos(engine);
  }

  int32_t min_d = std::numeric_limits<int32_t>::max();
  int32_t max_d = std::numeric_limits<int32_t>::min();
  std::sort(K.begin(), K.end());
  for(int i=1;i<N;++i) {
    int32_t d = K[i] - K[i-1];
    min_d = std::min(min_d, d);
    max_d = std::max(max_d, d);
  } 
  std::uniform_int_distribution<int64_t> uniform_distance(min_d, 2*max_d);
  const int32_t D = uniform_distance(engine);

  int32_t sol = Solve(N, D, K);
  std::cerr << "N="<<N <<", sol="<<sol <<std::endl;
  WriteCase(case_index, N, D, K, sol, engine); 
}


void GenerateCases() {
  std::random_device rd;
  std::default_random_engine engine(rd());

  GenerateCase(0, 10,      0, 1000, engine);
  GenerateCase(1, 50,      0, 1000, engine);
  GenerateCase(2, 100,     0, 10000, engine);
  GenerateCase(3, 250,     0, 100000, engine);
  GenerateCase(4, 500,     0, 1000000, engine);
  GenerateCase(5, 1000,    0, 1000000, engine);
  GenerateCase(6, 2000,    0, 10000000, engine);
  GenerateCase(7, 10000,   0, 1000000000, engine);
  GenerateCase(8, 100000,  0, 1000000000, engine);
  GenerateCase(9, 1000000, 0, 1000000000, engine);
}

int main() {
  GenerateCases();
  return 0;
}