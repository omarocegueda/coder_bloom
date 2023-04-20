#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const int64_t kMaxN = 1000; 
const int64_t kMaxM = 1000;

int64_t N, M;
std::string A[kMaxN+1];
std::string T[kMaxN+1];

std::vector<int> mediana(std::vector<int>& v) {
  sort(v.begin(), v.end());
  auto n = v.size();
  std::vector<int> rv{v[n/2]};
  if (n % 2 == 0) {
    rv.push_back(v[n/2 - 1]);
  }
  return rv;
}

int64_t SolveWrong() {
  int n = N;
  int m = M;
  std::vector<int> vr, vc;
  for (int i = 0; i != n; ++i) {
    std::string renglon=A[i];
    for (int j = 0; j != m; ++j) {
      if (renglon[j] == 'A') {
        vr.push_back(i);
        vc.push_back(j);
      }
    }
  }
  std::vector<std::pair<int,int>> t;
  for (int i = 0; i != n; ++i) {
    std::string renglon = T[i];
    for (int j = 0; j != m; ++j) {
      if (renglon[j] == 'T') {
        t.emplace_back(i, j);
      }
    }
  }

  std::vector<int> rs = mediana(vr);
  std::vector<int> cs = mediana(vc);

  int nt = t.size();
  std::vector<int> ct;
  for (int r : rs) {
    for (int c : cs) {
      int mn = 1<<29;
      int mni = -1;
      int q = ct.size();
      for (int i = 0; i != nt; ++i) {
        int dr = abs(r - t[i].first);
        int dc = abs(c - t[i].second);
        if (dr + dc < mn) {
          mn = dr + dc;
          mni = i;
          ct.resize(q);
          ct.push_back(i);
        } else if (dr + dc == mn) {
          ct.push_back(i);          
        }
      }
    }
  }
  sort(ct.begin(), ct.end());
  ct.erase(unique(ct.begin(), ct.end()), ct.end());
  int na = vr.size();
  int rv = 1<<29;
  for (int i : ct) {
    auto [r, c] = t[i];
    int s = 0;
    for (int j = 0; j != na; ++j) {
      int ar = vr[j];
      int ac = vc[j];
      s += abs(ar - r) + abs(ac - c);
    }
    rv = std::min(rv, s);
  }
  return rv;
}



int64_t SolveFast() {
  int64_t H[kMaxM+1];
  int64_t V[kMaxN+1];
  int64_t total_friends = 0;
  // Precompute horizontal distances
  H[0] = 0;
  for(int i=0;i<N;++i) {
    H[0] += (A[i][0] == 'A');
    total_friends += (A[i][0] == 'A');
  }
  for(int j=1;j<M;++j) {
    H[j] = H[j-1];
    for(int i=0;i<N;++i) {
      H[j] += (A[i][j] == 'A');
      total_friends += (A[i][j] == 'A');
    }
  }
  // Precompute vertical distances
  V[0] = 0;
  for(int j=0;j<M;++j) {
    V[0] += (A[0][j] == 'A');
  }
  for(int i=1;i<N;++i) {
    V[i] = V[i-1];
    for(int j=0;j<M;++j) {
      V[i] += (A[i][j] == 'A');
    }
  }
  // Compute full distances. Start with S[0][0]
  int64_t S[kMaxN+1][kMaxM+1];
  S[0][0] = 0;
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      if(A[i][j] == 'A') {
        S[0][0] += (i+j);
      }
    }
  }
  // Continue with the first row.
  for(int j=1;j<M;++j) {
    S[0][j] = S[0][j-1] + 2*H[j-1] - total_friends;
  }
  // Finally, the rest of the rows.
  for(int i=1;i<N;++i) {
    // Compute the first element of the row.
    S[i][0] = S[i-1][0] + 2*V[i-1] - total_friends;
    // The rest of the elements
    for(int j=1;j<M;++j) {
      S[i][j] = S[i][j-1] + 2*H[j-1] - total_friends;
    }
  }
  // Now return the minimum sum of distances.
  int64_t min_d = S[0][0];
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      if(T[i][j] == 'T') {
        //std::cerr << "S["<< j+1<<","<<N-i<<"]="<<S[i][j] << std::endl;
        min_d = std::min(min_d, S[i][j]);
      }
    }
  }
  return min_d;
}

void WriteCase(int case_index) {
  int64_t sol = SolveFast();
  // Generate input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, M);
    for(int i=0;i<N;++i) {
      fprintf(F, "%s\n", A[i].c_str());
    }
    for(int i=0;i<N;++i) {
      fprintf(F, "%s\n", T[i].c_str());
    }
    fclose(F);
  }
  // Generate output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}

void GenerateRandomCase(int N_, int M_, int t_percent, int a_percent) {
  N=N_;
  M=M_;
  for(int i=0;i<N;++i) {
    T[i].resize(M);
    A[i].resize(M);
    for(int j=0;j<M;++j) {
      if(rand()%100 < t_percent) {
        T[i][j] = 'T';
      } else {
        T[i][j] = '.';
      }
      if(rand()%100 < a_percent) {
        A[i][j] = 'A';
      } else {
        A[i][j] = '.';
      }
    }
  }
  
}
void GenerateAndPrintRandomCase(int case_index, int N_, int M_, int t_percent, int a_percent) {
  GenerateRandomCase(N_, M_, t_percent, a_percent);
  WriteCase(case_index);
}

