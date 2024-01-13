#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

struct Target {
  int64_t radius;
  int64_t points;
  Target() = default;
  Target(int64_t r, int64_t p): radius(r), points(p) {}
  const bool operator<(const Target& other) const {
    return radius < other.radius;
  }
};

int64_t SolveFast(const int32_t N, const std::vector<Target>& T, const int32_t M, const std::vector<int64_t>& R2) {
  int64_t total = 0;
  for(int64_t r2 : R2) {
    auto upper = std::upper_bound(T.begin(), T.end(), Target(r2, 0));
    if(upper != T.end()) {
      total += upper->points;
    }
  }
  return total;
}

int64_t SolveSlow(const int32_t N, const std::vector<Target>& T, const int32_t M, const std::vector<int64_t>& R2) {
  int64_t total = 0;
  for(int64_t r2 : R2) {
    for(int i=0;i<N;++i) {
      if(r2 < T[i].radius) {
        total+=T[i].points;
        break;
      }
    }
  }
  return total;
}

void Solve() {
  int32_t N;
  std::cin >> N;
  std::vector<Target> T2(N);
  for(int i=0;i<N;++i) {
    int64_t r, p;
    std::cin >> r >> p;
    T2[i].radius = r * r;
    T2[i].points = p;
  }
  std::sort(T2.begin(), T2.end());
  for(int i=1;i<N;++i) {
    assert(T2[i-1].radius !=T2[i].radius);
  }

  int32_t M;
  std::cin >> M;
  std::vector<int64_t> R2(M);
  for(int i=0;i<M;++i) {
    int64_t x, y;
    std::cin >> x >> y;
    R2[i] = x*x + y*y;
  }
  std::sort(R2.begin(), R2.end());
  std::cout << SolveFast(N, T2, M, R2) << std::endl;
  //std::cout << SolveSlow(N, T2, M, R2) << std::endl;
}

int main() {
  Solve();
  return 0;
}