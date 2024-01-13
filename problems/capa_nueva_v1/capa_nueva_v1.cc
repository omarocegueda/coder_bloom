#include <cassert>
#include <iostream>
#include <vector>

#include <random>
#include <sstream>
#include <fstream>

int32_t Solve(const int32_t N, const int32_t M, const std::vector<std::string>& T) {
  std::vector<std::vector<int32_t>> memo(N, std::vector<int32_t>(M, 1));
  int32_t sol = 1;
  for(int i=1; i<N;++i) {
    for(int j=1; j<M; ++j) {
      if(T[i][j]!=T[i][j-1] || T[i][j]!=T[i-1][j-1] || T[i][j]!= T[i-1][j]) {
        continue;
      }
      const int32_t sub_size = std::min(memo[i][j-1], std::min(memo[i-1][j-1], memo[i-1][j]));
      memo[i][j] = std::max(memo[i][j], sub_size+1);
      sol = std::max(sol, memo[i][j]);
    }
  }
  return sol;
}


void WriteCase(const int32_t case_index, const int32_t N, const int32_t M, std::vector<std::string>& T, int32_t sol, std::default_random_engine& engine) {
  // Write input
  {
    assert(T.size() == N);
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    std::ofstream F;
    F.open (os.str());
    F<<N<<" "<<M<<std::endl;
    for(int i=0;i<N;++i) {
      F << T[i] << std::endl;
      assert(T[0].size() == T[i].size());
    }
    F << std::endl;
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
}

void GenerateCase(const int32_t case_index, const int32_t N, const int32_t M, const int32_t square_side, const int32_t n_squares, std::default_random_engine& engine) {
  assert(square_side>0);
  assert(square_side<=N && square_side<=M);
  std::cerr << "Generating case "<< case_index<<std::endl;
  std::uniform_int_distribution<char> uniform_color('a', 'z');
  
  std::vector<std::string> T(N, std::string(M,' '));
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      T[i][j] = uniform_color(engine);
    }
  }

  std::uniform_int_distribution<int32_t> uniform_row(0, N-square_side);
  std::uniform_int_distribution<int32_t> uniform_column(0, M-square_side);
  for(int k=0;k<n_squares;++k) {
    const int32_t i0 = uniform_row(engine);
    const int32_t j0 = uniform_column(engine);
    const char color = uniform_color(engine);
    for(int di=0; di<square_side;++di) {
      for(int dj=0; dj<square_side; ++dj) {
        T[i0+di][j0+dj] = color;
      }
    }
  }

  int32_t sol = Solve(N, M, T);
  assert(sol>=square_side);
  if(sol!=square_side) {
    std::cerr << sol <<"!=" << square_side<< std::endl;
  }
  std::cerr << "N="<<N <<", M="<<M<< ", sol="<<sol <<std::endl;
  WriteCase(case_index, N, M, T, sol, engine); 
}


void GenerateCases() {
  std::random_device rd;
  std::default_random_engine engine(rd());

  GenerateCase(0, 10, 12, 5, 3, engine);
  GenerateCase(1, 50, 35, 15, 5, engine);
  GenerateCase(2, 82, 120, 73, 5, engine);
  GenerateCase(3, 105, 93, 34, 10, engine);
  GenerateCase(4, 205, 193, 134, 10, engine);
  GenerateCase(5, 340, 368, 285, 20, engine);
  GenerateCase(6, 640, 406, 385, 20, engine);
  GenerateCase(7, 587, 962, 391, 20, engine);
  GenerateCase(8, 994, 753, 401, 20, engine);
  GenerateCase(9, 1000, 1000, 725, 20, engine);
  
}

void Solve(){
  int32_t N, M;
  std::cin >> N >> M;
  std::vector<std::string> T(N); 
  for(int i=0;i<N;++i) {
    std::cin >> T[i];
  }

  std::cout << Solve(N, M, T) << std::endl;
}

int main(){
  GenerateCases();
  return 0;
}
