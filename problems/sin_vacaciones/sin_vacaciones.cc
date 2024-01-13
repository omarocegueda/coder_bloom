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

int32_t GetMaxActivities(const std::vector<Interval>& A, const bool debug) {
  int64_t last_ended = std::numeric_limits<int64_t>::min();
  int32_t total_selected = 0;
  std::vector<Interval> selected;
  for(const Interval& a : A) {
    if(last_ended <= a.begin) {
      ++total_selected;
      selected.push_back(a);
      last_ended = a.end;
    }
  }
  if(debug) {
    std::sort(selected.begin(), selected.end());
    for(const Interval& s : selected) {
      std::cerr << "["<<s.begin<<","<<s.end+1<<"]" << std::endl;
    }
    std::cerr << "Selected="<<selected.size() << std::endl;
  }
  return total_selected;
}

std::pair<int64_t, int64_t> Solve(const int32_t N, std::vector<Interval>C, const int32_t M, std::vector<Interval>& A, const int64_t fun) {
  assert(N>0);
  assert(N<=20000);
  assert(M>0);
  assert(M<=20000);
  assert(N==C.size());
  assert(M==A.size());
  if(fun <= 0) {
    return {0, 0};
  }
  std::sort(C.begin(), C.end());
  std::sort(A.begin(), A.end());
  std::vector<Interval> F;
  int64_t prev_end = std::numeric_limits<int64_t>::min();
  for(const Interval& a : A) {
    if(Doable(a, C)) {
      F.push_back(a);
    } 
  }
  return {fun*GetMaxActivities(A, false), fun*GetMaxActivities(F, false)};
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
  const std::pair<int64_t, int64_t> sol = Solve(N, C, M, A, fun);
  std::cout << sol.first<<" "<< sol.second << std::endl;
}

//////////////////////////////////////////// Pablo's solution /////////////////////////////////////////////////////

using Intervalos = std::vector<std::pair<int64_t,int64_t>>;

int solve(int mx, const Intervalos& C, const Intervalos& A) {
  std::vector<int> dp(mx);
  std::unordered_set<int> clases;
  std::vector<std::vector<int>> add(mx);
  std::vector<std::vector<int>> rem(mx);
  std::vector<std::vector<int>> start(mx);
  std::vector<std::vector<int>> stop(mx);
  for (int i = 0; i != C.size(); ++i) {
    auto [a, b] = C[i];
    add[a].push_back(i);
    rem[b].push_back(i);
  }
  for (int i = 0; i != A.size(); ++i) {
    auto [a, b] = A[i];
    start[a].push_back(i);
    stop[b].push_back(i);
  }
  int rv = 0;
  std::unordered_set<int> actividades;
  for (int i = 0; i != mx; ++i) {
    clases.insert(add[i].begin(), add[i].end());
    if (i > 0) dp[i] = std::max(dp[i], dp[i-1]);
    if (!clases.empty()) {
      actividades.clear();
      for (auto j : rem[i]) clases.erase(j);
    } else {
      // Iniciar actividades
      actividades.insert(start[i].begin(), start[i].end());
      // Terminar actividades
      for (int ai : stop[i]) {
        // cerr << i << ": Terminando " << ai << endl;
        if (actividades.erase(ai)) {
          auto &r = dp[A[ai].second + 1];
          r = std::max(r, dp[A[ai].first] + 1);
        }
      }
    }
    rv = std::max(rv, dp[i]);
  }
  // cerr << "Total " << rv << endl;
  return rv;
}

void collect(std::map<int64_t,int>& mp, Intervalos& v) {
  for (auto [a, b] : v) {
    mp.emplace(a, -1);
    mp.emplace(b, -1);
    mp.emplace(b + 1, -1);
  }
}
void compress(std::map<int64_t,int>& mp, Intervalos& v) {
  for (auto &[a, b] : v) {
    a = mp[a];
    b = mp[b];
  }
}

void assign(std::map<int64_t,int>& mp) {
  int i = 0;
  for (auto& [k, v] : mp) v = i++;
}

