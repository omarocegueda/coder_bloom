// 14650. Jack el factorizador
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

bool IsPrime(const uint64_t x) {
  for(int q = 2; q*q <=x; ++q) {
    if(x%q==0) {
      return false;
    }
  }
  return true;
}

std::vector<uint64_t> Solve(const std::vector<uint64_t>& input) {
  std::vector<uint64_t> sol;
  bool victim = false;
  for(const int x : input) {
    if(IsPrime(x)) {
      victim = true;
    } else {
      if(victim) {
        sol.push_back(0);
      }
      victim = false;
      sol.push_back(x);
    }
  }
  if(victim) {
    sol.push_back(0);
  }
  for(const uint64_t x : sol) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return sol;
}

void Solve() {
  int N;
  std::cin >> N;
  std::vector<uint64_t> input(N);
  for(int i=0;i<N;++i) {
    std::cin>>input[i];
  }
  std::cout<<Solve(input).size()<<std::endl;
}

// === Test case generator ===
const uint32_t kMaxPrime = 1000000;
const uint32_t kMaxNumPrimes = 1000000;
const uint32_t kMaxNumComposite = 1000000;
uint64_t primes[kMaxNumPrimes];
uint64_t composite[kMaxNumComposite];
int n_primes;
int n_composite;


void PrecomputePrimes() {
  primes[0] = 2;
  primes[1] = 3;
  n_primes = 2;
  composite[0] = 4;
  n_composite = 1;
  for(uint64_t q=5; q<=kMaxPrime; q+=2) {
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
    } else {
      composite[n_composite] = q;
      ++n_composite;
    }
  }
  std::cout<< "Num primes:"<<n_primes<<". Last prime: "<<primes[n_primes-1]<<std::endl;
  std::cout<< "Num composite:"<<n_composite<<". Last composite: "<<composite[n_composite-1]<<std::endl;
}

void GenerateCase(int case_index, int N) {
  std::vector<uint64_t> input;
  std::vector<uint64_t> expected_output;

  bool previous_victim = false;
  while(input.size()<N) {
    const bool kCanInsertVictim = (!previous_victim) && (N-input.size()>1);
    // Decide whether inserting a victim or not
    if(kCanInsertVictim && (rand()%2)) {
      // Decide the number of primes (at least 2) and at most kMaxPrimeFactors (not too many).
      const std::size_t kMaxPrimeFactors = std::min(N-input.size(), std::size_t(15));
      int g = 2 + rand()%(kMaxPrimeFactors-1);
      // Insert g primes.
      for(int i=0;i<g;++i) {
        input.push_back(primes[rand()%n_primes]);
      }
      previous_victim = true;
      expected_output.push_back(0);
    } else {
      // Insert a composite number.
      const uint64_t c = composite[rand()%n_composite];
      input.push_back(c);
      previous_victim = false;
      expected_output.push_back(c);
    }
  }
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", input.size());
    for(const int a : input) {
      fprintf(F, "%d ", a);
    }
    fclose(F);
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", expected_output.size());
    fclose(F);
  }
  // Report diff with official solution
  std::cout <<"case_"<<case_index<<". N="<<N<<". Actual: "<<Solve(input).size()<<". Expected: "<<expected_output.size()<<std::endl;
}

void GenerateCases() {
  srand(time(nullptr));
  PrecomputePrimes();
  GenerateCase(0, 15);
  GenerateCase(1, 32);
  GenerateCase(2, 58);
  GenerateCase(3, 76);
  GenerateCase(4, 96);
  GenerateCase(5, 160);
  GenerateCase(6, 280);
  GenerateCase(7, 510);
  GenerateCase(8, 803);
  GenerateCase(9, 100);
  GenerateCase(10, 104);
  GenerateCase(11, 300);
  GenerateCase(12, 500);
  GenerateCase(13, 704);
  GenerateCase(14, 950);
  GenerateCase(15, 1031);
  GenerateCase(16, 2034);
  GenerateCase(17, 5100);
  GenerateCase(18, 8020);
  GenerateCase(19, 9102);
}

int main() {
  //GenerateCases();
  Solve();
  return 0;
}
