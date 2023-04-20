#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Point {
  Point() = default;
  Point(int64_t x_, int64_t y_):x(x_), y(y_) {}
  
  int64_t x, y;
  friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

struct PointCmpX {
  bool operator()(const Point& a, const Point& b) const{
    if(a.x == b.x) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
};

int64_t Dist(const Point& a, const Point& b) {
  return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

struct PointCmpY {
  bool operator()(const Point& a, const Point& b) const {
    if(a.y == b.y) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
};

const int64_t kMinPos = -1000000000000;
const int64_t kMaxPos = 1000000000000;
const int32_t kMaxPoints = 30000;

int64_t FindClosestPairSlow(const std::vector<Point>& P) {
  int64_t min_dist = Dist(P[0], P[1]);
  for(int i=0;i<P.size();++i) {
    const Point& p = P[i];
    for(int j=i+1; j<P.size();++j) {
      const Point& q = P[j];
      const int64_t d = Dist(p, q);
      if(d < min_dist) {
        min_dist = d;
      }
    }
  }
  return min_dist;
}

void Solve() {
  int32_t N;
  std::cin >> N;
  std::vector<Point> P(N);
  for(int i=0;i<N;++i) {
    Point& p = P[i];
    std::cin >> p.x >> p.y;
  }
  std::cout << FindClosestPairSlow(P) << std::endl;  
}

int main() {
  Solve();
  return 0;
}





