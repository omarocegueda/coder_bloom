#include <vector>
#include <string>
#include <iostream>

void Fill(std::vector<std::string>& dest, const char c,
          const std::size_t i0, const std::size_t j0,
          const std::size_t i1, const std::size_t j1) {
  for(std::size_t i=i0;i<i1;++i) {
    for(std::size_t j=j0;j<j1;++j) {
      dest[i][j] = c;
    }
  }
}

void Solve(const std::size_t N, std::vector<std::string>& dest, const std::size_t i0, std::size_t j0) {
  if(N==1) {
    dest[i0][j0] = '.';
  } else {
    const uint64_t k = N/3;
    for(int ii=0;ii<3;++ii) {
      for(int jj=0; jj<3;++jj) {
        if(ii==1 && jj==1) {
          Fill(dest, 'X', i0+k, j0+k, i0+2*k, j0+2*k);
        } else {
          Solve(k, dest, i0+ii*k, j0+jj*k);
        }
      }
    }
  }
}

void SolveSingle() {
	std::size_t N;
  std::cin >> N;
  std::vector<std::string> sol(N, std::string(N, ' '));
  Solve(N, sol, 0, 0);
  for(std::size_t i=0;i<sol.size();++i) {
  	std::cout << sol[i] << std::endl;
  }
}

int main(){
  SolveSingle();
  return 0;
}
