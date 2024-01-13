#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <sstream>
#include <fstream>

int32_t StrengthNeeded(const int32_t N, const int32_t K, const std::vector<int32_t>& R, const int32_t P) {
  assert(0<=P && P<R.size());
  int32_t g = std::__gcd(N, K);
  int32_t min_resistance = std::numeric_limits<int32_t>::max();
  for(int i=0, p=P; i<N; ++i, p=(p+g)%N) {
    min_resistance = std::min(min_resistance, R[p]);
  }
  return min_resistance + 1;
}

std::vector<int32_t> SolveSlow(const int32_t N, const int32_t K, const std::vector<int32_t>&R, const int32_t M, const std::vector<int32_t>& P) {
  std::vector<int32_t> S(M);
  for(int32_t j=0; j<M; ++j) {
    S[j] = StrengthNeeded(N, K,  R, P[j]);
  }
  return S;
}

std::vector<int32_t> SolveFast(const int32_t N, const int32_t K, const std::vector<int32_t>&R, const int32_t M, const std::vector<int32_t>& P) {
  // Precompute minimum resistance per group.
  int32_t g = std::__gcd(N, K);
  std::vector<int32_t> min_resistance(g, std::numeric_limits<int32_t>::max());
  for(int i=0;i<N;++i) {
    const int32_t r = i%g;
    min_resistance[r] = std::min(min_resistance[r], R[i]);
  }

  // Lookup solutions.
  std::vector<int32_t> S(M);
  for(int32_t j=0; j<M; ++j) {
    S[j] = 1 + min_resistance[P[j]%g];
  }
  return S;
}

void Solve() {
  int32_t N, K;
  std::cin >> N >> K;
  std::vector<int32_t> R(N);
  for(int32_t i=0; i<N; ++i) {
    std::cin >> R[i];
  }
  int32_t M;
  std::cin >> M;
  std::vector<int32_t> P(M);
  for(int32_t j=0; j<M;++j) {
    std::cin >> P[j];
    --P[j];
  }
  std::vector<int32_t> sol = SolveFast(N, K, R, M, P);
  for(const int32_t s : sol) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}


const uint32_t kMaxNumPrimes = 10000;
uint64_t primes[kMaxNumPrimes];
int n_primes;

void PrecomputePrimes() {
  primes[0] = 2;
  primes[1] = 3;
  n_primes = 2;
  for(uint64_t q=5; n_primes<kMaxNumPrimes; q+=2) {
    bool is_prime = true;
    for(int i=1; primes[i]*primes[i]<=q; ++i) {
      if(q % primes[i] == 0) {
        is_prime = false;
        break;
      }
    }
    if(is_prime) {
      primes[n_primes] = q;
      ++n_primes;
    }
  }
  std::cout<< "Num primes:"<<n_primes<<". Last prime: "<<primes[n_primes-1]<<std::endl;
}


void GenerateCase(int32_t case_index, int32_t g, const int max_prime_index, const int32_t game_percent, std::default_random_engine& engine) {
  std::cerr << "Generating case "<< case_index<<std::endl;
  int p=0;
  {
    std::uniform_int_distribution<int32_t> distribution(0, max_prime_index-1);
    p = distribution(engine);
  }
  // Select K and N such that gcd(N, K)=g
  const int K = g * primes[p];
  const int N = g * primes[p+1];
  const int M = (N*game_percent)/100;
  std::cerr << "N="<<N<<", K="<<K<<", M="<<M<<", prime["<<p<<"]="<<primes[p]<<std::endl;
  std::vector<int32_t> R(N);
  std::uniform_int_distribution<int32_t> random_resistance(1, 1000000000);
  for(int i=0;i<N;++i) {
    R[i] = random_resistance(engine);
  }

  // Select starting point for each game instance
  std::vector<int32_t> P(M);
  std::uniform_int_distribution<int32_t> random_position(0, N-1);
  for(int i=0;i<M;++i) {
    P[i] = random_position(engine);
  }


  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    F << N<<" "<<K<<std::endl;
    for(const int32_t r : R) {
      F << r << " ";
    }
    F << std::endl;
    F << M <<std::endl;
    for(const int32_t p : P) {
      // Input positions are 1-based
      F << p+1 << " ";
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
    
    const std::vector<int32_t> sol_fast = SolveFast(N, K, R, M, P);
    //const std::vector<int32_t> sol_slow = SolveSlow(N, K, R, M, P);
    for(int32_t j=0; j<M; ++j) {
      //assert(sol_fast[j] == sol_slow[j]);
      F << sol_fast[j] << " ";
    }
    F << std::endl;
    F.close();
  }
}

void GenerageCases() {
  std::random_device rd;
  std::default_random_engine engine(rd());
  PrecomputePrimes();

  GenerateCase(0, 4, 5, 90, engine);
  GenerateCase(1, 21, 10, 90, engine);
  GenerateCase(2, 53, 12, 90, engine);
  GenerateCase(3, 182, 17, 90, engine);
  GenerateCase(4, 495, 21, 90, engine);
  GenerateCase(5, 870, 30, 90, engine);
  GenerateCase(6, 1008, 20, 80, engine);
  GenerateCase(7, 2185, 15, 90, engine);
  GenerateCase(8, 3596, 13, 95, engine);
  GenerateCase(9, 4262, 9, 100, engine);
  
  /*GenerateCase(10, 75392, 105, 2572, engine);
  GenerateCase(11, 94231, 125, 4295, engine);
  GenerateCase(12, 102412, 150, 8298, engine);
  GenerateCase(13, 235828, 175, 17324, engine);
  GenerateCase(14, 284721, 181, 35912, engine);
  GenerateCase(15, 328217, 201, 72324, engine);
  GenerateCase(16, 483571, 211, 142932, engine);
  GenerateCase(17, 611217, 221, 278123, engine);
  GenerateCase(18, 793261, 231, 578125, engine);
  GenerateCase(19, 893425, 250, 994639, engine);*/
}

int main() {
  // Solve();
  GenerageCases();
  return 0;
}

