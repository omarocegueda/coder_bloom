#include <iostream>
#include <set>
const int32_t kMaxN = 100;
int A[kMaxN][kMaxN];
int32_t N, Tr, Tc, Cr, Cc;

struct Position {
  Position(int64_t dist_, int32_t r_, int32_t c_) {
    dist = dist_;
    r = r_;
    c = c_;
  }
  int64_t dist;
  int32_t r, c;
  const bool operator<(const Position& other) const{
    if(dist == other.dist) {
      if(r == other.r) {
        return c < other.c;
      }
      return r < other.r;
    }
    return dist < other.dist;
  }
};

int64_t Solve() {
  bool Visited[kMaxN][kMaxN];
  const int32_t dRow[4] = {-1, 0, 1, 0};
  const int32_t dCol[4] = {0, 1, 0, -1};
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      Visited[i][j] = false;
    }
  }
  std::set<Position> S;
  S.insert({0, Tr, Tc});
  while(!S.empty()) {
    const Position current = *S.begin();
    S.erase(S.begin());
    if(Visited[current.r][current.c]) {
      continue;
    }
    Visited[current.r][current.c] = true;
    if(current.r == Cr && current.c == Cc) {
      return current.dist;
    }
    for(int i=0;i<4;++i) {
      int32_t r = current.r + dRow[i];
      int32_t c = current.c + dCol[i];
      if(r<0 || r>=N || c<0 || c>=N) {
        continue;
      }
      int64_t delta = A[current.r][current.c] - A[r][c];
      S.insert({current.dist + delta * delta, r, c});
    }
  }
  return -1;
}

int main() {
  std::cin >> N >> Tr >> Tc >> Cr >> Cc;
  --Tr;
  --Tc;
  --Cr;
  --Cc;
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      std::cin >> A[i][j];
    }
  }
  std::cout << Solve() << std::endl;
  return 0;
}



