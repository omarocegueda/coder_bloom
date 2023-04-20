
void PrintSate() {
  std::cerr<<"Max Position: "<<std::endl;
  for(int i=0;i<M;++i) {
    std::cerr<<max_position[i] << ", ";
  }
  std::cerr<<std::endl;
  std::cerr<<"D:"<<std::endl;
  for(int i=0;i<M;++i) {
    for(int j=0;j<M;++j) {
      std::cerr<<D[i][j]<<", ";
    }
    std::cerr<<std::endl;
  }
  std::cerr<<"Init: "<<std::endl;
  for(int i=0;i<M;++i) {
    std::cerr<<num_houses[i] + max_position[i] << ", ";
  }
  std::cerr<<std::endl;
}


void TestDistance() {
  max_position[0] = 0;
  max_position[1] = 0;
  houses[0] = (1<<9)|(1<<5)|(1<<2);
  houses[1] = (1<<10)|(1<<5)|(1<<3);
  assert(Distance(0,1)==2);
  
  houses[0] = (1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6);
  houses[1] = (1<<0)|(1<<3)|(1<<4)|(1<<7)|(1<<8)|(1<<9);
  assert(Distance(0,1)==4);
  //
  max_position[0] = 10;
  max_position[1] = 20;
  houses[0] = (1<<4)|(1<<5)|(1<<6);
  houses[1] = (1<<3)|(1<<5)|(1<<6);
  assert(Distance(0,1)==11);
  //
  max_position[0] = 5;
  max_position[1] = 3;
  houses[0] = (1<<0)|(1<<1);
  houses[1] = (1<<0);
  assert(Distance(0,1)==0);
  assert(Distance(1,0)==3);
}


#include <assert.h>

#include <algorithm>
#include <iostream>

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

int SolveRecursive(int pos, int current_sum, int* global_minimum, int used, int* order) {
  if(pos>=M) {
    //for(int i=0;i<M;++i) {
    //  std::cerr << order[i] << ", ";
    //}
    //std::cerr<<std::endl;
    if(*global_minimum < 0 || current_sum<*global_minimum) {
      *global_minimum = current_sum;
    }
    return 0;
  }
  if((*global_minimum>=0) && (current_sum >= *global_minimum)) {
    return current_sum;
  }
  int best = -1;
  for(int i=0;i<M;++i) {
    if(!(used&(1<<i))) {
      order[pos] = i;
      const int dist = (pos==0)?num_houses[order[0]] + max_position[order[0]]
                               :D[order[pos-1]][order[pos]];
      const int sub = dist + SolveRecursive(pos+1, current_sum+dist, global_minimum, used|(1<<i), order);
      if(best<0 || sub < best) {
        best = sub;
      }
    }
  }
  return best;
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
  int global_minimum = -1;
  int best = SolveRecursive(0, 0, &global_minimum, 0, order);
  std::cout << best << std::endl;
}

int main() {
  Solve();
  return 0;
}


