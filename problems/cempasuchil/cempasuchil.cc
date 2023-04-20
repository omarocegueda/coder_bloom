#include <assert.h>

#include <algorithm>
#include <iostream>
#include <limits>

const int kMaxHouses = 20;
const int kMaxDead = 30;

int N, M;
int house_position[kMaxHouses];
int num_houses[kMaxDead];
int houses[kMaxDead];
int max_position[kMaxDead];
int D[kMaxDead][kMaxDead];

int Distance(int i, int j) {
  int d = std::max(0, max_position[j]-max_position[i]);
  for(int n=houses[j]&(~(houses[i]));n;n>>=1) {
    d += n&1;
  }
  return d;
}

int PrecomputeDistances() {
  for(int i=0;i<M;++i) {
    for(int j=0;j<M;++j) {
      D[i][j] = Distance(i, j);
    }
  }
  return 0;
}

void SolveRecursive(int pos, int current_sum, int* global_minimum, int used, int* order) {
  if(pos>=M) {
    if(current_sum<*global_minimum) {
      *global_minimum = current_sum;
    }
  }
  if(current_sum >= *global_minimum) {
    return;
  }
  int best = -1;
  for(int i=0;i<M;++i) {
    if(!(used&(1<<i))) {
      order[pos] = i;
      const int dist = (pos==0)?num_houses[order[0]] + max_position[order[0]]
                               :D[order[pos-1]][order[pos]];
      SolveRecursive(pos+1, current_sum+dist, global_minimum, used|(1<<i), order);
    }
  };
}

void Solve() {
  std::cin >> N >> M;
  for(int i=0;i<N;++i) {
    std::cin >> house_position[i];
  }
  for(int dead=0;dead<M;++dead) {
    max_position[dead] = -1;
    std::cin >> num_houses[dead];
    houses[dead] = 0;
    for(int house=0;house<num_houses[dead];++house) {
      int index;
      std::cin >> index;
      houses[dead]|=(1<<index);
      max_position[dead] = std::max(max_position[dead], house_position[index]);
    }
  }
  PrecomputeDistances();
  int order[kMaxHouses];
  for(int i=0;i<M;++i) {
    order[i] = i;
  }
  std::sort(order, order+M, [](const int a, const int b){return max_position[a]>max_position[b];});
  int global_minimum = num_houses[order[0]] + max_position[order[0]];
  for(int i=1;i<M;++i) {
    global_minimum += D[order[i-1]][order[i]];
  }
  //SolveRecursive(0, 0, &global_minimum, 0, order);
  std::cout << global_minimum << std::endl;
}

int main() {
  Solve();
  return 0;
}


