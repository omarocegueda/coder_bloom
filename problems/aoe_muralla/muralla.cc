#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <random>
#include <sstream>
#include <fstream>

const int64_t kMinCoord = -1000;
const int64_t kMaxCoord = 1000;
const int64_t kMaxVillagers = 100;

struct Point{
    int64_t x, y;
    Point():x(0),y(0){}
    Point(const int64_t _x, const int64_t _y):x(_x), y(_y){}
    int64_t Cross(const Point &P)const{
        return x * P.y - P.x * y;
    }
    Point operator - (const Point &P)const{
        return Point(x - P.x, y - P.y);
    }
    Point operator + (const Point &P)const{
        return Point(x + P.x, y + P.y);
    }
};

bool Inside(const std::vector<Point>& T, const Point& P) {
  bool has_positive = false;
  bool has_negative = false;
  bool has_zero = false;
  for(int i=0;i<3;++i) {
    const int ii = (i + 1) % 3;
    const int cp = (T[ii] - T[i]).Cross(P - T[i]); 
    if(cp == 0) {
      has_zero = true;
    } else if (cp < 0) {
      has_negative = true;
    } else {
      has_positive = true;
    }
  }
  const bool is_inside = !(has_positive && has_negative); 
  if(has_zero) {
    // Sanity check
    assert(!is_inside);
  }
  return is_inside;
}

int Solve(const std::vector<Point>& T, const Point& S,const std::vector<Point>& A) {
  int n_inside = 0;
  int n_outside = 0;
  for(const Point& a : A) {
    if(Inside(T, a)) {
      ++n_inside;
    } else {
      ++n_outside;
    }
  }
  if(Inside(T, S)) {
    return n_outside;
  }
  return n_inside;
}

Point GetRandomPointInside(const std::vector<Point>& T, std::default_random_engine& generator) {
  int64_t min_x = T[0].x;
  int64_t min_y = T[0].y;
  int64_t max_x = T[0].x;
  int64_t max_y = T[0].y;
  for(const Point& p : T) {
    min_x = std::min(min_x, p.x);
    min_y = std::min(min_y, p.y);
    max_x = std::max(max_x, p.x);
    max_y = std::max(max_y, p.y);
  }
  std::uniform_int_distribution<int64_t> uniform_x(min_x, max_x);
  std::uniform_int_distribution<int64_t> uniform_y(min_y, max_y);
  Point p(uniform_x(generator), uniform_y(generator));
  while(!Inside(T, p)) {
    p = Point(uniform_x(generator), uniform_y(generator));
  }
  return p;
}

bool InBounds(const Point& P) {
  return (kMinCoord <= P.x && P.x <= kMaxCoord) && (kMinCoord <= P.y && P.y <= kMaxCoord);
}

std::vector<Point> GetColinearPoints(const std::vector<Point>& T) {
  std::vector<Point> points;
  for(int i=0;i<3;++i) {
    const Point& a = T[i];
    const Point& b = T[(i+1)%3];
    const Point c = b+(b-a);
    if(InBounds(c)) {
      points.push_back(c);
    }
    const Point d = a+(a-b);
    if(InBounds(d)) {
      points.push_back(d);
    }
  }
  return points;
}

Point GetRandomPointOutside(const std::vector<Point>& T, std::default_random_engine& generator) {
  std::uniform_int_distribution<int64_t> uniform(kMinCoord, kMaxCoord);
  Point p(uniform(generator), uniform(generator));
  while(Inside(T, p)) {
    p = Point(uniform(generator), uniform(generator));
  }
  return p;
}

void WriteCase(const int case_index, const std::vector<Point>& T, const Point& S, const std::vector<Point>& A, const int sol) {
  // Write input
  {
    std::ostringstream os;
    os << "case_" << case_index << ".in";
    std::ofstream F;
    F.open (os.str());
    for(const Point& p : T) {
      F << p.x << " " << p.y << std::endl;
    }
    F << S.x << " " << S.y << std::endl;
    F << A.size() << std::endl;
    for(const Point& p : A) {
      F << p.x << " " << p.y << std::endl;
    }
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os << "case_"<< case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    F << sol << std::endl;
    F.close();
  }
}

