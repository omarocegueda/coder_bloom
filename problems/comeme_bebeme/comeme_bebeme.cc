#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

#define ABS(x) (((x)>=0)?(x):-(x))
const int64_t kMaxVal = 1000000000;

bool Solve(const int64_t A, const int64_t B, const int64_t C, const int64_t N) {
  assert(1<=A);
  assert(1<=B);
  assert(1<=C);
  assert(1<=N);
  assert(A<=kMaxVal);
  assert(B<=kMaxVal);
  assert(C<=kMaxVal);
  assert(N<=kMaxVal);
  return ((N-A)%std::gcd(B, C)) == 0;
}

void SolveSingle() {
  int64_t A, B, C, N;
  std::cin >> A >> B >> C >> N;
  const bool sol = Solve(A, B, C, N);
  std::cout << (sol?"SI":"NO") << std::endl;
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


void GenerateCase(const int group_index, const int group_size, const int64_t min_gcd_wanted, const int64_t max_prime_index, 
                  std::default_random_engine& generator,
                  std::uniform_int_distribution<int64_t>& distribution) {
  
  for(int case_index = 0; case_index < group_size; ++case_index) {
    const int64_t B = min_gcd_wanted * primes[distribution(generator) % max_prime_index]*primes[distribution(generator) % max_prime_index];
    const int64_t C = min_gcd_wanted * primes[distribution(generator) % max_prime_index]*primes[distribution(generator) % max_prime_index];
    const int64_t actual_gcd = std::gcd(B, C);
    assert(actual_gcd > 1);
    const bool sol_wanted = case_index % 2;
    // Decide the residual of |N-A| div gcd(B, C). If 'SI' is wanted then the residual must be zero.
    const int64_t residual = sol_wanted?0:(1 + distribution(generator)%(actual_gcd-1));
    // Decide the value of |N-A|: a multiple of gcd(B, C) plus a residual
    const int64_t delta = (distribution(generator)%(100000000/actual_gcd))*actual_gcd + residual;
    // Decide A, assuming A<=N: some small integer such that A+delta<=kMaxVal
    int64_t A = 1 + distribution(generator)%(kMaxVal-delta);
    // N is already decided, assuming A<=N.
    int64_t N = A + delta;
    // Decide whether A<=N or N<=A
    if(distribution(generator)%2) {
      std::swap(A, N);
    }
    
    std::cerr<<"A="<<A<<", B="<<B<<", C="<<C<<", N="<<N<<". Expected: "<<sol_wanted<<std::endl;
    std::cerr<<"N-A="<<N-A<<std::endl;
    std::cerr<<"gcd(B, C)="<<std::gcd(B,C)<<std::endl;
    std::cerr<<"(N-A)%%gcd(B, C)="<<(N-A)%std::gcd(B,C)<<std::endl;
    const int64_t sol = Solve(A, B, C, N);
    std::cerr<<"actual sol="<<sol<<std::endl;
    
    assert(sol==sol_wanted);
    #if 0
    // Write input
    {
      std::ostringstream os;
      os<<"group_"<<group_index<<".case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << A << " " << B << " " << C << " " << N << std::endl;
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
    #endif
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
  
  GenerateCase(5, 6, 13, 33, generator, distribution);
  GenerateCase(6, 6, 34, 47, generator, distribution);
  GenerateCase(7, 6, 42, 55, generator, distribution);
  GenerateCase(8, 6, 81, 79, generator, distribution);
  GenerateCase(9, 6, 95, 110, generator, distribution);
  //GenerateCase(6, 6, 185, 800, generator, distribution);
  //GenerateCase(7, 6, 392, 1500, generator, distribution);
  //GenerateCase(8, 6, 460, 3000, generator, distribution);
  //GenerateCase(9, 6, 871, 4000, generator, distribution);

}

int main(){
  //SolveSingle(true);
  GenerateCases();
  return 0;
}
