#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

bool Solve(const int64_t N, const int64_t G, const int64_t K) {
  assert(N<=1000000000000);
  assert(G<=1000000000000);
  assert(K<=N);
  return K%std::__gcd(N, G) == 0;
}

bool SolveSlow(const int64_t N, int64_t G, int64_t K, const bool verbose=false) {
  G = G%N;
  K = K%N;
  int64_t last_broken = 0;
  
  for(int i=0;i<N;++i) {
    last_broken = (last_broken + G) % N;
    if(last_broken == K) {
      if(verbose){
        std::cerr<<"JOOG: num iterations: "<<i+1<< std::endl;
      }
      return true;
    }
  }
  if(verbose){
    std::cerr<<std::endl;
  }
  return false;
}

void SolveSingle(const bool verbose = false) {
  int64_t N, G, K;
  std::cin >> N >> G >> K;
  const bool expected = SolveSlow(N, G, K, verbose);
  const bool actual = Solve(N, G, K);
  if(expected!=actual) {
    std::cerr<<"JOOG: Failed: " << N << " " << G << " " << K << ". Expected: " << expected << ". Actual: " << actual << std::endl;
  }
  assert(actual == expected);
  std::cout << (expected?"SI":"NO") << std::endl;
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


void GenerateCase(const int group_index, const int group_size, const int64_t min_segment_size, const int64_t max_prime_index, 
                  std::default_random_engine& generator,
                  std::uniform_int_distribution<int64_t>& distribution) {
  for(int case_index = 0; case_index < group_size; ++case_index) {
    const bool sol_wanted = case_index % 2;
    
    const int64_t N = min_segment_size * primes[distribution(generator) % max_prime_index]*primes[distribution(generator) % max_prime_index];
    const int64_t G = min_segment_size * primes[distribution(generator) % max_prime_index]*primes[distribution(generator) % max_prime_index];
    const int64_t actual_segment_size = std::__gcd(N, G);
    const int64_t breakers_size = N/actual_segment_size;
    // SI: Set K as the last index being visited (the additive inverse of g mod N).
    // NO: Set K as any non-reachable integer.
    const int64_t K = sol_wanted?(N - (G%N)):(N - actual_segment_size + 1);// For "SI", consider setting K = g*(N/g)/2 (the middle, in case some one interates backwards.) 
    std::cerr << "Generating group " << group_index << ", case "<<case_index<<".(N="<<N<<",G="<<G<<",K="<<K<<". Breakers size:"<<breakers_size<<  ". Intended:"<<sol_wanted<<std::endl;
    const bool actual_sol_fast = Solve(N, G, K);
    assert(actual_sol_fast == sol_wanted);    
    #if 0
    const bool actual_sol_slow = SolveSlow(N, G, K);  
    assert(actual_sol_fast == actual_sol_slow);
    #endif
    
    // Write input
    {
      std::ostringstream os;
      os<<"group_"<<group_index<<".case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << N<<" "<<G<<" "<<K<<std::endl;
      F.close();
    }
    // Write output
    {
      std::ostringstream os;
      os<<"group_"<<group_index<<".case_"<<case_index<<".out";
      
      std::ofstream F;
      F.open (os.str());
      F << (sol_wanted?"SI":"NO")<<std::endl;
      F.close();
    }
  }
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  PrecomputePrimes();
  std::uniform_int_distribution<int64_t> distribution(0,0x0FFFFFFFFFFFFFFF);
  
  GenerateCase(0, 6, 3, 10, generator, distribution);
  GenerateCase(1, 6, 4, 11, generator, distribution);
  GenerateCase(2, 6, 5, 12, generator, distribution);
  // GenerateCase(3, 6, 57, 85, generator, distribution);
  // GenerateCase(4, 6, 100, 100, generator, distribution);
  GenerateCase(3, 6, 6, 13, generator, distribution);
  GenerateCase(4, 6, 7, 14, generator, distribution);
  
  GenerateCase(5, 6, 133, 150, generator, distribution);
  GenerateCase(6, 6, 185, 800, generator, distribution);
  GenerateCase(7, 6, 392, 1500, generator, distribution);
  GenerateCase(8, 6, 460, 3000, generator, distribution);
  GenerateCase(9, 6, 871, 4000, generator, distribution);

}

int main(){
  //SolveSingle(true);
  GenerateCases();
  return 0;
}
