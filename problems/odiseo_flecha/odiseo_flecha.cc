#include <stdio.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <numeric>

const int64_t kMinX = 1;
const int64_t kMaxX = 100000000;
const int64_t kMinY = 0;
const int64_t kMaxY = 100000000;

int32_t Solve(const int32_t B, const int32_t N, const std::vector<int32_t>& X, const std::vector<int32_t>& Y) {
  std::map<int64_t, int32_t> M;
  for(int i=0;i<N;++i) {
    const int32_t g = std::gcd((Y[i]-B), X[i]);
    
    const int64_t key = (static_cast<int64_t>((Y[i]-B)/g)<<32) | (X[i]/g);
    
    // std::cerr<<"JOOG: "<<(Y[i]-B)/g<<", "<<X[i]/g<<" -> "<<key<<std::endl;
    
    M[key] ++;
  }
  int32_t best = 0;
  for(const auto& count : M) {
    // std::cerr<<"JOOG: ["<<(count.first>>32)<<", "<<(count.first&(static_cast<int64_t>(1)<<32)-1)<<"]->"<<count.second<<std::endl;
    best = std::max(best, count.second);
  }
  return best;
}

int32_t SolveSlow(const int32_t B, const int32_t N, const std::vector<int32_t>& X, const std::vector<int32_t>& Y) {
  int best = 0;
  for(int i=0;i<N;++i) {
    const int64_t dxi = X[i];
    const int64_t dyi = Y[i] - B;
    int opt = 1;
    for(int j=i+1;j<N;++j) {
      const int64_t dxj = X[j];
      const int64_t dyj = Y[j] - B;
      if(dyi * dxj == dxi * dyj) {
        ++opt;
      }
    }
    if(best < opt) {
      best = opt;
    }
  }
  return best;
}

void SaveCase(const int32_t case_index, const int32_t B, const int32_t N, const std::vector<int32_t>& X, const std::vector<int32_t>& Y, const int32_t sol){
  // Generate input
  {
    std::ostringstream os;
    os << "case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", B, N);
    for(int i=0;i<N;++i) {
      fprintf(F, "%d %d\n", X[i], Y[i]);
    }
    fclose(F);
  }
  // Generate output
  {
    std::ostringstream os;
    os << "case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}

void GenerateNonColinear(const int32_t case_index, const int32_t N) {
  std::vector<int32_t> X(N);
  std::vector<int32_t> Y(N);
  for(int i=0;i<N;++i) {
    X[i] = 1 + i;
    Y[i] = N-i;
  }
  const int32_t B = N/2;
  const int32_t sol = Solve(B, N, X, Y);
  assert(sol == SolveSlow(B, N, X, Y));
  SaveCase(case_index, B, N, X, Y, sol);
}

void GenerateColinear(const int32_t case_index, const int32_t N) {
  std::vector<int32_t> X(N);
  std::vector<int32_t> Y(N);
  const int32_t B = N/2;
  for(int i=0;i<N;++i) {
    X[i] = 1 + i;
    Y[i] = B + 2 * X[i];
  }
  
  const int32_t sol = Solve(B, N, X, Y);
  assert(sol == SolveSlow(B, N, X, Y));
  SaveCase(case_index, B, N, X, Y, sol);
}



void GenerateRandomCase(const int32_t case_index, const int32_t B, const int32_t N, 
                        const int32_t max_dx, const int32_t min_m, const int32_t max_m, 
                        std::default_random_engine& generator) {
  std::cerr << "JOOG: Generating case with B="<<B<<", N="<<N<<std::endl;
  std::uniform_int_distribution<int64_t> uniform_dx(1, max_dx);
  std::uniform_int_distribution<int64_t> uniform_m(min_m, max_m);
    
  std::vector<int32_t> X(N);
  std::vector<int32_t> Y(N);
  std::set<std::pair<int32_t, int32_t>> S;
  for(int i=0;i<N;++i) {
    bool point_accepted = false;
    while(!point_accepted) {
      const int32_t dx = uniform_dx(generator);
      const int32_t m = uniform_m(generator);
      X[i] = dx + (i==0?0:X[i-1]);
      Y[i] = B + X[i] * m;
      point_accepted = true;
      if(X[i] < kMinX || X[i]> kMaxX || Y[i]<kMinY || Y[i]>kMaxY) {
        // Out of bounds
        //std::cerr << "JOOG: out of bounds"<<std::endl;
        point_accepted = false;
      } else if(S.find({X[i], Y[i]})!=S.end()) {
        // Already exists
        //std::cerr << "JOOG: repeated"<<std::endl;
        point_accepted = false;
      }
    }
    S.insert({X[i], Y[i]});
  }
  const int32_t sol = Solve(B, N, X, Y);
  if(N<=10000) {
    assert(sol == SolveSlow(B, N, X, Y));
  }
  SaveCase(case_index, B, N, X, Y, sol);
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  GenerateNonColinear(0, 100000);
  GenerateColinear(1, 100000);
  GenerateRandomCase(2, 35, 51,  50, -200, 200, generator);
  GenerateRandomCase(3, 88, 138,  100, -200, 200, generator);
  GenerateRandomCase(4, 350, 583,  100, -200, 200, generator);
  GenerateRandomCase(5, 1582, 955,  100, -200, 200, generator);
  GenerateRandomCase(6, 9234, 1203,  200, -200, 200, generator);
  GenerateRandomCase(7, 29012, 8343,  200, -200, 200, generator);
  GenerateRandomCase(8, 324091, 56123,  200, -200, 200, generator);
  GenerateRandomCase(9, 581238, 98621,  200, -200, 200, generator);
}

int main() {
  GenerateCases();
  return 0;
}
