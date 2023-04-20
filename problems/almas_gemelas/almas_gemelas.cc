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

void Print(const std::vector<Point>& v) {
  for(const Point& p : v) {
    std::cout << p <<std::endl;
  }
}


std::ostream& operator<<(std::ostream& os, const Point& p){
  os << '(' << p.x << ',' << p.y << ')';
  return os;
}

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
                        const int64_t x1, const int64_t y1, const bool verbose=false) {
  // Change of coordinates
  Point L(x1-x0, y1-y0);
  for(int i=0;i<P.size();++i) {
    Point T(P[i].x-x0, P[i].y-y0);
    P[i] = Point(L.Dot(T), L.Cross(T));
  }                    
  
  std::sort(P.begin(), P.end(), PointCmpX());
  if(verbose) {
    std::cerr<<"Solving. Rotated points:"<<std::endl;
    Print(P);
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


void WriteCase(const int case_index, const std::vector<Point>& P,
               const int64_t x0, const int64_t y0,
               const int64_t x1, const int64_t y1) {
  // Write input
  std::vector<Point> mutable_p = P;
  const int32_t sol = CountTwinFlames(mutable_p, x0, y0, x1, y1);
  {
    std::ostringstream os;
    os << "case_" << case_index << ".in";
    std::ofstream F;
    F.open (os.str());
    F << P.size() << std::endl;
    for(const Point& p : P) {
      F << p.x << " " << p.y << std::endl;
    }
    F << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os << "case_" << case_index << ".out";
    std::ofstream F;
    F.open (os.str());
    F << sol << std::endl;
    F.close();
  }
}

void GenerateCase(const int32_t case_index, const int32_t N,
                  std::default_random_engine& generator, const bool verbose=false) {
  std::uniform_int_distribution<int64_t> uniform_N(1, N/2);
  std::uniform_int_distribution<int64_t> uniform_coord(-1000, 1000);
  
  
  const int min_twin_flames = uniform_N(generator);
  std::cerr << "Generating case "<< case_index<<". N="<<N<<". n_twin_flames="<<min_twin_flames<<std::endl;
  std::set<Point, PointCmpX> S;
  while(S.size() < 2*min_twin_flames) {
    const int64_t x = uniform_coord(generator);
    const int64_t y = uniform_coord(generator);
    S.insert(Point(x, y));
    S.insert(Point(x, -y));
  }
  while(S.size()<N) {
    const int64_t x = uniform_coord(generator);
    const int64_t y = uniform_coord(generator);
    S.insert(Point(x, y));
  }
  if(verbose) {
    std::cerr<<"Initial points:"<<std::endl;
    for(const Point& p : S) {
      std::cerr << "(" <<p.x << ", "<<p.y<<")" <<std::endl;
    } 
  }
  // Transform all points
  Point v(uniform_coord(generator), uniform_coord(generator));
  Point p0(uniform_coord(generator), uniform_coord(generator));  
  
  std::vector<Point> points;
  points.reserve(N);
  for(const Point& p : S) {
    points.push_back(Point(v.Dot(p)+p0.x, v.Cross(p)+p0.y));
  }
  Point p1(v.Dot(Point(1, 0))+p0.x, v.Cross(Point(1, 0))+p0.y);
  
  if(verbose) {
    std::cerr<<"Line:"<<p0.x<<", "<< p0.y<<", " <<p1.x<<", "<< p1.y << std::endl;
    std::cerr<<"Final points:"<<std::endl;
    for(const Point& p : points) {
      std::cerr << "(" <<p.x << ", "<<p.y<<")" <<std::endl;
    }
  }
  WriteCase(case_index, points, p0.x, p0.y, p1.x, p1.y);
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  //GenerateCase(0, 7, generator, false);
  GenerateCase(0, 10000, generator);
  GenerateCase(1, 20000, generator);
  GenerateCase(2, 25000, generator);
  GenerateCase(3, 27000, generator);
  GenerateCase(4, 30000, generator);

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
  // int32_t sol = CountTwinFlames(points, x0, y0, x1, y1);
  int32_t sol = CountTwinFlamesBruteForce(points, x0, y0, x1, y1);
  std::cout << sol << std::endl;
}

int main() {
  //GenerateCases();
  Solve();
}



