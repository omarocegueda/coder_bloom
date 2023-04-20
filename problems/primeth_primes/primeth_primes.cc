// Primeth primes
#include <iostream>
#include <sstream>
const uint32_t kMaxPrime = 1100000;
const uint32_t kMaxNumPrimes = 1100000;
uint64_t primes[kMaxNumPrimes];
int n_primes;

void PrintFirstPrimethPrimes() {
  for(int i=0;i<20;++i) {
    std::cout<<primes[i]<<", ";
  }
  std::cout<<std::endl;
  
  for(int i=0;i<20;++i) {
    std::cout<<primes[primes[i]-1]<<", ";
  }
  std::cout<<std::endl;
}

void PrecomputePrimes() {
  primes[0] = 2;
  primes[1] = 3;
  n_primes = 2;
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
    }
  }
  std::cout<< "Num primes:"<<n_primes<<". Last prime: "<<primes[n_primes-1]<<std::endl;
}

int Solve(const int N) {
  int cnt = 0;
  while(cnt<n_primes && primes[cnt]-1 < n_primes && primes[primes[cnt]-1] <= N) {
    //std::cout <<cnt+1 << "\t" <<  primes[cnt]<< "\t" << primes[primes[cnt]-1] <<std::endl;
    ++cnt;
  }
  return cnt;
}

void GenerateCase(const int case_index, const int N) {
  std::cerr<<"Generating("<<case_index<<", "<<N<<std::endl;
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", N);
    fclose(F);
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", Solve(N));
    fclose(F);
  }
}

void GenerateCases() {
  GenerateCase(0, 105);
  GenerateCase(1, 320);
  GenerateCase(2, 518);
  GenerateCase(3, 762);
  GenerateCase(4, 961);
  GenerateCase(5, 1600);
  GenerateCase(6, 2800);
  GenerateCase(7, 5100);
  GenerateCase(8, 8030);
  GenerateCase(9, 10051);
  GenerateCase(10, 10481);
  GenerateCase(11, 30020);
  GenerateCase(12, 50003);
  GenerateCase(13, 70401);
  GenerateCase(14, 95009);
  GenerateCase(15, 103001);
  GenerateCase(16, 203204);
  GenerateCase(17, 510600);
  GenerateCase(18, 802007);
  GenerateCase(19, 918002);
}

int main() {
  PrecomputePrimes();
  GenerateCases();
  return 0;
}


