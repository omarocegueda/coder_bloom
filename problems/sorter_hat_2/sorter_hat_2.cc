#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <fstream>

const int64_t kMod = 1000000007;

void Print(std::vector<int64_t>& v) {
  for(int64_t x : v) {
    if(x == 0) {
      break;
    }
    std::cout << x << ",\t";
  }
  std::cout << std::endl;
}


int64_t BinPow(int64_t x, int64_t n) {
  if(n==0) {
    return 1;
  }
  if(n==1) {
    return x;
  }
  int64_t partial = BinPow(x, n/2);
  partial = (partial * partial) % kMod;
  if(n%2==0) {
    return partial;
  }
  return (partial* x) %kMod;
} 


int64_t InvMult(int64_t x) {
  int64_t inv = BinPow(x, kMod-2);
  assert((inv * x)%kMod == 1);
  return inv;
}

int64_t Comb(int64_t N, int64_t C) {
  C = std::max(C, N-C);
  
  int64_t sol = 1;
  for(int64_t i = C+1; i<=N; ++i) {
    sol = (sol*i)%kMod;
  }
  for(int64_t i = 2; i<=N-C; ++i) {
    sol = (sol*InvMult(i))%kMod;
  }
  return sol;
}

int64_t SolveFast(int64_t N, int64_t C) {
  return Comb(N+C-1, C-1);
}


int64_t SolveSlow(int64_t N, int64_t C) {
  std::vector<int64_t> v[2];
  v[0].resize(N+C);
  v[1].resize(N+C);
  v[0][0] = v[1][0] = v[1][1] = 1;
  for(int n = 2; n<N+C; ++n) {
    std::vector<int64_t> &prev = v[1-n%2];
    std::vector<int64_t> &current = v[n%2];
    for(int k=1; k<=n; ++k) {
      current[k] = (prev[k-1] + prev[k])%kMod;
    }
  }
  std::vector<int64_t> &sol = v[(N+C-1)%2];
  std::cout << "slow:"<<(sol[C-1]%kMod) << ". fast:"<<(SolveFast(N, C)) <<std::endl;
  assert(sol[C-1] == SolveFast(N, C));
  return sol[C-1];
}

void GenerateCases() {
  auto generate_case = [&](const int case_index, const int64_t N, const int64_t C){
    int64_t sol = SolveFast(N, C);
    // Write input
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << N << " " << C << std::endl;
      F.close();
    }
    // Write output
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".out";
      
      std::ofstream F;
      F.open (os.str());
      F << sol << std::endl;
      F.close();
    }
  };

  generate_case(0,     21,       87);
  generate_case(1,     57,       23);
  generate_case(2,     183,     371);
  generate_case(3,     491,     241);
  generate_case(4,     523,     671);
  generate_case(5,     823,     673);
  generate_case(6,     974,     623);
  generate_case(7,     1024,   1211);
  generate_case(8,     2048,   1945);
  generate_case(9,     3001,   3002);
  
  generate_case(10,    9821,   7232);
  generate_case(11,   15923,  18423);
  generate_case(12,   24322,    323);
  generate_case(13,  105322,   2439);
  generate_case(14,  290230, 412320);
  generate_case(15,  328739, 314320);
  generate_case(16,  692302, 523928);
  generate_case(17,  791210, 874351);
  generate_case(18,  824312,  87223);
  generate_case(19, 1000000, 999900);
}


int main() {
  GenerateCases();
  return 0;
}
