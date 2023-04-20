#include <iostream>
#include <cstring>
int64_t a0, a1, alpha, beta;
bool seen[100];
int64_t memo[100];

int64_t Solve(int64_t n) {
	if(n==0) {
    return a0;
  }
  if(n==1) {
  	return a1;
  }
  if(seen[n]) {
    return memo[n];
  }
  int64_t sol =  alpha*Solve(n-1) + beta*Solve(n-2);
  memo[n] = sol;
  seen[n] = true;
  return sol;
}

int main() {
  memset(seen, 0, sizeof(seen));
  int64_t n;
  std::cin >> n >> a0 >> a1 >> alpha >> beta;
  std::cout <<Solve(n) << std::endl;
  for(int i=0;i<n;++i) {
    std::cout<<i<<": " <<Solve(i) << std::endl;
  }
  
	return 0;
}
