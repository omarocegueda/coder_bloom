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
  int32_t sol = CountTwinFlamesBruteForce(points, x0, y0, x1, y1);
  std::cout << sol << std::endl;
}

int main() {
  Solve();
}



