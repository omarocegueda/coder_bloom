#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
int64_t kMod = 1000000007;

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

std::unordered_map<int64_t, int64_t> Factorize(int64_t x) {
  std::unordered_map<int64_t, int64_t> F;
  for(int p=2;p*p<=x;++p) {
    int c=0;
    while(x%p==0) {
      ++c;
      x/=p;
    }
    if(c>0) {
      F[p] = c;
    }  
  }
  if(x>1) {
    F[x] = 1;
  }
  return F;
}

int64_t Solve(const std::vector<int64_t>& E) {
  std::unordered_map<int64_t, int64_t> lcm = Factorize(E[0]);
  for(int i=1;i<E.size();++i) {
    std::unordered_map<int64_t, int64_t> e = Factorize(E[i]);
    for(const auto&[p,c] : e) {
      lcm[p] = std::max(lcm[p], c);
    }
  }
  int64_t sol = 1;
  for(const auto&[p,c] : lcm) {
    sol = (sol*BinPow(p,c))%kMod;
  }
  return sol;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int64_t> E(N);
  for(int i=0;i<N;++i){
    std::cin >> E[i];
  }
  std::cout << Solve(E)<< std::endl;
  return 0;
}
