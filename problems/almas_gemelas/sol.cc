#include <stdint.h>

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <vector>

struct Point {
  Point() = default;
  Point(int64_t x_, int64_t y_):x(x_), y(y_) {}
  int64_t Dot(const Point& other) {
    return x * other.x + y * other.y;
  }
  int64_t Cross(const Point& other) {
    return x * other.y - y * other.x;
  }
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

bool TwinFlames(const Point& P, const Point& Q,
                int64_t x0, int64_t y0, int64_t x1, int64_t y1){
  if(Point(Q.x-P.x, Q.y-P.y).Dot(Point(x1-x0, y1-y0))!=0) {
    return false;
  }
  
  return Point(x1-x0, y1-y0).Cross(Point(P.x-x0, P.y-y0)) ==
         Point(Q.x-x0, Q.y-y0).Cross(Point(x1-x0, y1-y0));
}

int32_t CountTwinFlamesBruteForce(const std::vector<Point>& P,
                                  const int64_t x0, const int64_t y0,
                                  const int64_t x1, const int64_t y1, const bool verbose=false) {
  int32_t n_twin_flames = 0;
  for(int i=1;i<P.size();++i) {
    for(int j=0; j<i; ++j) {
      if(TwinFlames(P[i], P[j], x0, y0, x1, y1)) {
        ++n_twin_flames;
      }
    }
  }
  return n_twin_flames;
}

int32_t CountTwinFlames(std::vector<Point>& P,
                        const int64_t x0, const int64_t y0,
                        const int64_t x1, const int64_t y1) {
  // Change of coordinates
  Point L(x1-x0, y1-y0);
  for(int i=0;i<P.size();++i) {
    Point T(P[i].x-x0, P[i].y-y0);
    P[i] = Point(L.Dot(T), L.Cross(T));
  }                      
  std::set<Point, PointCmpX> upper;
  std::set<Point, PointCmpX> lower;
  for(const Point& p : P) {
    if(p.y > 0){
      upper.insert(p);
    } else if (p.y < 0) {
      lower.insert(Point(p.x, -p.y));
    }
  }
  int32_t twin_flames = 0;
  for(const Point& p : upper) {
    if(lower.find(p)!=lower.end()) {
      ++twin_flames;
    }
  }
  return twin_flames;
}

void Solve() {
  int32_t N;
  std::cin >> N;
  std::vector<Point> points;
  points.reserve(N);
  for(int i=0;i<N;++i) {
    int64_t x, y;
    std::cin >> x >> y;
    points.push_back(Point(x, y));
  }
  
  int64_t x0, y0, x1, y1;
  std::cin >> x0 >> y0 >> x1 >> y1;
  int32_t sol = CountTwinFlames(points, x0, y0, x1, y1);
  std::cout << sol << std::endl;
}

int main() {
  Solve();
}



