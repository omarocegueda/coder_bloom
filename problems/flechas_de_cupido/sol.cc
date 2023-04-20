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

int64_t FindClosestPairFast(std::vector<Point>& points) {
  std::sort(points.begin(), points.end(), PointCmpX());
  std::set<Point, PointCmpY> S;
  S.insert(points[0]);
  S.insert(points[1]);
  int64_t min_dist = Dist(points[0], points[1]);
  for(int32_t i = 2; i< points.size(); ++i) {
    const Point& p = points[i];
    auto begin = S.lower_bound(Point(kMinPos, p.y - min_dist));
    auto end = S.upper_bound(Point(kMaxPos, p.y + min_dist));    
    for(auto iter=begin; iter!=end;) {
      const int64_t d = Dist(p, *iter);
      if(d < min_dist) {
        min_dist = d;
      }
      auto previous = iter;
      ++iter;
      // Remove irrelevant points from S 
      if(previous->x < p.x - min_dist) {
        S.erase(previous);
      } 
    }
    S.insert(p);
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
  std::cout << FindClosestPairFast(P) << std::endl;  
}

int main() {
  Solve();
  return 0;
}





