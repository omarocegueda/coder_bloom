#include <stdint.h>

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <unordered_set>
#include <vector>

struct Point {
  Point() = default;
  Point(int64_t x_, int64_t y_):x(x_), y(y_) {}
  
  int64_t x, y;
  friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p){
  os << '(' << p.x << ',' << p.y << ')';
  return os;
}

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

void Print(const std::vector<Point>& v) {
  for(const Point& p : v) {
    std::cout << p.x << ", "<<p.y<<std::endl;
  }
}

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

int64_t FindClosestPairSlowPlusHeuristic(std::vector<Point>& P) {
  std::sort(P.begin(), P.end(), PointCmpX());
  int64_t min_dist = Dist(P[0], P[1]);
  for(int i=0;i<P.size();++i) {
    const Point& p = P[i];
    for(int j=i-1; j>=0;--j) {
      const Point& q = P[j];
      int64_t d = std::abs(p.x - q.x);
      if(d > min_dist) {
        break;
      }
      d += std::abs(p.y - q.y);
      if(d < min_dist) {
        min_dist = d;
      }
    }
  }
  return min_dist;
}

int64_t FindClosestPairHeuristic(const std::vector<Point>& in) {
  std::vector<Point> P = in;
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

Point GenerateInRectangle(const int64_t min_x, const int64_t max_x,
                          const int64_t min_y, const int64_t max_y,
                          std::default_random_engine& generator) {
  std::uniform_int_distribution<int64_t> distribution_x(min_x, max_x-1);
  std::uniform_int_distribution<int64_t> distribution_y(min_y, max_y-1);
  return Point(distribution_x(generator), distribution_y(generator));
}

int64_t Validate(const std::vector<Point>& P) {
  auto temp = P;
  const int64_t sol = FindClosestPairFast(temp);
  // Compare against brute force
  const int64_t sol_bf = FindClosestPairSlow(P);
  if(sol != sol_bf) {
    return -1;
  }
  return sol;
}

void Shuffle(std::vector<Point>& P) {
  return;
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(P.begin(), P.end(), g);
}

std::vector<Point> GenerateAntiHeuristic(const int N, const bool flip,
                                         std::default_random_engine& generator) {
  std::vector<Point> P;
  P.reserve(N);
  P.push_back(Point(kMinPos, kMinPos));
  for(int i=1;i<N-1;++i) {
    P.push_back(Point(kMinPos+i, kMinPos+i*2*N));  
  }
  P.push_back(Point(kMinPos+N-1, kMinPos));
  if(flip) {
    for(int i=0;i<N;++i) {
      P[i] = Point(P[i].y, P[i].x);
    }
  }
  Shuffle(P);
  return P;
}

std::vector<Point> GenerateSparse(const int N, std::default_random_engine& generator) {
  const int64_t kSide = (kMaxPos - kMinPos)/1000;
  const int64_t kMinSquare = kMinPos/1000;
  const int64_t kMaxSquare = kMaxPos/1000;
  std::vector<Point> P;
  bool acceptable = false;
  while(!acceptable) {
    P.clear();
    P.reserve(N);
    // Select random squares
    std::set<Point, PointCmpY> S;
    while(S.size() < N) {
      S.insert(GenerateInRectangle(kMinSquare, kMaxSquare, kMinSquare, kMaxSquare, generator));
    }
    // Expand
    for(const Point& p : S) {
      int64_t min_x = p.x*1000;
      int64_t max_x = min_x + 1000;
      int64_t min_y = p.y*1000;
      int64_t max_y = min_y + 1000;
      P.push_back(GenerateInRectangle(min_x, max_x, min_y, max_y, generator));
    }
    // Official solution
    auto temp = P;
    const int64_t sol = FindClosestPairFast(temp);
    // Heuristic
    temp = P;
    int64_t sol_h = FindClosestPairHeuristic(temp);
    if(sol_h == sol) {
      std::cerr << "Unacceptable, heuristic passes"<<std::endl;
    } else {
      acceptable = true;
    }    
  }      
  Shuffle(P);
  return P;
}

std::vector<Point> GenerateDense(const int N, 
                                 const int64_t min_x, const int64_t max_x,
                                 const int64_t min_y, const int64_t max_y,
                                 std::default_random_engine& generator) {
  assert(N <= kMaxPoints);
  assert(kMinPos <= min_x <= kMaxPos);
  assert(kMinPos <= max_x <= kMaxPos);
  assert(kMinPos <= min_y <= kMaxPos);
  assert(kMinPos <= max_y <= kMaxPos);
  std::vector<Point> P;
  P.reserve(N);
  // Generate random points
  std::set<Point, PointCmpY> S;
  while(S.size() < N) {
    S.insert(GenerateInRectangle(min_x, max_x, min_y, max_y, generator));
  }
  for(const Point& p : S) {
    P.push_back(p);
  }
  Shuffle(P);
  return P;
}


void WriteCase(const int group_index, const int case_index, const std::vector<Point>& P) {
  int64_t sol = Validate(P);
  assert(sol>0);
  // Write input
  {
    std::ostringstream os;
    os << "group_" << group_index << ".case_" << case_index << ".in";
    std::ofstream F;
    F.open (os.str());
    F << P.size() << std::endl;
    for(const Point& p : P) {
      F << p.x << " " << p.y << std::endl;
    }
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os << "group_" << group_index << ".case_" << case_index << ".out";
    std::ofstream F;
    F.open (os.str());
    F << sol << std::endl;
    F.close();
  }
}

void GenerateGroup(const int group_index, const int N,
                  std::default_random_engine& generator) {
  std::cerr<<"Generating group "<<group_index<<std::endl;
  assert(N <= kMaxPoints);
  {
    // Add anti-heuristic along x
    const std::vector<Point> P = GenerateAntiHeuristic(N, false, generator);
    WriteCase(group_index, 0, P);
  }
  {
    // Add anti-heuristic along y
    const std::vector<Point> P = GenerateAntiHeuristic(N, true, generator);
    WriteCase(group_index, 1, P);
  }
  {
    // Add sparse
    const std::vector<Point> P = GenerateSparse(N, generator);
    WriteCase(group_index, 2, P);
  }
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  //GenerateCase(0, 5, -9, 9, -9, 9, generator);
  GenerateGroup(0, 10000, generator);
  GenerateGroup(1, 20000, generator);
  GenerateGroup(2, 25000, generator);
  GenerateGroup(3, 30000, generator);
  // Give extra points to the heuristic
  for(int i=0;i<3;++i) {
    const std::vector<Point> P = GenerateSparse(30000, generator);
    WriteCase(4, i, P);
  }
}

void Solve() {
  int32_t N;
  std::cin >> N;
  std::vector<Point> P(N);
  for(int i=0;i<N;++i) {
    Point& p = P[i];
    std::cin >> p.x >> p.y;
  }
  //std::cout << FindClosestPairSlowPlusHeuristic(P) << std::endl;
  std::cout << FindClosestPairHeuristic(P) << std::endl;    
  
}

int main() {
  GenerateCases();
  //Solve();
  return 0;
}





