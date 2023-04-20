#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

const int kMaxN = 500;
const int kMaxFamilyTypes = 26;
int I[kMaxN+1][kMaxN+1][kMaxFamilyTypes];

void PrecomputeIntegral(const int N, const std::vector<std::string>& A, const int family=-1) {
  if(family==-1) {
    for(int k=0;k<kMaxFamilyTypes;++k) {
      PrecomputeIntegral(N, A, k);
    }
    return;
  }
  for(int i=0; i<=N; ++i) {
    for(int j=0; j<=N; ++j) {
      I[i][j][family] = 0;
    }
  }
  // First row
  for(int j=1; j<=N; ++j) {
    const bool observed = family == (A[0][j-1]-'A');
    I[1][j][family] = I[1][j-1][family] + observed;
  }
  // Rest of rows
  for(int i=2; i<=N; ++i) {
    for(int j=1; j<=N;++j) {
      const int observed = (family == (A[i-1][j-1]-'A'));
      const int top =  I[i-1][j][family];
      const int left = I[i][j-1][family];
      const int intersection = I[i-1][j-1][family];
      I[i][j][family] = top+left-intersection+observed;
    }
  }
}

int CountDistinctFamilies(const int end_row, const int end_col, const int side) {
  int n_observed = 0;
  for(int k=0;k<kMaxFamilyTypes;++k) {
    const int top = I[end_row-side][end_col][k];
    const int left = I[end_row][end_col-side][k];
    const int intersection = I[end_row-side][end_col-side][k];
    const int total = I[end_row][end_col][k] - top - left + intersection;
    n_observed += (total>0);
  }
  return n_observed;
}

bool Possible(const int N, const int distinct_families, const int side) {
  for(int end_row=side; end_row<=N; ++end_row) {
    for(int end_col=side; end_col<=N; ++end_col) {
      const int n_observed = CountDistinctFamilies(end_row, end_col, side);
      if(n_observed >= distinct_families) {
        return true;
      }
    }
  }
  return false;
}

int Solve(const int N, const std::vector<std::string>& A) {
  PrecomputeIntegral(N, A);
  const int distinct_families = CountDistinctFamilies(N, N, N);
  if(distinct_families <= 1) {
    return distinct_families;
  }
  int a = 0; // impossible
  int b = N; // possible
  while(a + 1 < b) {
    int mid = (a + b) / 2;
    if(Possible(N, distinct_families, mid)) {
      b=mid;
    } else {
      a = mid;
    }
  }
  return b;
}

int CountDistinctFamiliesBruteForce(const int N, const std::vector<std::string>& A, const int end_row, const int end_col, const int side) {
  std::vector<bool> found(kMaxFamilyTypes, false);
  int n_found = 0;
  for(int i=end_row-side;i<end_row;++i) {
    for(int j=end_col-side;j<end_col;++j) {
      const int observed=A[i][j] - 'A';
      if(observed<0 || observed>kMaxFamilyTypes) {
        continue;
      }
      if(!found[observed]) {
        ++n_found;
        found[observed] = true;
      }
    }
  }
  return n_found;
}

bool PossibleBruteForce(const int N, const std::vector<std::string>& A, const int distinct_families, const int side) {
  for(int end_row=side;end_row<=N;++end_row) {
    for(int end_col=side;end_col<=N;++end_col) {
      const int n_found = CountDistinctFamiliesBruteForce(N, A, end_row, end_col, side);
      if(n_found>=distinct_families) {
        return true;
      }
    }
  }
  return false;
}

int SolveBruteForce(const int N, const std::vector<std::string>& A) {
  const int distinct_families = CountDistinctFamiliesBruteForce(N, A, N, N, N);
  if(distinct_families<=1) {
    return distinct_families;
  }
  for(int side=2; side<N;++side) {
    if(PossibleBruteForce(N, A, distinct_families, side)) {
      return side;
    }
  }
  return N;
}


void Solve() {
  int N;
  std::cin >> N;
  std::vector<std::string> A(N, "");
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << Solve(N, A) << std::endl;
}

void SolveBruteForce() {
  int N;
  std::cin >> N;
  std::vector<std::string> A(N, "");
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  std::cout << SolveBruteForce(N, A) << std::endl;
}

void Print(const std::vector<std::string>& A) {
  for(int i=0;i<A.size();++i) {
    std::cerr << A[i] << std::endl;
  }
}

void WriteCase(const int case_index, const int N, const std::vector<std::string>& A, const int sol) {
  {
    std::ostringstream os;
    os << "case_"<<case_index<<".in";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", N);
    for(int i=0;i<N;++i) {
      fprintf(F, "%s\n", A[i].c_str());
    }
    fclose(F);
  }
  {
    std::ostringstream os;
    os << "case_"<<case_index<<".out";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}



void GenerateCase(const int case_index, const int N, const int n_families, const int fill_percent) {
  std::vector<std::string> A(N,std::string(N, '.'));
  // Ensure at least one cell to each family;
  for(int family=kMaxFamilyTypes-n_families; family<kMaxFamilyTypes;++family) {
    int i, j;
    do {
      i=rand()%N;
      j=rand()%N;
      if(A[i][j]=='.') {
        A[i][j] = 'A' + family;
      }
    } while(A[i][j]!=('A'+family));
  }
  if(n_families >0) {
    for(int i=0;i<N;++i) {
      for(int j=0;j<N;++j) {
        if(A[i][j]!='.') {
          continue;
        }
        const bool do_fill = (1 + rand()%100)<=fill_percent;
        if(!do_fill) {
          continue;
        }
        const int selected = kMaxFamilyTypes - 1 - rand()%n_families;
        A[i][j] = 'A' + selected;
      }
    }
  }
  std::cerr << "Case #" <<case_index<< "Generated. N="<<N<< std::endl;
  Print(A);
  std::cerr<<"Solving case#"<<case_index<<", N="<<N << std::endl;
  const int sol = Solve(N, A);
  std::cerr <<"Solution:"<<sol<<std::endl;
  WriteCase(case_index, N, A, sol);
}

void GenerateCases() {
  const int factor = 5;
  srand(time(NULL));
  GenerateCase(0, 10*factor, 3, 0);
  GenerateCase(1, 20*factor, 10, 10);
  GenerateCase(2, 30*factor, 15, 9);
  GenerateCase(3, 40*factor, 15, 8);
  GenerateCase(4, 50*factor, 20, 7);
  GenerateCase(5, 81*factor, 21, 6);
  GenerateCase(6, 88*factor, 22, 5);
  GenerateCase(7, 93*factor, 23, 4);
  GenerateCase(8, 97*factor, 24, 3);
  GenerateCase(9, 100*factor, 26, 2);
}

int main() {
  // Solve();
  GenerateCases();
  return 0;
}
