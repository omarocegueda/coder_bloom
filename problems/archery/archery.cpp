#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <unordered_set>
#include <vector>

const int64_t kMaxRadius = 1000000;
const int64_t kMaxPoints = 1000000;

struct Target {
  int64_t radius;
  int64_t points;
  Target() = default;
  Target(int64_t r, int64_t p): radius(r), points(p) {}
  const bool operator<(const Target& other) const {
    return radius < other.radius;
  }
};

struct Point {
  int64_t x, y;
  Point(): x(0), y(0) {}
  Point(int64_t x_, int64_t y_): x(x_), y(y_){}
};

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

int64_t Solve(const int32_t N, const std::vector<Target>& T, const int32_t M, const std::vector<int64_t>& R2) {
  int64_t total = 0;
  for(int64_t r2 : R2) {
    auto upper = std::upper_bound(T.begin(), T.end(), Target(r2, 0));
    if(upper != T.end()) {
      total += upper->points;
    }
  }
  return total;
}

void WriteCase(const int32_t case_index, const int N, const std::vector<Target>& T, const int M, const std::vector<Point>& P) {
  assert(N == T.size());
  assert(M == P.size());
  {
    // Write input 
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    std::ofstream F;
    F.open(os.str());
    F << N <<std::endl;
    for(const Target& t : T) {
      F << t.radius << " " << t.points << std::endl;
    }
    F << M << std::endl;
    for(const Point& p : P) {
      F << p.x << " " << p.y << std::endl;
    }
    F.close();
  }

  std::vector<Target> T2(N);
  for(int i=0;i<N;++i) {
    T2[i].points = T[i].points;
    T2[i].radius = T[i].radius*T[i].radius;
  }

  std::vector<int64_t> R2(M);
  for(int i=0;i<M;++i) {
    R2[i] = P[i].x*P[i].x + P[i].y*P[i].y;
  }
  std::sort(T2.begin(), T2.end());
  int64_t sol = Solve(N, T2, M, R2);
  int64_t sol_slow = SolveSlow(N, T2, M, R2);
  assert(sol == sol_slow);
  {
    // Write output
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open(os.str());
    F << sol <<std::endl;
    F.close();
  }
}

void GenerateCase(const int32_t case_index, const int32_t N, const int32_t M,
                  std::default_random_engine& generator) {
  std::cerr << "Generating case "<< case_index<<std::endl;
  std::uniform_int_distribution<int64_t> uniform_points(1, kMaxPoints);
  std::uniform_int_distribution<int64_t> uniform_radius(1, kMaxRadius);
  std::uniform_int_distribution<int64_t> uniform_position(-kMaxRadius, kMaxRadius);
  std::vector<Target> targets(N);
  std::unordered_set<int64_t> selected;
  for(int i=0;i<N;++i) {  
    targets[i].points = uniform_points(generator);
    do {
      targets[i].radius = uniform_radius(generator);
    } while(selected.find(targets[i].radius) != selected.end());
    selected.insert(targets[i].radius);
  }

  std::vector<Point> points(M);
  for(int i=0;i<M;++i) {
    points[i].x = uniform_position(generator);
    points[i].y = uniform_position(generator);
  }
  // Replace a few points
  std::uniform_int_distribution<int64_t> uniform_point(0, M-1);
  std::uniform_int_distribution<int64_t> uniform_target(0, N-1);
  std::bernoulli_distribution bernoulli(0.5);
  for(int iter=0;2*iter<M;++iter) {
    int32_t selected_point = uniform_point(generator);
    int32_t selected_target = uniform_target(generator);
    int32_t sign = uniform_target(generator)?1:-1;
    if(bernoulli(generator)) {
      // Add horizontal
      points[selected_point].x = sign * targets[selected_target].radius;
      points[selected_point].y = 0;
    } else {
      // Add vertical
      points[selected_point].x = 0;
      points[selected_point].y = sign * targets[selected_target].radius;
    }
  }
  WriteCase(case_index, N, targets, M, points);
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());

  GenerateCase(0, 1, 10, generator);
  GenerateCase(1, 10, 1, generator);
  GenerateCase(2, 1, 1, generator);
  GenerateCase(3, 30, 15, generator);
  GenerateCase(4, 15, 30, generator);
  GenerateCase(5, 90, 75, generator);
  GenerateCase(6, 100, 1000, generator);
  GenerateCase(7, 1000, 100, generator);
  GenerateCase(8, 850, 850, generator);
  GenerateCase(9, 1000, 1000, generator);
  GenerateCase(10, 1000, 10000, generator);
  GenerateCase(11, 10000, 1000, generator);
  GenerateCase(12, 8500, 8500, generator);
  GenerateCase(13, 10000, 10000, generator);
  GenerateCase(14, 1000, 100000, generator);
  GenerateCase(15, 100000, 1000, generator);
  GenerateCase(16, 10000, 100000, generator);
  GenerateCase(17, 100000, 10000, generator);
  GenerateCase(18, 85000, 85000, generator);
  GenerateCase(19, 100000, 100000, generator);
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

  int32_t M;
  std::cin >> M;
  std::vector<int64_t> R2(M);
  for(int i=0;i<M;++i) {
    int64_t x, y;
    std::cin >> x >> y;
    R2[i] = x*x + y*y;
  }
  std::cout << Solve(N, T2, M, R2) << std::endl;
}

int main() {
  GenerateCases();
  return 0;
  //Solve();
  //return 0;
}