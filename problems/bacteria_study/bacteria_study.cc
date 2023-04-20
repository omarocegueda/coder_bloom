#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>

int Solve(const int S, const std::vector<std::vector<int>>& L, std::set<int>* repeated=nullptr) {
  std::vector<int> C(S);
  int best = -1;
  bool draw = false;
  for(const std::vector<int>& l : L) {
    std::set<int> seen;
    for(int idx : l) {
      assert(seen.find(idx)==seen.end());
      seen.insert(idx);
      --idx;
      C[idx]++;
      if(best<0 || C[idx] > C[best]) {
        best = idx;
        draw = false;
        if(repeated) {
          repeated->clear();
          repeated->insert(best);
        }
      } else if(C[idx] == C[best] && idx!=best) {
        draw = true;
        if(repeated) {
          repeated->insert(idx);
        }
      }
    }
  }
  if(draw) {
    return -1;
  }
  return best + 1;
}

void SolveSingle() {
  int B, S;
  std::cin >> B >> S;
  std::vector<std::vector<int>> L(B);
  for(int i=0;i<B;++i) {
    int n;
    std::cin >> n;
    L[i].resize(n);
    for(int j=0;j<n;++j) {
      std::cin >> L[i][j];
      L[i][j];
    }
  }
  std::cout << Solve(S, L) << std::endl; 
}

std::vector<int> ChooseWithoutReplacement(int n, int k) {
  assert(n>=k);
  std::vector<int> P(n);
  for(int i=0;i<n;++i) {
    P[i] = i+1;
  }
  for(int i=0;i<k;++i) {
    const int r = i + rand()%(n-i);
    assert(r>=0 && r<n);
    std::swap(P[i], P[r]);
  }
  std::vector<int> sol(k);
  for(int i=0;i<k;++i) {
    sol[i] = P[i];
  }
  return sol;
}


void GenerateCase(int case_index, int B, int S) {
  std::cerr << "Generating case "<< case_index<< std::endl;
  std::vector<std::vector<int>> input(B);
  for(int i=0;i<B;++i) {
    const int n = 1 + rand() % S; 
    input[i] = ChooseWithoutReplacement(S, n);
  }
  std::set<int> repeated;
  int expected_sol = Solve(S, input, &repeated);
  while(expected_sol == -1) {
    std::cerr<<"Adjusting case "<<case_index<<std::endl;
    int i = rand()%input.size();
    const int n = 1 + rand() % S; 
    input[i] = ChooseWithoutReplacement(S, n);
    expected_sol = Solve(S, input, &repeated);
  }

  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", input.size(), S);
    for(const std::vector<int>& l : input) {
      fprintf(F, "%d ", l.size());
      for(const int idx : l) {
        fprintf(F, "%d ", idx);
      }
      fprintf(F, "\n");
    }
    fclose(F);
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", expected_sol);
    fclose(F);
  }
}

void GenerateCases() {
  srand(time(nullptr));
  GenerateCase(0, 1, 8);
  GenerateCase(1, 7, 9);
  GenerateCase(2, 11, 14);
  GenerateCase(3, 17, 22);
  GenerateCase(4, 19, 30);
  GenerateCase(5, 23, 44);
  GenerateCase(6, 26, 51);
  GenerateCase(7, 28, 68);
  GenerateCase(8, 39, 73);
  GenerateCase(9, 44, 96);
  GenerateCase(10, 49, 1);
  GenerateCase(11, 51, 13);
  GenerateCase(12, 58, 22);
  GenerateCase(13, 62, 38);
  GenerateCase(14, 67, 49);
  GenerateCase(15, 70, 50);
  GenerateCase(16, 75, 79);
  GenerateCase(17, 83, 86);
  GenerateCase(18, 92, 99);
  GenerateCase(19, 98,100);
}

int main(){
  //SolveSingle();
  GenerateCases();
  return 0;
}
