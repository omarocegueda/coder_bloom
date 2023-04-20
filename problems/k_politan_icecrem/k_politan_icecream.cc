#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <fstream>

std::vector<std::vector<int64_t>> ComputePascalTriangleStandard(int64_t N) {
  std::vector<std::vector<int64_t>> T(N+1);
  T[0] = {1};
  for(int n=1;n<=N;++n) {
    T[n].resize(n+1);
    T[n][0] = T[n][n] = 1;
    for(int k=1;k<n;++k) {
      T[n][k] = T[n-1][k] + T[n-1][k-1];
    }
  }
  return T;
}

std::vector<std::vector<int64_t>> ComputePascalTriangleNew(int N) {
  std::vector<std::vector<int64_t>> T(N+1);
  for(int n=0;n<=N;++n) {
    T[n] = std::vector<int64_t>(n+1, 0);
  }
  T[0][0] = 1;
  for(int k=1; k<=N; ++k) {
    T[k][0] = T[k][k] = 1;
    for(int n=k+1; n <= N; ++n) {
      T[n][k] = (T[n-1][k] * n)/(n-k);
    }
  }
  return T;
}


int64_t SolveSlow(int64_t N, int64_t K) {
  std::vector<std::vector<int64_t>> T = ComputePascalTriangleStandard(60);
  int64_t n = K;
  while(n<=60 && T[n][K] < N) {
    ++n;
  }
  if(n>60) {
    return -1;
  }
  return n;
  
}

int64_t SolveFast(int64_t N, int64_t K) {
  if(K==1) {
    return N;
  }
  int64_t n = K;
  int64_t n_choose_k = 1;
  while(n_choose_k < N) {
    ++n;
    n_choose_k = (n_choose_k*n)/(n-K);
  } 
  return n;
}


void GenerateCases() {
  auto generate_case = [&](const int case_index, const int64_t N, const int64_t K, bool verify){
    int64_t sol = SolveFast(N, K);
    std::cerr<<"N="<<N<<", K="<<K << ". Sol="<<sol<<std::endl;
    
    if(verify) {
      assert(sol == SolveSlow(N, K));
    }
    // Write input
    {
      std::ostringstream os;
      os<<"case_"<<case_index<<".in";
      
      std::ofstream F;
      F.open (os.str());
      F << N << " " << K << std::endl;
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

  generate_case(0, 21,        2, true);
  generate_case(1, 80,        6, true);
  generate_case(2, 1267,      5, true);
  generate_case(3, 24310,     8, true);
  generate_case(4, 2598,     23, true);
  generate_case(5, 74613,     6, true);
  generate_case(6, 100000,    6, true);
  generate_case(7, 3122550,   9, true);
  generate_case(8, 37442060, 13, true);
  generate_case(9, 1,        987, false);
  
  generate_case(10, 973610600, 3, false);
  generate_case(11, 593306590, 4, false);
  generate_case(12, 999916840, 2, false);
  generate_case(13, 224150024, 5, false);
  generate_case(14, 21200004,  501, false);
  generate_case(15, 200000,    692, false);
  generate_case(16, 66177420,  733, false);
  generate_case(17, 1000000000, 20, true);
  generate_case(18, 1000000000,  1, false);
  generate_case(19, 157668501, 1000, false);
}


void Print(std::vector<int64_t>& v) {
  int i=0;
  for(int64_t x : v) {
    /*if(i*2>v.size()) {
      break;
    }*/
    std::cout << x << ",\t";
    ++i;
  }
  std::cout << std::endl;
}

void VerifyPascalTriangle() {
  int N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> T = ComputePascalTriangleStandard(N);
  std::vector<std::vector<int64_t>> T2 = ComputePascalTriangleNew(N);
  for(int i=0;i<=N;++i) {
    for(int j=0;j<=i;++j) {
      assert(T[i][j] == T2[i][j]);
    }
  }
}

void Trace() {
  int64_t K;
  std::cin >> K;
  int64_t n = K;
  int64_t n_choose_k = 1;
  while(n_choose_k < 1000000000) {
    std::cerr<<"N="<<n<<", K="<<K<<". C(N,K)="<<n_choose_k<<std::endl;
    ++n;
    n_choose_k = (n_choose_k*n)/(n-K);
  }
}

int main() {
  //Trace();
  GenerateCases();
  
  return 0;
}
