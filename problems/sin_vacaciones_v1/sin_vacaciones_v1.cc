#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>
#include <cassert>
#include <random>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>

const bool kDoShuffle = true;
const int64_t kMinTime = -1000000000000000000ll;
const int64_t kMaxTime = 1000000000000000000ll;


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

int64_t Solve(const int32_t N, std::vector<Interval>C, const int32_t M, std::vector<Interval>& A, const int64_t fun) {
  assert(N>0);
  assert(N<=20000);
  assert(M>0);
  assert(M<=20000);
  assert(N==C.size());
  assert(M==A.size());
  if(fun <= 0) {
    return 0;
  }
  std::sort(C.begin(), C.end());
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
    ++a.end;
  }
  const int64_t sol = Solve(N, C, M, A, fun);
  std::cout << sol << std::endl;
}

void WriteCase(const int32_t case_index, const int32_t N, std::vector<Interval>&C, const int32_t M, std::vector<Interval>&A, const int32_t fun) {
  assert(N == C.size());
  assert(M == A.size());
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    std::ofstream F;
    F.open (os.str());
    if(kDoShuffle) {
      std::random_shuffle(C.begin(), C.end());
    }
    F << N << std::endl;
    for(const Interval& c : C) {
      F << c.begin << " " << c.end-1 << std::endl;
    }
    if(kDoShuffle) {
      std::random_shuffle(A.begin(), A.end());
    }
    F << M << std::endl;
    for(const Interval& a : A) {
      F << a.begin << " " << a.end-1 << " " << fun << std::endl;
    }
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    const int64_t sol = Solve(N, C, M, A, fun);
    F << sol << std::endl;
    F.close();
  }
}

std::vector<Interval> PartitionRange(const int32_t N, const int64_t min_time, const int64_t max_time, std::default_random_engine& generator) {
  const int64_t kMaxDelta = (max_time - min_time) / (2*N+1);
  assert(kMaxDelta>=1);
  std::uniform_int_distribution<int64_t> uniform_interval_duration(2, kMaxDelta);
  std::vector<Interval> I(2*N+1); // N classes and N+1 free intervals
  I[0].begin = min_time + uniform_interval_duration(generator);
  I[0].end = I[0].begin + uniform_interval_duration(generator);
  for(int32_t i=1; i<=2*N; ++i) {
    I[i].begin = I[i-1].end + uniform_interval_duration(generator);
    I[i].end = I[i].begin + uniform_interval_duration(generator);
    assert(I[i].begin<I[i].end);
  }
  return I;
}

void GenerateRandomCase(const int32_t case_index, const int32_t N, const int32_t m_in, const int32_t m_out, const int32_t m_across, const int64_t fun,
                  std::default_random_engine& generator, const int64_t min_time, const int64_t max_time) {
  std::cerr << "Generating Random Case: "<<case_index <<std::endl;
  assert(min_time <= max_time);
  const int64_t kMaxDelta = (max_time - min_time) / (2*N+1);
  assert(kMaxDelta>=1);

  std::uniform_int_distribution<int64_t> uniform_interval_duration(2, kMaxDelta);
  std::vector<Interval> I = PartitionRange(N, min_time, max_time, generator);
  // Select odd intervals as classes.
  std::vector<Interval> C;
  C.reserve(N);
  for(int32_t i=0;i<N; ++i) {
    C.push_back(I[2*i+1]);
  }

  std::vector<Interval> A;
  // Insert activities fully contained within class/free intervals.
  for(bool within_class : {false, true}) {
    for(int32_t i=0; i<(within_class?m_in:m_out); ++i) {
      std::uniform_int_distribution<int64_t> uniform_interval(0, within_class?(N-1):N);
        const int32_t selected = 2 * uniform_interval(generator) + within_class;
        const int64_t delta = I[selected].end - I[selected].begin;
        assert(delta>=2);
        std::uniform_int_distribution<int64_t> uniform_activity_duration(1, delta/2);
        const int64_t a_begin = I[selected].begin + uniform_activity_duration(generator);
        const int64_t a_end = a_begin + uniform_activity_duration(generator);
        assert(a_begin<a_end);
        A.push_back(Interval(a_begin, a_end));
    }
  }
  {
    // Insert activities across classes
    std::uniform_int_distribution<int32_t> uniform_interval(0, 2*N);
    for(int32_t i=0;i<m_across;++i) {
      int32_t a_selected = uniform_interval(generator);
      int32_t b_selected = a_selected;
      while(b_selected == a_selected) {
        b_selected = uniform_interval(generator);
      }
      if(b_selected<a_selected) {
        std::swap(a_selected, b_selected);
      }
      assert(I[a_selected] < I[b_selected]);
      std::uniform_int_distribution<int64_t> uniform_begin(I[a_selected].begin, I[a_selected].end-1);
      std::uniform_int_distribution<int64_t> uniform_end(I[b_selected].begin, I[b_selected].end-1);

      Interval interval(uniform_begin(generator), uniform_end(generator));

      assert(interval.begin<interval.end);
      A.push_back(interval);
    }
  }
  
  // Select non-intersecting activities
  std::sort(A.begin(), A.end());
  int64_t last_ended = std::numeric_limits<int64_t>::min();
  std::vector<Interval> non_intersecting;
  for(const Interval& a : A) {
    if(last_ended <= a.begin) {
      non_intersecting.push_back(a);
      last_ended = a.end;
    }
  }
  WriteCase(case_index, N, C, non_intersecting.size(), non_intersecting, fun);
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  GenerateRandomCase(0, /*N=*/1000,  500, 10, 10,          /*fun=*/3, generator, 0, 1000000);
  GenerateRandomCase(1, /*N=*/10000,  10000, 50,    50,    /*fun=*/ 3999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(2, /*N=*/10000,  50,    10000, 50,    /*fun=*/ 2999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(3, /*N=*/10000,  50,    50,    10000, /*fun=*/ 1999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(4, /*N=*/12000,  11000, 500,   500,   /*fun=*/ 799999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(5, /*N=*/12000,  500,   11000, 500,   /*fun=*/ 599999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(6, /*N=*/12000,  500,   500,   11000,   /*fun=*/ 299999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(7, /*N=*/20000,  19000, 500,   500,   /*fun=*/ 699999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(8, /*N=*/20000,  500,   19000, 500,   /*fun=*/ 499999993, generator, kMinTime, kMaxTime);
  GenerateRandomCase(9, /*N=*/20000,  500,   500,   19000, /*fun=*/1000000000, generator, kMinTime, kMaxTime);
  GenerateRandomCase(10, /*N=*/10,  3, 3, 3,          /*fun=*/-1000, generator, 0, 1000);
  GenerateRandomCase(11, /*N=*/10,  3, 3, 3,          /*fun=*/0, generator, 0, 1000); 
}

int main() {
  GenerateCases();
  //Solve();
  return 0;
}