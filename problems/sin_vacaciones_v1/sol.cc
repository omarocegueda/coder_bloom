#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
#include <cassert>
#include <random>
#include <fstream>
#include <sstream>

struct Interval {
  Interval(const int64_t a, const int64_t b):begin(a), end(b) {}
  Interval():Interval(0,0) {}
  bool operator < (const Interval& other) const {
    if(end == other.end) {
      return begin < other.begin;
    }
    return end < other.end;
  }
  bool Intersects(const Interval& other) const {
    return std::max(begin, other.begin) < std::min(end, other.end); 
  }
  int64_t begin;
  int64_t end;
};


// Assumes C is sorted by increasing `end`
bool Doable(const Interval& a, const std::vector<Interval>& C) {
  std::size_t N = C.size();
  if(C[N-1].end <= a.begin) {
    // All classes end before `a` starts
    return true;
  }
  if(C[0].begin >= a.end) {
    // All classes start after `a` ends
    return true;
  }
  if(a.Intersects(C[0])) {
    return false;
  }
  if(a.Intersects(C[N-1])) {
    return false;
  }

  // Find the last class that ends before `a` starts
  int32_t left = 0; // We know that C[left] is fully before `a`
  int32_t right = N-1; // We know that C[right] is fully after `a`
  while(left+1<right) {
    int32_t mid = (left+right) / 2;
    if(C[mid].end <= a.begin) {
      left = mid;
    } else {
      right = mid;
    }
  }
  // C[left] ends before `a` starts
  return a.end <= C[left+1].begin; // C[left+1] starts after `a` ends.
}

int32_t GetMaxActivities(const std::vector<Interval>& A) {
  //std::cerr << "Selected: "<<std::endl;
  int64_t last_ended = std::numeric_limits<int64_t>::min();
  int32_t total_selected = 0;
  for(const Interval& a : A) {
    if(last_ended <= a.begin) {
      //std::cerr << "["<< a.begin<<","<<a.end<<")"<<std::endl;
      ++total_selected;
      last_ended = a.end;
    }
  }
  return total_selected;
}

void Print(const Interval& a) {
  std::cerr << "["<<a.begin << ","<<a.end<<")" << std::endl;
}

void VerifyNonIntersecting(std::vector<Interval>& A) {
  std::sort(A.begin(), A.end());
  assert(A[0].begin < A[0].end);
  for(int i=1;i<A.size();++i) {
    if(A[i-1].end > A[i].begin) {
      Print(A[i-1]);
      Print(A[i]);
    }
    assert(A[i-1].end <= A[i].begin);
    assert(A[i].begin < A[i].end);
  }
}

int64_t Solve(const int32_t N, std::vector<Interval>C, const int32_t M, std::vector<Interval>& A, const int64_t fun) {
  assert(N>0);
  assert(N<=20000);
  assert(M>0);
  assert(M<=20000);
  assert(N==C.size());
  assert(M==A.size());
  VerifyNonIntersecting(C); // Will sort C
  VerifyNonIntersecting(A); // Will sort A
  if(fun <= 0) {
    return 0;
  }
  int64_t prev_end = std::numeric_limits<int64_t>::min();
  int64_t n_doable = 0;
  for(const Interval& a : A) {
    if(Doable(a, C)) {
      ++n_doable;
    } 
  }
  return n_doable*fun;
}


void Solve() {
  int32_t N;
  std::cin >> N;
  std::vector<Interval> C(N);
  for(Interval& c : C) {
    std::cin >> c.begin >> c.end;
    ++c.end;
  }
  int32_t M;
  std::cin >> M;
  std::vector<Interval> A(M);
  int64_t fun;
  for(Interval& a : A) {
    std::cin >> a.begin >> a.end >> fun;
    assert(a.begin<=a.end);
    ++a.end;
  }
  const int64_t sol = Solve(N, C, M, A, fun);
  std::cout << sol << std::endl;
}

int main() {
  Solve();
  return 0;
}