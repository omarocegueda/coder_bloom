#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <map>
#include <fstream>

int sum_all(const std::vector<int>& v) {
  int sol = 0;
  for(int c : v) {
    sol+=c;
  }
  return sol;
}

std::pair<int, int> Solve(const int N, const int C, const int k, const std::vector<int>& v) {
  const int g = std::__gcd(N, k);
  std::map<int, int> M;
  for(int p : v) {
    M[(p-1)%g]++;
  }
  std::vector<std::pair<int, int>> counts;
  for(const auto&[mod, count] : M) {
    counts.push_back({count, mod});
  }
  std::sort(counts.rbegin(), counts.rend());
  std::pair<int, int> sol = {0,0};
  for(int i=0; i<counts.size(); ++i) {
    if(i%2==0) {
      sol.first+=counts[i].first;
    } else {
      sol.second+=counts[i].first;
    }
  }
  return sol;
}

std::pair<int, int> SolveSlow(const int N, const int C, const int k, const std::vector<int>& v) {
  assert(v.size()==C);
  auto collect_all = [N, k](std::vector<int>& canicas, const int start) -> int{
    int collected = canicas[start];
    canicas[start] = 0;   
    int current = (start + k) % N;
    while(current != start) {
      collected += canicas[current];
      canicas[current] = 0;
      current = (current + k) % N;
    }
    return collected;
  };

  std::vector<int> canicas(N);
  for(int p : v) {
    assert(p>=1);
    assert(p<=N);
    canicas[p-1]++;
  }
  assert(sum_all(canicas) == C);
  
  std::vector<std::pair<int, int>> counts;
  for(int start=0, remaining=C; remaining>0; ++start) {
    if(start>=N) {
      std::cerr<<"JOOG: remaining="<<remaining<<". start="<<start<<std::endl;
      assert(start<N);
    }
    const int collected = collect_all(canicas, start);
    counts.push_back({collected, start});
    remaining -= collected;
  }
  
  std::sort(counts.rbegin(), counts.rend());
  std::pair<int, int> sol = {0,0};
  for(int i=0; i<counts.size(); ++i) {
    if(i%2==0) {
      sol.first+=counts[i].first;
    } else {
      sol.second+=counts[i].first;
    }
  }
  return sol;
}

void SolveSingle() {
  int64_t N, C, k;
  std::cin >> N >> C >> k;
  std::vector<int> v(C);
  for(int i=0;i<C;++i) {
    std::cin >> v[i];
  }
  const std::pair<int, int> actual = SolveSlow(N, C, k, v);
  std::cout << actual.first<<" "<<actual.second<<std::endl;
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



std::vector<int> GeneratePositions(const std::vector<int>& mod_counts, const int N,
                                   std::default_random_engine& generator) {
  int total_to_assign = sum_all(mod_counts);
  const int segment_size = mod_counts.size();
  const int num_segments = N / segment_size;
  std::uniform_int_distribution<int64_t> distribution(0, num_segments-1);
  std::vector<int> generated;
  for(int r=0;r<segment_size;++r) {
    // Append mod_counts[i] indices.
    for(int j=0;j<mod_counts[r];++j) {
      const int selected_segment = distribution(generator);
      assert(selected_segment * segment_size + r < N);
      assert(selected_segment * segment_size + r >=0);
      generated.push_back(1+ selected_segment * segment_size + r);
    }
  }
  std::cerr << "JOOG: GeneratePositions ended."<<std::endl;
  assert(generated.size()==total_to_assign);
  return generated;
}

std::vector<int> GenerateModCounts(const int C, const int segment_size) {
  std::vector<int> mod_counts(segment_size);
  int remaining = C;
  for(int i=0, to_assign = 1; remaining>0; i=(i+1)%segment_size, ++to_assign) {
    const int actual_assign = std::min(to_assign, remaining);
    mod_counts[i] += actual_assign;
    remaining -= actual_assign;
  }
  assert(sum_all(mod_counts)==C);
  return mod_counts;
}

void GenerateCase(const int case_index, const int g, const int max_prime_index, const int C, 
                  std::default_random_engine& generator) {
  int p=0;
  {
    std::uniform_int_distribution<int64_t> distribution(0, max_prime_index-1);
    p = distribution(generator);
  }
   
  const int k = g * primes[p];
  const int N = g * primes[p+1];
  std::cerr<<"JOOG: case "<<case_index<<". N="<<N<<", C="<<C<<", k="<<k<<std::endl;
  
  const std::vector<int> mod_counts = GenerateModCounts(C, g);
  const std::vector<int> v = GeneratePositions(mod_counts, N, generator);
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    assert(1<=N && N<=1000000000);
    assert(1<=k && k<=1000000000);
    assert(0<=C && C<=1000000);
    F << N<<" "<<C<<" "<<k<<std::endl;
    for(int i=0;i<C;++i) {
      F << v[i] << " ";
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
    
    const std::pair<int, int> actual = Solve(N, C, k, v);
    if(N<=1000000) {
      const std::pair<int, int> expected = SolveSlow(N, C, k, v);
      assert(actual == expected);
    }
    F << actual.first << " " << actual.second << std::endl;
    F.close();
  }

}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  PrecomputePrimes();
  
  
  GenerateCase(0, 4, 5, 3, generator);
  GenerateCase(1, 21, 10, 5, generator);
  GenerateCase(2, 53, 12, 10, generator);
  GenerateCase(3, 182, 17, 20, generator);
  GenerateCase(4, 495, 21, 38, generator);
  GenerateCase(5, 870, 30, 71, generator);
  GenerateCase(6, 1008, 36, 130, generator);
  GenerateCase(7, 2185, 42, 255, generator);
  GenerateCase(8, 37596, 88, 550, generator);
  GenerateCase(9, 62349, 91, 1100, generator);
  
  GenerateCase(10, 75392, 105, 2572, generator);
  GenerateCase(11, 94231, 125, 4295, generator);
  GenerateCase(12, 102412, 150, 8298, generator);
  GenerateCase(13, 235828, 175, 17324, generator);
  GenerateCase(14, 284721, 181, 35912, generator);
  GenerateCase(15, 328217, 201, 72324, generator);
  GenerateCase(16, 483571, 211, 142932, generator);
  GenerateCase(17, 611217, 221, 278123, generator);
  GenerateCase(18, 793261, 231, 578125, generator);
  GenerateCase(19, 893425, 250, 994639, generator);
}

int main(){
  // SolveSingle();
  GenerateCases();
  return 0;
}