void GenerateRandomTriangle(std::default_random_engine& generator, std::vector<Point>& T) {
  std::uniform_int_distribution<int64_t> uniform(kMinCoord, kMaxCoord);
  do {
    std::cerr << "Generating triangle"<<std::endl;
    for(int i=0; i<3; ++i) {
      T[i] = Point(uniform(generator), uniform(generator));
      std::cerr << "("<<T[i].x << ","<<T[i].y<<") ";
    }
    std::cerr << std::endl;

  } while((T[1] - T[0]).Cross(T[2] - T[0]) == 0);
}


void GenerateCase(const int case_index, const bool soldier_in, const int n_inside, const int n_outside, bool add_colinear, std::default_random_engine& generator) {
  std::cerr << "Generating case "<< case_index <<std::endl;
  const int N = n_inside + n_outside;
  assert(1<=N && N<=kMaxVillagers);
  // Generate the triangle
  std::vector<Point> T(3);
  GenerateRandomTriangle(generator, T);
  // Generate the soldier
  const Point S = soldier_in?GetRandomPointInside(T, generator):GetRandomPointOutside(T, generator);
  
  // Add colinear points
  std::vector<Point> A;
  int out_cnt = 0;
  if(add_colinear) {
    const std::vector<Point> colinear = GetColinearPoints(T);
    for(const Point& p : colinear) {
      if(out_cnt == n_outside) {
        break;
      }
      A.push_back(p);
      ++out_cnt;
    }
  }
  std::cerr << "Added "<< out_cnt<<" colinear"<<std::endl;
  // Generate the rest of the villagers
  std::bernoulli_distribution bernoulli(0.5);
  int in_cnt = 0;
  std::cerr << "Generating villagers"<<std::endl;
  for(int i=0;A.size()<N;++i) {
    if(in_cnt == n_inside) {
      A.push_back(GetRandomPointOutside(T, generator));
      ++out_cnt;
    } else if (out_cnt == n_outside) {
      A.push_back(GetRandomPointInside(T, generator));
      ++in_cnt;
    } else if(bernoulli(generator)) {
      A.push_back(GetRandomPointOutside(T, generator));
      ++out_cnt;
    } else {
      A.push_back(GetRandomPointInside(T, generator));
      ++in_cnt;
    }
  }
  const int sol = Solve(T, S, A);
  if(soldier_in) {
    assert(sol == n_outside);
  } else {
    assert(sol == n_inside);
  }
  WriteCase(case_index, T, S, A, sol);
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());

  GenerateCase(0, false, 5, 2, false, generator);
  GenerateCase(1, true, 5, 2, false, generator);
  GenerateCase(2, false, 5, 2, true, generator);
  GenerateCase(3, true, 5, 2, true, generator);

  GenerateCase(4, false, 14, 9, false, generator);
  GenerateCase(5, true, 14, 9, false, generator);
  GenerateCase(6, false, 14, 9, true, generator);
  GenerateCase(7, true, 14, 9, true, generator);

  GenerateCase(8, false, 22, 4, false, generator);
  GenerateCase(9, true, 22, 4, false, generator);
  GenerateCase(10, false, 22, 4, true, generator);
  GenerateCase(11, true, 22, 4, true, generator);

  GenerateCase(12, false, 9, 51, false, generator);
  GenerateCase(13, true, 9, 51, false, generator);
  GenerateCase(14, false, 9, 51, true, generator);
  GenerateCase(15, true, 9, 51, true, generator);

  GenerateCase(16, false, 17, 83, false, generator);
  GenerateCase(17, true, 17, 83, false, generator);
  GenerateCase(18, false, 17, 83, true, generator);
  GenerateCase(19, true, 17, 83, true, generator);
}

int main() {
  GenerateCases();
  return 0;
}
