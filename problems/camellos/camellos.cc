#include <iostream>
#include <numeric>
int main() {
  int64_t x, y, z, T;
  std::cin >> x >> y >> z >> T;
  int64_t lcm = (x*y) / std::gcd(x, y);
  lcm = (lcm*z)/std::gcd(lcm, z);
  int64_t nx = lcm/x;
  int64_t ny = lcm/y;
  int64_t nz = lcm/z;
  if(nx+ny+nz > lcm) {
    std::cout << "imposible" << std::endl;
  } else {
    int64_t min_factor = (T+lcm-1)/lcm;
    std::cout << min_factor*lcm - T << std::endl;
  }
  return 0;
}
