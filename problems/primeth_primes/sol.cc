#include <iostream>
#include <sstream>
const uint32_t kMaxNumPrimes = 100000; // 1,000,000/ln(1000,000) ~= 72,382
uint64_t primes[kMaxNumPrimes];
int n_primes;

void PrecomputePrimes(const uint32_t kMaxPrime) {
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
}

int Solve(const int N) {
  PrecomputePrimes(N);
  int cnt = 0;
  while(cnt<n_primes && primes[cnt]-1 < n_primes && primes[primes[cnt]-1] <= N) {
    ++cnt;
  }
  return cnt;
}

int main() {
  uint32_t N;
  std::cin >> N;
  std::cout << Solve(N) << std::endl;
  return 0;
}

