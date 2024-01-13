#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <cassert>

bool Feasible(const int64_t t, const int32_t N, const int64_t K, const std::vector<int64_t>& P) {
  // std::cerr << "Checking:"<<t<<std::endl;
  int64_t extra = 0;
  int64_t needed = 0;
  for(int64_t p : P) {
    if(p<=t) {
      // we can do all p
      extra += (t-p)/K; // the reviewer has t-p extra hours to work, with that they can do (t-p)/K extra problems
      // std::cerr << "extra="<<extra << std::endl;
    } else {
      needed += p-t;
      // std::cerr << "needed="<<needed<<std::endl;
    }
  }
  // std::cerr << ". Result: extra="<<extra<<", needed=" << needed<<std::endl;
  return extra >= needed;
}

int64_t Solve(const int32_t N, const int64_t K, const std::vector<int64_t>& P) {
  int64_t a = 0;
  int64_t b = P[0];
  for(int32_t i=1;i<N;++i) {
    b = std::max(b, P[i]);
  }

  while(a+1<b) {
    int64_t mid = (a+b)/2;
    if(Feasible(mid, N, K, P)) {
      b = mid;
    } else {
      a = mid;
    }
  }
  return b;
}


void GenerateCase(const int32_t case_index, const int32_t N, const int64_t K, std::default_random_engine& engine, const int64_t min_problems, const int64_t max_problems) {
  std::cerr << "Generating Random Case: "<<case_index <<std::endl;
  std::uniform_int_distribution<int64_t> uniform_num_problems(min_problems, max_problems);
  std::vector<int64_t> P(N);
  for(int32_t i=0; i<N; ++i) {
    P[i] = uniform_num_problems(engine);
  }
  const int64_t sol = Solve(N, K, P);
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    std::ofstream F;
    F.open (os.str());
    F << N << " " << K << std::endl;
    for(const int64_t& p : P) {
      F << p << " ";
    }
    F << std::endl;
    F.close();
  }

  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open(os.str());
    F << sol << std::endl;
    F.close();
  }
}

void GenerateCases() {
  std::random_device device;
  std::default_random_engine engine(device());
  GenerateCase(0,  10,     1,   engine, 0, 10);
  GenerateCase(1,  1000,   100, engine, 1, 1000000);
  GenerateCase(2,  2000,   88,  engine, 1, 10000000);
  GenerateCase(3,  5000,   50,  engine, 1, 100000000);
  GenerateCase(4,  8500,   25,  engine, 1, 1000000000);
  GenerateCase(5,  10000,  90,   engine, 1, 1000000000);
  GenerateCase(6,  12500,  17,   engine, 1, 1000000000);
  GenerateCase(7,  15000,  29,   engine, 1, 1000000000);
  GenerateCase(8,  17500,  55,   engine, 1, 1000000000);
  GenerateCase(9,  20000,  18,  engine, 1, 1000000000);
}

void Solve() {
  int32_t N;
  int64_t K;
  std::cin >> N >> K;
  std::vector<int64_t> P(N);
  for(int32_t i=0;i<N;++i) {
    std::cin >> P[i];
  }
  std::cout << Solve(N, K, P) <<std::endl;
}

int main() {
  GenerateCases();
  return 0;
}