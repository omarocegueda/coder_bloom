#include <iostream>

int64_t Solve(int64_t n) {
  if(n==0) {
    return 1;
  }
  if(n==1) {
    return 1;
  }
  if(n==2) {
    return 2;
  }
  if(n==3) {
    return Solve(n-1) + Solve(n-2);
  }
  return Solve(n-1) + Solve(n-2) + Solve(n-4);
}


int main(){
  int64_t n;
  std::cin >> n;
  std::cout << Solve(n) << std::endl;
  return 0;
}
