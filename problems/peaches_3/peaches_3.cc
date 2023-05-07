#include <iostream>
#include <string>

int Solve(const int64_t P, const int64_t L, const int64_t R, const std::string& mushrooms){
  int kMinExponent = 0;
  while(P >= L * (int64_t(1)<<(-kMinExponent+1))) {
    --kMinExponent;
  }
  int kMaxExponent = 0;
  while(P * (int64_t(1)<<(kMaxExponent+1))<=R) {
    ++kMaxExponent;
  }
  int p = 0;
  int coins = 0;
  for(const char c : mushrooms) {
    const int delta = (c=='b')?1:-1; 
    if(kMinExponent<=(p + delta) && (p + delta) <=kMaxExponent) {
      p+=delta;
      ++coins;
    }
  }
  return coins;
}

int main() {
  int64_t N, P, L, R;
  std::string S;
  std::cin >> N >> P >> L >> R >> S;
  std::cout << Solve(P, L, R, S) << std::endl;
  return 0;
}