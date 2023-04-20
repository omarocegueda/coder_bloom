#include <iostream>
#include <string>

int64_t ParseIncorrect(const std::string& s, const int start) {
  int64_t n = 0;
  for(int i=start; i>=start; --i) {
    n = n * 10 + s[i] - '0';
  }
  return n;
}

int64_t ParseCorrect(const std::string& s, const int start) {
  return std::stoll(std::string(s.begin() + start, s.end()));
}

int64_t SolveIncorrect(const std::string& s) {
  int64_t sum = 0;
  for(int start = 0; start < s.size(); ++start) {
    int64_t n = ParseCorrect(s, start);
    sum += n % (s[s.size()-1] - '0');
  }
  return sum;
}

long long SolveCorrect(const std::string& s) {
  long long a = s.back() - '0', res = 0;
  for(int j = 0; j < s.size(); ++j) {
      res += (std::stoll(std::string(s.begin() + j, s.end())) % a);
  }
  return res;
}


int main() {
  int cases = 0;
  std::cin >> cases;
  for(int i=0;i<cases;++i) {
    std::string s;
    std::cin >> s;
    std::cout << SolveIncorrect(s) <<std::endl;
  }
  return 0;*/
}


/*
int main() {
  int cases;
  std::cin >> cases;
  for(int i=0;i<cases;++i) {
    std::string s;
    std::cin >> s;
    std::size_t n = s.size();
    int a0 = s[n - 1] - '0';
    int pow_mod = 1 % a0;
    int current_mod = 0;
    int64_t sum = 0;
    for(int j=0; j<n; ++j) {
      int aj = s[n-1-j] - '0';
      current_mod = (current_mod + aj * pow_mod) % a0;
      sum += current_mod;
      pow_mod = (pow_mod * 10) % 9;
    }
    std::cout << sum <<std::endl; 
  }
  return 0;
*/
