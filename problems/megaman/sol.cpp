#include <string.h>

#include <iostream>
#include <vector>

const int kMaxBosses = 1000000;
const int kMaxDifficulty = 1000000;
int F[kMaxBosses];

struct Boss {
  Boss() {
  }
  int difficulty;
  int weakness;
};

int FindFirstBoss(int target, const std::vector<Boss>& bosses) {
  if(F[target]!=-1) {
    return F[target];
  }
  // Find the cycle
  int cycle_start = target;
  for(;F[cycle_start]==-1;cycle_start = bosses[cycle_start].weakness) {
    F[cycle_start] = -2;
  }
  int easiest = F[cycle_start]==-2?cycle_start:F[cycle_start];
  if(F[cycle_start]==-2) {
    // New cycle found. Find the easiest boss in the cycle
    for(int boss = bosses[cycle_start].weakness; boss != cycle_start; boss = bosses[boss].weakness) {
      if(bosses[boss].difficulty < bosses[easiest].difficulty) {
        easiest = boss;
      }
    }
  }
  // Propagate to the full group
  for(int boss = target; F[boss]==-2; boss = bosses[boss].weakness) {
    F[boss] = easiest;
  }
  return easiest;
}

int64_t Solve(const int N, const std::vector<Boss>& bosses) {
  memset(F, -1, sizeof(F));
  int64_t total = 0;
  for(int b=0;b<N;++b) {
    const int easiest = FindFirstBoss(b, bosses);
    if(easiest == b) {
      total += bosses[easiest].difficulty;
    } else {
      total += 1;
    }
  }
  return total;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<Boss> bosses(N);
  for(int i=0;i<N;++i) {
    Boss& boss = bosses[i];
    std::cin >> boss.difficulty >> boss.weakness;
  }
  std::cout << Solve(N, bosses) << std::endl;
  return 0;
}
