#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <sstream>
const int kMaxPrimes=7000000;
const int kMaxVote = 1000000000;

int primes[kMaxPrimes];
int n_primes;

bool IsPrime(const int p) {
  for(int i=0; primes[i]*primes[i] <= p; ++i) {
    if(p%primes[i] == 0) {
      return false;
    }
  }
  return true;
}

void PrecomputePrimes(const int max_p) {
  primes[0] = 2;
  n_primes = 1;
  for(int p = 3; p <=max_p; ++p) {
    if(IsPrime(p)) {
      primes[n_primes] = p;
      ++n_primes;
    }
  }
}

std::vector<int> Factor(int n) {
  std::vector<int> factors;
  for(int i=0; (n > 1) && (primes[i]*primes[i] <= n);++i) {
    while(n%primes[i] == 0) {
      factors.push_back(primes[i]);
      n/=primes[i];
    }
  }
  if(n>1) {
    factors.push_back(n);
  }
  return factors;
}

void CountVotes(int n, std::map<int, int>& counts) {
  for(int i=2; (n > 1) && (i*i <= n);++i) {
    bool divisible = false;
    while(n % i == 0) {
      divisible = true;
      n/=i;
    }
    if(divisible) {
      counts[i] ++;
    }
  }
  if(n>1) {
    counts[n]++;
  }
}

void PrintFactors(int n) {
  std::vector<int> v = Factor(n);
  std::cout<<"Factors("<<n<<")=";
  for(int f : v) {
    std::cout<<f<<",";
  }
  std::cout<<std::endl;
}


std::pair<int, int> Solve(const std::vector<int>& votes) {
  std::map<int, int> C;
  for(const int v : votes) {
    CountVotes(v, C);
  }
  
  std::pair<int, int> best = std::make_pair(-1, -1);
  for(const auto&[p, c] : C) {
    if(best.second == -1 || best.second < c) {
      best = {p, c};
    }
  }
  
  return best;
}

void GenerateCase(int V, int case_index) {
  std::cout << "Generating case: "<< case_index<<std::endl;
  std::vector<int> votes;
  std::map<int, int> counts;
  std::pair<int, int> winner = std::make_pair(-1, -1); 
  for(int i = 0; i<V-1;++i) {
    // Select some primes at random.
    uint64_t v = 1;
    for(int r = rand()%n_primes; primes[r]*v <= kMaxVote; r = rand()%n_primes) {
      v *= primes[r];
      counts[primes[r]]++;
      if(winner.second==-1 || winner.second < counts[primes[r]]) {
        winner = {primes[r], counts[primes[r]]};
      }
    }
    votes.push_back(v);
  }
  // Make sure there is at most one winner.
  int64_t added = winner.first;
  while(added*winner.first < kMaxVote) {
    added*=winner.first;
  }
  votes.push_back(added);
  
  {
    // Write input
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", votes.size());
    for(int v : votes) {
      fprintf(F, "%d ", v);
    }
    fprintf(F, "\n");
    fclose(F);
  }
  
  {
    // Write output
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    const std::pair<int, int> sol = Solve(votes);
    fprintf(F, "%d %d\n", sol.first, sol.second);
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(nullptr));
  PrecomputePrimes(10000);
  
  //Generate cases
  GenerateCase(5, 0);
  GenerateCase(10, 1);
  GenerateCase(23, 2);
  GenerateCase(25, 3);
  GenerateCase(33, 4);
  GenerateCase(45, 5);
  GenerateCase(51, 6);
  GenerateCase(62, 7);
  GenerateCase(89, 8);
  GenerateCase(93, 9);
  GenerateCase(101, 10);
  GenerateCase(134, 11);
  GenerateCase(211, 12);
  GenerateCase(272, 13);
  GenerateCase(390, 14);
  GenerateCase(468, 15);
  GenerateCase(515, 16);
  GenerateCase(600, 17);
  GenerateCase(818, 18);
  GenerateCase(999, 19);  
}


int main() {
  GenerateCases();
  /*PrecomputePrimes(10000000);
  std::cout<< "n_primes="<<n_primes<<std::endl;
  std::cout<< "last prime="<<primes[n_primes-1]<<std::endl;
  PrintFactors(2*2*3*3*5*7);*/
  //Solve(); 
  return 0;
}
