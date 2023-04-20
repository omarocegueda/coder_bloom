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

int64_t FindClosestPairSlowPlusHeuristic(const std::vector<Point>& P) {
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
  std::uniform_int_distribution<int64_t> distribution_x(min_x, max_x);
  std::uniform_int_distribution<int64_t> distribution_y(min_y, max_y);
  return Point(distribution_x(generator), distribution_y(generator));
}



void GenerateCase(const int case_index, const int N, 
                  const int64_t min_x, const int64_t max_x,
                  const int64_t min_y, const int64_t max_y,
                  std::default_random_engine& generator, bool fail_heuristic) {
  assert(N <= kMaxPoints);
  assert(kMinPos <= min_x <= kMaxPos);
  assert(kMinPos <= max_x <= kMaxPos);
  assert(kMinPos <= min_y <= kMaxPos);
  assert(kMinPos <= max_y <= kMaxPos); 
  
  bool acceptable = false;
  int64_t sol = -1;
  std::vector<Point> P;
  while(!acceptable) {
    P.clear();
    P.reserve(N);
    // Generate random points
    std::set<Point, PointCmpY> S;
    while(S.size() < N) {
      S.insert(GenerateInRectangle(min_x, max_x, min_y, max_y, generator));
    }
    for(const Point& p : S) {
      P.push_back(p);
    }
    {
      std::random_device rd;
      std::mt19937 g(rd());
      std::shuffle(P.begin(), P.end(), g);
    }
    // Official solution
    auto temp = P;
    sol = FindClosestPairFast(temp);
    // Heuristic
    temp = P;
    int64_t sol_h = FindClosestPairHeuristic(temp);
    if(fail_heuristic && sol_h == sol) {
      std::cerr << "Unacceptable, heuristic passes"<<std::endl;
    } else {
      acceptable = true;
    }    
  }
  
  // Compare against brute force
  const int64_t sol_bf = FindClosestPairSlow(P);
  
  // Generate official solution
  
  std::cerr << "Case "<<case_index<<": sol="<<sol<<", sol_bf="<<sol_bf<<std::endl;
  assert(sol == sol_bf);
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    
    F << N << std::endl;
    for(const Point& p : P) {
      F << p.x << " " << p.y << std::endl;
    }
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    F << sol << std::endl;
    F.close();
  }

}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  //GenerateCase(0, 5, -9, 9, -9, 9, generator);
  GenerateCase(0, 1000, -1000000, 1000000, 0, 0, generator, false);
  GenerateCase(1, 1000, 0, 0, -1000000, 1000000, generator, false);
  GenerateCase(2, 10000, -1000000000, 1000000000, -1000000000, 1000000000, generator, true);
  GenerateCase(3, 15000, -1000000000, 1000000000, -1000000000, 1000000000, generator, true);
  GenerateCase(4, 20000, -10000000000, 10000000000, -10000000000, 10000000000, generator, true);
  GenerateCase(5, 25000, -1000000000000, 1000000000000, -1000000000000, 1000000000000, generator, true);
  GenerateCase(6, 30000, -1000000000000, 1000000000000, -1000, 1000, generator, false);
  GenerateCase(7, 30000, -1000, 1000, -1000000000000, 1000000000000, generator, false);
  GenerateCase(8, 30000, -1000000000000, 1000000000000, -1000000000000, 1000000000000, generator, true);
  GenerateCase(9, 30000, -1000000000000, 1000000000000, -1000000000000, 1000000000000, generator, true);
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
  GenerateCases();
  return 0;
}





