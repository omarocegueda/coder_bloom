#include <stdlib.h>
#include <time.h>

#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void SolveMedium() {
  int C, R;
  std::cin >> C >> R;
  std::vector<int> importance(R);
  for(int i=0;i<R;++i) {
    std::cin >> importance[i];
  }
  std::sort(importance.rbegin(), importance.rend());
  if(C==1) {
    std::cout << importance[0] << std::endl;
  } else {
  	std::cout << importance[0] << " " <<importance[1] << std::endl;
  }
}

int main() {
  SolveMedium();
  return 0;
}
