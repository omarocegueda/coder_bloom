#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <map>
#include <fstream>

int64_t Solve(const int64_t C, const int64_t N) {
  int64_t M = std::max(C, N);
  while(std::__gcd(C, M)>1) {
    ++M;
  }
  return M;
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

void GenerateCase(const int case_index, const int g, const int max_prime_index, 
                  std::default_random_engine& generator) {
  int p=0;
  {
    std::uniform_int_distribution<int64_t> distribution(0, max_prime_index-1);
    p = distribution(generator);
  }
   
  int64_t C = g * primes[p];
  int64_t N0 = g * primes[p+1];
  if(case_index%2) {
    std::swap(C, N0);
  }
  
  int64_t N = N0;
  int64_t sol = Solve(C, N);
  for(int64_t i =-std::min(C, N); i<std::max(C, N); ++i) {
    const int64_t opt = Solve(C, N0+i);
    if(opt - std::max(C, N0+i) > sol - std::max(C, N)) {
      N = N0+i;
      sol = opt;
    }
  }
  
  if(sol-std::max(C, N)<3) {
    std::swap(C, N);
  }
  
  
  std::cerr<<"JOOG: case "<<case_index<<". sorted="<<(C<=N)<<". C="<<C<<", N="<<N<<", sol="<<sol<<". Constructed diff="<<sol-std::max(C, N);
  
  
  
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    assert(1<=C && C<=10000000);
    assert(1<=N && N<=10000000);
    F << C << " " << N << std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os << "case_" << case_index << ".out";
    std::ofstream F;
    F.open (os.str());
    int64_t sol = Solve(C, N); 
    std::cerr<<". sol - max(C, N) = "<<sol-std::max(C, N) <<std::endl;
    F << sol << std::endl;
    F.close();
  }

}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  PrecomputePrimes();
  
  
  GenerateCase(0, 4, 5, generator);
  GenerateCase(1, 21, 10, generator);
  GenerateCase(2, 53, 12, generator);
  GenerateCase(3, 182, 17, generator);
  GenerateCase(4, 495, 21, generator);
  GenerateCase(5, 870, 30, generator);
  GenerateCase(6, 100, 36, generator);
  GenerateCase(7, 218, 42, generator);
  GenerateCase(8, 3756, 88, generator);
  GenerateCase(9, 6239, 91, generator);
  
  GenerateCase(10, 739, 105, generator);
  GenerateCase(11, 923, 125, generator);
  GenerateCase(12, 1242, 150, generator);
  GenerateCase(13, 2588, 175, generator);
  GenerateCase(14, 2471, 181, generator);
  GenerateCase(15, 3827, 201, generator);
  GenerateCase(16, 4351, 211, generator);
  GenerateCase(17, 6127, 221, generator);
  GenerateCase(18, 7321, 231, generator);
  GenerateCase(19, 8345, 250, generator);
}

int main() {
  GenerateCases();
  /*int64_t C, N;
  std::cin >> C >> N;
  std::cout << Solve(C, N) << std::endl;*/
  return 0;
}
