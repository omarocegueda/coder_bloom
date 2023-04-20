#include <iostream>
#include <assert.h>
#include <string.h>
const int64_t kMod = 1000000007;
const int64_t kMaxDishes = 100;
int64_t M[kMaxDishes+1][kMaxDishes+1];
int64_t I[kMaxDishes+1];
int64_t N, T;

int64_t SolveRec(int course=0, int first_dish=0) {
  if(M[course][first_dish]>=0) {
    return M[course][first_dish];
  }
  if(course==T-1) {
    int64_t sol = 0;
    for(int dish=first_dish;dish<N;++dish) {
      sol = (sol + (1LL<<I[dish]))%kMod;
    }
    return M[course][first_dish] = sol;
  }
  int64_t sol = 0;
  for(int dish=first_dish;dish+T-1-course<N;++dish) {
    sol = (sol + ((1LL<<I[dish])*SolveRec(course+1, dish+1))%kMod)%kMod;
  }
  return M[course][first_dish] = sol;
}

int main() {
  std::cin >> N >> T;
  assert(1<=T);
  assert(T<=N);
  assert(N<=100);
  for(int i=0;i<N;++i) {
    std::cin >> I[i];
    assert(0<=I[i]);
    assert(I[i]<=20);
  }
  memset(M, -1, sizeof(M));
  std::cout << SolveRec() << std::endl;
  return 0;

}