std::pair<int64_t, int64_t> pablo(const int n, std::vector<std::pair<int64_t,int64_t>>& C, const int m, std::vector<std::pair<int64_t,int64_t>>& A, int64_t f) {
  if (f<=0) {
    return {0,0};
  }
  std::map<int64_t, int> mp;
  collect(mp, A);
  collect(mp, C); 
  assign(mp); 
  compress(mp, A);
  compress(mp, C);
  int sin_clases = solve(mp.size(), {}, A);
  int con_clases = solve(mp.size(), C, A);
  return {f * sin_clases, f * con_clases};
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void WriteCase(const int32_t case_index, const int32_t N, std::vector<Interval>&C, const int32_t M, std::vector<Interval>&A, const int32_t fun) {
  assert(N == C.size());
  assert(M == A.size());
  Intervalos c_pairs;
  Intervalos a_pairs;
  for(const auto c : C) {
    c_pairs.push_back({c.begin, c.end-1});
  }
  for(const auto a : A) {
    a_pairs.push_back({a.begin, a.end-1});
  }
  const std::pair<int64_t, int64_t> validation = pablo(N, c_pairs, M, a_pairs, fun);
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
    const std::pair<int64_t, int64_t> sol = Solve(N, C, M, A, fun);
    F << sol.first << " " << sol.second << std::endl;
    F.close();
    if(sol.first!=validation.first || sol.second!=validation.second) {
      std::cerr << "Diff found: sol={"<<sol.first<<","<<sol.second<<"}, validation={"<<validation.first<<","<<validation.second<<"}"<<std::endl;
      assert(false);
    }
  }
}

void GenerateRandomCase(const int32_t case_index, const int32_t N, const int32_t m_in, const int32_t m_out, const int32_t m_across, const int64_t fun,
                  std::default_random_engine& generator, const int64_t min_time, const int64_t max_time) {
  std::cerr << "Generating Random Case: "<<case_index <<std::endl;
  assert(min_time <= max_time);
  const int64_t kMaxDelta = (max_time - min_time) / (2*N+1);
  assert(kMaxDelta>=1);
  const int M = m_in + m_out + m_across;

  std::uniform_int_distribution<int64_t> uniform_interval_duration(2, kMaxDelta);
  std::vector<Interval> I(2*N+1); // N classes and N+1 free intervals
  I[0].begin = min_time + uniform_interval_duration(generator);
  I[0].end = I[0].begin + uniform_interval_duration(generator);
  for(int32_t i=1; i<=2*N; ++i) {
    I[i].begin = I[i-1].end + uniform_interval_duration(generator);
    I[i].end = I[i].begin + uniform_interval_duration(generator);
    assert(I[i].begin<I[i].end);
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
  std::vector<Interval> C;
  C.reserve(N);
  for(int32_t i=0;i<N; ++i) {
    C.push_back(I[2*i+1]);
  }
  WriteCase(case_index, N, C, M, A, fun);
}

void GenerateNestedCase(const int32_t case_index, const int32_t N, const int32_t M, const int64_t fun,
                        std::default_random_engine& generator, const int64_t min_time, const int64_t max_time) {
  std::cerr << "Generating Nested Case: "<<case_index <<std::endl;
  assert(min_time <= max_time);
  const int64_t kMaxDelta = (max_time - min_time) / (2*(2*N+1)); // divide the first half of [min_time, max_time] in 2N sub-intervals (classes + free intervals)
  assert(kMaxDelta>=1);
  assert((max_time-min_time) >= 4*M ); // The second half of the interval must be at least as large as the longest nested interval (2*M)
  std::uniform_int_distribution<int64_t> uniform_interval_duration(1, kMaxDelta);
  std::vector<Interval> I(2*N+1); // N classes and N+1 free intervals
  I[0].begin = min_time + uniform_interval_duration(generator);
  I[0].end = I[0].begin + uniform_interval_duration(generator);
  for(int32_t i=1; i<=2*N; ++i) {
    I[i].begin = I[i-1].end + uniform_interval_duration(generator);
    I[i].end = I[i].begin + uniform_interval_duration(generator);
  }
  std::vector<Interval> C;
  C.reserve(N);
  for(int32_t i=0;i<N; ++i) {
    C.push_back(I[2*i]);
  }
  std::vector<Interval> A(M);
  A[0]=Interval((min_time+max_time)/2, max_time);
  for(int32_t i=1; i<M; ++i) {
    A[i]=Interval(A[i-1].begin+1, A[i-1].end-1);
  }
  WriteCase(case_index, N, C, M, A, fun);
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

  // --
  GenerateNestedCase(10, /*N=*/5000, /*M=*/5000,          /*fun=*/236487264, generator, kMinTime, kMaxTime);
  GenerateNestedCase(11, /*N=*/10000, /*M=*/10000,          /*fun=*/132486266, generator, kMinTime, kMaxTime);
  GenerateNestedCase(12, /*N=*/20000, /*M=*/20000,          /*fun=*/32486266, generator, kMinTime, kMaxTime);

  //
  GenerateRandomCase(13, /*N=*/10,  3, 3, 3,          /*fun=*/-1000, generator, 0, 1000);
  GenerateRandomCase(14, /*N=*/10,  3, 3, 3,          /*fun=*/0, generator, 0, 1000); 
}

int main() {
  GenerateCases();
  //Solve();
  return 0;
}