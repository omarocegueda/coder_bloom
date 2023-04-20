#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>

const int64_t kMaxN = 10000000;


bool SolveIncorrect(const int64_t N, const int64_t A, const int64_t B) {
  return N%std::__gcd(A, B) == 0;
}

bool Solve(const int64_t N, const int64_t A, const int64_t B) {
  if(A < B) {
    return Solve(N, B, A);
  }
  for(int64_t spent = 0;spent <= N; spent+=A) {
    if ((N - spent) % B) {
      continue;
    }
    return true;
  }
  return false;
}

void SolveSingle(const bool verbose = false) {
  int64_t N, A, B;
  std::cin >> N >> A >> B;
  std::cout << (Solve(N, A, B)?"SI":"NO") << std::endl;
}













const uint32_t kMaxNumPrimes = 200001;
uint64_t primes[kMaxNumPrimes];
int n_primes;

void PrecomputePrimes() {
  primes[0] = 2;
  primes[1] = 3;
  n_primes = 2;
  int last_reported=0;
  for(uint64_t q=5; n_primes<kMaxNumPrimes; q+=2) {
    if(n_primes%1000000==0 && last_reported!=n_primes) {
      last_reported=n_primes;
      std::cerr << "JOOG: Precomputing primes...primes["<<n_primes-1<<"]=" << primes[n_primes-1]<<std::endl;
    }
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


int64_t lcm(int64_t A, int64_t B) {
  int64_t g = std::__gcd(A, B);
  return (A/g)*B;
}


void GenerateCase(const int group_index, const int group_size, const int64_t max_gcd, const int64_t max_prime_index, 
                  std::default_random_engine& generator,
                  std::uniform_int_distribution<int64_t>& distribution) {
  assert(max_gcd>1);
  int n_ok = 0;
  int n_wrong = 0;
  for(int case_index = 0; case_index < group_size; ++case_index) {
    const bool sol_wanted = case_index % 2;
    int64_t A = 0;
    int64_t B = 0;
    int64_t N = 0;
    if (sol_wanted) { // Should return YES: let gcd(A,B) divide N
      A = 2 + distribution(generator) % (max_gcd-1);
      B = 2 + distribution(generator) % (max_gcd-1);
      const int64_t p = distribution(generator)%std::min(max_prime_index, int64_t(20000));
      // In this case, the (wrong) number-theory-based algorithm will say YES too
      N = A*primes[p]+B*primes[p+1]; // the actual solution
      std::cerr<<N<<","<<A<<","<<B<<","<<primes[p]<<std::endl;
      assert(B<=N && A<=N && N<=kMaxN);
    } else  {
      const bool detect_wrong_algo = distribution(generator)%2;
      if(detect_wrong_algo) {
        const int64_t p =  distribution(generator) % std::min(int64_t(100), max_prime_index);
        const int64_t g = 2 + distribution(generator) % (max_gcd-1);
        A = g * primes[p];
        B = g * primes[p+1];
        // The greatest integer N that cannot be written as N=Ax+By with x,y>=0 is lcm(A,B)-A-B = g* (primes[p]*primes[p+1] - primes[p] - primes[p+1]) 
        // The wrong algo will say YES (because g divides N, but the right answer is NO (because of the chicken mc-nugget theorem))
        N = g * (primes[p]*primes[p+1] - primes[p] - primes[p+1]); 
        std::cerr<<N<<","<<A<<","<<B<<std::endl;
        assert(B<=N && A<=N && N<=kMaxN);
      } else {
        const int64_t p =  distribution(generator) % max_prime_index;
        const int64_t g = 2 + distribution(generator) % (max_gcd-1);
        int64_t residual = 1 + distribution(generator)%(g-1);
        // the wrong algo will say NO too.
        A = g * primes[p];
        B = g * primes[p+1];
        N = g * primes[p+2] + residual;
        std::cerr<<N<<","<<A<<","<<B<<std::endl;
        assert(B<=N && A<=N && N<=kMaxN);
      }
      
    }
    const bool wrong_algo_sol = SolveIncorrect(N, A, B);
    const bool actual_sol_fast = Solve(N, A, B);
    n_ok += (wrong_algo_sol==actual_sol_fast);
    n_wrong += (wrong_algo_sol!=actual_sol_fast);
    
    std::cout << "Generating group " << group_index << ", case "<<case_index<<".(N="<<N<<",A="<<A<<",B="<<B<<
                 ". Intended:"<<sol_wanted<<". Actual:"<<actual_sol_fast<<". WrongAlgo:"<<wrong_algo_sol<<std::endl;
    assert(B<=N && A<=N && N<=kMaxN);
    assert(sol_wanted==actual_sol_fast);
    // Write input
    {
      std::ostringstream os;
      os<<"group_"<<group_index<<".case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << N<<" "<<A<<" "<<B<<std::endl;
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
  std::cout<<"n_ok="<<n_ok<<", n_wrong="<<n_wrong<<std::endl;
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  PrecomputePrimes();
  std::uniform_int_distribution<int64_t> distribution(0,0x0FFFFFFFFFFFFFFF);
  
  GenerateCase(0, 6, 7,  10, generator, distribution);
  GenerateCase(1, 6, 7,  50, generator, distribution);
  GenerateCase(2, 6, 7,  250, generator, distribution);
  GenerateCase(3, 6, 7, 500, generator, distribution);
  GenerateCase(4, 6, 14, 1000, generator, distribution);
  GenerateCase(5, 6, 16, 2000, generator, distribution);
  GenerateCase(6, 6, 18, 15000, generator, distribution);
  GenerateCase(7, 6, 20, 20000, generator, distribution);
  GenerateCase(8, 6, 22, 45000, generator, distribution);
  GenerateCase(9, 6, 25, 50000, generator, distribution);

}

int main(){
  //SolveSingle(true);
  GenerateCases();
  return 0;
}
