#include <iostream>
int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int64_t total = 0;
  for(int i=0;i<12;++i) {
    int64_t a;
    std::cin >> a;  
    total += a*days_in_month[i];
  }
  total*=3600*24;
  std::cout << total << std::endl;
  return 0;
}
