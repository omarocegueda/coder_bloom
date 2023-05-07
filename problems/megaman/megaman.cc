#include <string.h>

#include <cassert>
#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <random>
#include <fstream>

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
  // std::cerr << "Finding cycle..." << std::endl;
  int cycle_start = target;
  while(F[cycle_start]==-1) {
    F[cycle_start] = -2;
    cycle_start = bosses[cycle_start].weakness;
  }
  if(F[cycle_start] != -2) {
    // Propagate to the full group
    // std::cerr << "Propagating to full group..." << std::endl;
    int boss = target;
    while(F[boss]==-2) {
      F[boss] = F[cycle_start];
      boss = bosses[boss].weakness;
    }
    return F[cycle_start];
  }
  // New cycle found
  // Find the easiest boss in the cycle
  // std::cerr << "Finding easiest boss in cycle..." << std::endl;
  int easiest = cycle_start;
  int boss = bosses[cycle_start].weakness;
  while(boss != cycle_start) {
    // std::cerr << "boss:"<<boss<<"!= cycle_start:"<<cycle_start << std::endl;
    if(bosses[boss].difficulty < bosses[easiest].difficulty) {
      easiest = boss;
    }
    boss = bosses[boss].weakness;
  }
  // Propagate to the full group
  // std::cerr << "Propagating to full group..." << std::endl;
  boss = target;
  while(F[boss]==-2) {
    F[boss] = easiest;
    boss = bosses[boss].weakness;
  }
  // std::cerr << "Done." << std::endl;
  return easiest;
}

int64_t Solve(const int N, const std::vector<Boss>& bosses) {
  memset(F, -1, sizeof(F));
  int64_t total = 0;
  for(int b=0;b<N;++b) {
    // std::cerr << "Optimizing for boss: " << b << std::endl;
    const int easiest = FindFirstBoss(b, bosses);
    // std::cerr << "Best for boss " << b << ": " << easiest <<std::endl;
    if(easiest == b) {
      total += bosses[easiest].difficulty;
    } else {
      total += 1;
    }
  }
  return total;
}

void Solve() {
  int N;
  std::cin >> N;
  std::vector<Boss> bosses(N);
  for(int i=0;i<N;++i) {
    Boss& boss = bosses[i];
    std::cin >> boss.difficulty >> boss.weakness;
  }
  std::cout << Solve(N, bosses) << std::endl;
  /*for(int i=0;i<N;++i) {
    std::cerr << i << ": "<< F[i] << ", diff:"<<bosses[F[i]].difficulty<<std::endl;
  }*/
}

void AddCycle(const int size, std::vector<Boss>& bosses, std::default_random_engine& generator) {
  // std::cerr << "Adding cycle of size "<< size<<std::endl;
  std::uniform_int_distribution<int64_t> uniform_difficulty(2, kMaxDifficulty);
  const int offset = bosses.size();
  bosses.resize(offset+size);
  for(int i=0;i<size;++i) {
    Boss& boss = bosses[offset+i];
    boss.difficulty = uniform_difficulty(generator);
    boss.weakness = offset + (i + 1) % size;
    assert(2<=boss.difficulty && boss.difficulty<=kMaxDifficulty);
    assert(offset<=boss.weakness && boss.weakness<offset+size);
  }
  // std::cerr << "Cycle done" << std::endl;
}

void AddBranch(const int size, std::vector<Boss>& bosses, std::default_random_engine& generator) {
  // std::cerr << "Adding branch of size "<< size<<std::endl;
  assert(!bosses.empty());
  std::uniform_int_distribution<int64_t> uniform_difficulty(2, kMaxDifficulty);
  const int offset = bosses.size();
  std::uniform_int_distribution<int64_t> uniform_boss(0, bosses.size()-1);
  int target = uniform_boss(generator);
  assert(target<offset);
  bosses.resize(offset+size);
  for(int i=0;i<size;++i) {
    Boss& boss = bosses[offset+i];
    boss.difficulty = uniform_difficulty(generator);
    boss.weakness = target;
    target = offset+i;
    assert(2<=boss.difficulty);
    assert(boss.difficulty<=kMaxDifficulty);
    assert(offset<=target);
    assert(boss.weakness<offset+size);
  }
  // std::cerr << "Branch done" << std::endl;
}

void GenerateCase(const int case_index, const int N, std::default_random_engine& generator) {
  std::bernoulli_distribution bernoulli(0.5);
  std::vector<Boss> bosses;
  while(bosses.size()<N) {
    // std::cerr << "Next component" << std::endl;
    const int missing = N-bosses.size();
    std::uniform_int_distribution<int64_t> uniform_size(1, missing);
    const int size = uniform_size(generator);
    if(!bosses.empty() && bernoulli(generator)) {
      AddBranch(size, bosses, generator);
    } else {
      AddCycle(size, bosses, generator);
    }
  }
  assert(bosses.size()==N);
  
  {
    std::ostringstream os;
    os << "case_" << case_index << ".in";
    std::ofstream F;
    F.open (os.str());
    F << N << std::endl;
    for(int i=0;i<N;++i) {
      F << bosses[i].difficulty << " " << bosses[i].weakness << std::endl;
    }
    F.close();
  }
  
  
  
  // std::cerr << "Solving..." << std::endl;
  const int64_t sol = Solve(N, bosses);
  
  {
    std::ostringstream os;
    os << "case_"<< case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    F << sol << std::endl;
    F.close();
  }
}

void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());

  GenerateCase(0, 100, generator);
  GenerateCase(1, 500, generator);
  GenerateCase(2, 1000, generator);
  GenerateCase(3, 2000, generator);
  GenerateCase(4, 5000, generator);
  GenerateCase(5, 10000, generator);
  GenerateCase(6, 100000, generator);
  GenerateCase(7, 900000, generator);
  GenerateCase(8, 950000, generator);
  GenerateCase(9, 1000000, generator);

}

int main() {
  //Solve();
  GenerateCases();
  return 0;
}