void GenerateSparseTCase(int N_, int M_, int n_t, int a_percent) {
  N=N_;
  M=M_;
  for(int i=0;i<N;++i) {
    T[i].resize(M);
    A[i].resize(M);
    for(int j=0;j<M;++j) {
      T[i][j] = '.';
      if(rand()%100 < a_percent) {
        A[i][j] = 'A';
      } else {
        A[i][j] = '.';
      }
    }
  }
  for(int i=0;i<n_t;++i) {
    int ii = rand()%N;
    int jj = rand()%M;
    T[ii][jj] = 'T';  // Ok if duplicated.
  }
}
void GenerateAndPrintSparseTCase(int case_index, int N_, int M_, int n_t, int a_percent) {
  GenerateSparseTCase(N_, M_, n_t, a_percent);
  WriteCase(case_index);
}


void GenerateSparseACase(int N_, int M_, int t_percent, int n_a) {
  N=N_;
  M=M_;
  for(int i=0;i<N;++i) {
    T[i].resize(M);
    A[i].resize(M);
    for(int j=0;j<M;++j) {
      A[i][j] = '.';
      if(rand()%100 < t_percent) {
        T[i][j] = 'T';
      } else {
        T[i][j] = '.';
      }
    }
  }
  for(int i=0;i<n_a;++i) {
    int ii = rand()%N;
    int jj = rand()%M;
    A[ii][jj] = 'A';  // Ok if duplicated.
  }
}
void GenerateAndPrintSparseACase(int case_index, int N_, int M_, int t_percent, int n_a) {
  GenerateSparseACase(N_, M_, t_percent, n_a);
  WriteCase(case_index);
}


int64_t SolveSlow() {
  int64_t min_dist = -1;
  for(int i=0; i<N;++i) {
    for(int j=0;j<M;++j) {
      if(T[i][j] == 'T') {
        int64_t opt = 0; 
        for(int ii=0;ii<N;++ii) {
          for(int jj=0;jj<M;++jj) {
            if(A[ii][jj] == 'A') {
              opt += std::abs(i-ii)+std::abs(j-jj);
            }
          }
        }
        if(min_dist <0 || opt < min_dist) {
          min_dist = opt;
        }
      }
    }
  }
  return min_dist;
}

void PrintCase() {
  for(int i=0;i<N;++i) {
    std::cerr << A[i] << std::endl;
  }
  for(int i=0;i<N;++i) {
    std::cerr << T[i] << std::endl;
  }
}

void ValidateFast(int n_runs) {
  srand(time(NULL));
  for(int i=0;i<n_runs;++i) {
    GenerateRandomCase(200, 200, 25, 25);
    std::cerr << "Validating run "<< i << ". N="<<N<<", M="<<M<<std::endl;
    int64_t expected = SolveSlow(); 
    assert(SolveFast()==expected);
    //PrintCase();
    std::cerr<< "Ok: "<<expected<<std::endl;
  }
}

void BreakPablo(int case_index, int N_, int M_, int t_percent, int a_percent) {
  srand(time(NULL));
  int64_t expected;
  int64_t actual;
  do {
    std::cerr<<"Trying..." << std::endl;
    GenerateRandomCase(N_, M_, t_percent, a_percent);
    expected = SolveFast(); 
    actual = SolveWrong();
  }while(actual==expected);
  std::cerr<< "Case #"<<case_index<<" successfully broken: "<<actual<<"!="<<expected<<std::endl;
  WriteCase(case_index);
}

void GenerateCases() {
  srand(time(NULL));
  // Edge cases - map dimensions
  GenerateAndPrintRandomCase(0, 1, 1, 100, 100);
  GenerateAndPrintRandomCase(1, 1, 50, 25, 25);
  GenerateAndPrintRandomCase(2, 50, 1, 25, 25);
  GenerateAndPrintRandomCase(3, 1, 1000, 50, 50);
  GenerateAndPrintRandomCase(4, 1000, 1, 50, 50);
  // Edge cases - sparse A
  GenerateAndPrintSparseACase(5, 994, 983, 80, 10);
  GenerateAndPrintSparseACase(6, 976, 992, 90, 10);
  // Edge cases - sparse T
  GenerateAndPrintSparseTCase(7, 991, 981, 10, 85);
  GenerateAndPrintSparseTCase(8, 941, 999, 10, 95);
  // Edge cases - Full T
  GenerateAndPrintRandomCase(9, 993, 943, 100, 75);
  GenerateAndPrintRandomCase(10, 890, 781, 100, 50);
  // Random cases
  BreakPablo(11, 100, 100, 25, 15);
  BreakPablo(12, 793, 242, 30, 35);
  BreakPablo(13, 312, 561, 40, 40);
  BreakPablo(14, 423, 418, 55, 50);
  BreakPablo(15, 754, 623, 75, 75);
  BreakPablo(16, 793, 843, 80, 85);
  GenerateAndPrintRandomCase(17, 803, 801, 90, 90);
  GenerateAndPrintRandomCase(18, 921, 912, 90, 95);
  GenerateAndPrintRandomCase(19, 999, 998, 95, 95);
}

int main() {
  GenerateCases();
  return 0;
  
  //ValidateFast(20);
  //return 0;
  GenerateCases();
  return 0;
  std::cin >> N >> M;
  for(int i=0; i<N;++i) {
    std::cin >> A[i];
  }
  for(int i=0; i<N;++i) {
    std::cin >> T[i];
  }
  std::cout << SolveFast() << std::endl;
  return 0;
}

