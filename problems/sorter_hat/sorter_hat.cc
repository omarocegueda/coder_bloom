#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <fstream>

int64_t SolveSlow(int64_t N, int64_t C) {
  std::vector<int64_t> v[2];
  v[0].resize(N+C);
  v[1].resize(N+C);
  v[0][0] = v[1][0] = v[1][1] = 1;
  for(int n = 2; n<N+C; ++n) {
    std::vector<int64_t> &prev = v[1-n%2];
    std::vector<int64_t> &current = v[n%2];
    for(int k=1; k<=n; ++k) {
      current[k] = prev[k-1] + prev[k];
    }
  }
  std::vector<int64_t> &sol = v[(N+C-1)%2];
  return sol[C-1];
}


void GenerateCases() {
  auto generate_case = [&](const int case_index, const int64_t N, const int64_t C){
    int64_t sol = SolveSlow(N, C);
    // Write input
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << N << " " << C << std::endl;
      F.close();
    }
    // Write output
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".out";
      
      std::ofstream F;
      F.open (os.str());
      F << sol << std::endl;
      F.close();
    }
  };
  
  generate_case(0, 3, 1);
  generate_case(1, 3, 5);
  generate_case(2, 4, 2);
  generate_case(3, 4, 5);
  generate_case(4, 5, 3);
  generate_case(5, 5, 7);
  generate_case(6, 6, 4);
  generate_case(7, 6, 8);
  generate_case(8, 7, 2);
  generate_case(9, 7, 10);
  
  generate_case(10, 21, 12);
  generate_case(11, 21, 23);
  generate_case(12, 22, 9);
  generate_case(13, 22, 23);
  generate_case(14, 23, 8);
  generate_case(15, 23, 24);
  generate_case(16, 24, 20);
  generate_case(17, 24, 25);
  generate_case(18, 25, 19);
  generate_case(19, 25, 25);
}


int main() {
  GenerateCases();
  return 0;
  /*int64_t N, C;
  std::cin >> N >> C;
  std::cout << SolveSlow(N, C) << std::endl;
  return 0;*/
}
