#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>


void Solve(const int64_t a, const int64_t b, int n) {
  int* num_qdiv = new int[b-a+1];
  memset(num_qdiv, 0, (b-a+1)*sizeof(int));
  
  for(int64_t d = 1, dd=1; dd <= b; ++d, dd=d*d) {
    for(int64_t i=(a+dd-1)/dd; i*dd<=b; ++i) {
      num_qdiv[i*dd - a]++;
    }
  }
  std::vector<std::pair<int, int>> counts;
  for(int64_t i=a;i<=b;++i) {
    counts.push_back(std::make_pair(i-a, num_qdiv[i-a]));
  }
  std::sort(counts.begin(), counts.end(), [](const std::pair<int, int>& left,
                                       const std::pair<int, int>& right){
                                         if(left.second == right.second) {
                                          return left.first<right.first;
                                         }
                                         return left.second>right.second;
                                       });
  for(int i=0;i<n;++i) {
    num_qdiv[i] = counts[i].first;
  }
  std::sort(num_qdiv, num_qdiv+n);
  for(int i=0;i<n;++i) {
    std::cout << a + num_qdiv[i] << " ";
  }
  delete[] num_qdiv;
}


int main() {
  int64_t a,b,n;
  std::cin >> a >> b >> n;
  Solve(a, b, n);
  return 0;
}
