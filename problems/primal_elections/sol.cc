#include <vector>
#include <iostream>
#include <map>

void CountVotes(int n, std::map<int, int>& counts) {
  for(int i=2; (n > 1) && (i*i <= n); ++i) {
    bool divisible = false;
    while(n % i == 0) {
      divisible = true;
      n/=i;
    }
    if(divisible) {
      counts[i]++;
    }
  }
  if(n>1) {
    // Now n is prime.
    counts[n]++;
  }
}

std::pair<int, int> Solve(const std::vector<int>& votes) {
  std::map<int, int> C;
  for(const int v : votes) {
    CountVotes(v, C);
  }
  
  std::pair<int, int> best = std::make_pair(-1, -1);
  bool multiple_solutions = false;
  for(const auto&[p, c] : C) {
    if(best.second == -1 || best.second < c) {
      best = {p, c};
      multiple_solutions = false;
    } else if (best.second == c) {
      multiple_solutions = true;
    }
  }
  if (multiple_solutions) {
    // Detect wrong input case.
    return {-1,-1};
  }
  return best;
}

int main() {
  int V;
  std::cin >> V;
  std::vector<int> v(V);
  for(int i=0;i<V;++i) {
    std::cin>>v[i];
  }
  std::pair<int, int> sol = Solve(v);
  std::cout << sol.first << " " << sol.second << std::endl;
  return 0;
}

