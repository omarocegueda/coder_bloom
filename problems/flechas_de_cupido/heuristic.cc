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

int64_t FindClosestPairHeuristic(std::vector<Point>& P) {
  std::sort(P.begin(), P.end(), PointCmpX());
  int64_t min_dist = Dist(P[0], P[1]);
  for(int i=2;i<P.size();++i) {
    int64_t d = Dist(P[i-1], P[i]);
    if(d < min_dist) {
      min_dist = d;
    }
  }
  // Now by Y
  std::sort(P.begin(), P.end(), PointCmpY());
  for(int i=1;i<P.size();++i) {
    int64_t d = Dist(P[i-1], P[i]);
    if(d < min_dist) {
      min_dist = d;
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
  std::cout << FindClosestPair(P) << std::endl;  
}

int main() {
  Solve();
  return 0;
}





