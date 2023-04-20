#include <algorithm>
#include <iostream>
#include <map>

int main() {
  int N;
  std::cin >> N;
  std::map<int, int> M;
  for(int i=0;i<N;++i) {
    int p, d;
    std::cin >> p >> d;
    if(d != 0) {
      M[p] = -1;
    } else if(M[p]!=-1) {
      M[p]++;
    }
  }
  
  int sol = 0;
  auto iter=M.begin();
  while(iter!=M.end()) {
    if(iter->second > 0) {
      int opt = 0;
      while(iter!=M.end() && iter->second>0) {
        opt+=iter->second;
        ++iter;
      }
      sol = std::max(sol, opt);
    } else {
      ++iter;
    }
  }
  std::cout << sol << std::endl;
  return 0;
}

