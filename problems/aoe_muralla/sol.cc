#include <iostream>
#include <vector>
#include <set>
#include <cassert>

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
    bool operator <(const Point &Q) const{
      if(x == Q.x){
          return y < Q.y;
      }
      return x < Q.x;
    }
};

struct Segment{
    Point P, Q;
    Segment(const Point &_P, const Point &_Q){
        P = _P;
        Q = _Q;
    }
    
    bool Contains(const Point &R) const{
      // First check if the point is in the segment's range
      if(R.x < std::min(P.x, Q.x) || std::max(P.x, Q.x) < R.x){
          return false;
      }
      if(R.y < std::min(P.y, Q.y) || std::max(P.y, Q.y) < R.y){
          return false;
      }
      //If the triangle P,Q,R is degenerated then they're collinear
      bool in_line = (R-P).Cross(Q-P) == 0;
      return in_line;
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

void Validate(const std::vector<Point>& T, const Point& S,const std::vector<Point>& A) {
  std::set<Point> all_points;
  all_points.insert(S);
  all_points.insert(T.begin(), T.end());
  all_points.insert(A.begin(), A.end());
  assert(all_points.size() == A.size()+4);

  std::vector<Segment> segments = {Segment(T[0], T[1]), Segment(T[1], T[2]), Segment(T[2], T[0])};
  for(const Segment& segment : segments) {
    assert(!segment.Contains(S));
    for(const Point& p : A) {
      assert(!segment.Contains(p));
    }
  }
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

int main() {
  std::vector<Point> T(3);
  for(int i=0;i<3;++i) {
    std::cin >> T[i].x >> T[i].y;
  }
  Point S;
  std::cin >> S.x >> S.y;
  int N;
  std::cin >> N;
  std::vector<Point> A(N);
  for(int i=0;i<N;++i) {
    std::cin >> A[i].x >> A[i].y;
  }
  Validate(T, S, A);
  std::cout << Solve(T, S, A) << std::endl;
  return 0;
}
