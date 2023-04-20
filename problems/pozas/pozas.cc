#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> A;

bool Equals(int i, int j, char c) {
  if(i<0 || j<0 || i>=A.size() || j>=A[0].size()) {
    return false;
  }
  return A[i][j]==c;
}


bool Valid(int i, int j) {
  if(A[i][j] != 'X') {
    return false;
  }
  int n_nature = 0;
  int n_sculpture = 0;
  for(int ii=-1;ii<=1;++ii) {
    for(int jj=-1;jj<=1;++jj) {
      if(ii==0 && jj==0) {
        continue;
      }
      n_nature += Equals(i+ii, j+jj, 'A');
      n_sculpture += Equals(i+ii, j+jj, 'E');
    }
  }
  return (n_sculpture==0) && n_nature>=3;
}


int main() {
  int n,m;
  std::cin >> n >> m;
  for(int i=0;i<n;++i) {
    std::string line;
    std::cin >> line;
    A.push_back(line);
  }
  int sol = 0;
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      if(Valid(i, j)) {
        ++sol;
      }
    }
  }
  std::cout << sol << std::endl;
  return 0;
}


