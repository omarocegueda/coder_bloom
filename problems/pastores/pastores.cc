#include <iostream>
#include <sstream>
int Solve(const int N, const int R, const int B) {  
  return N/((B+R-1)/R);
}

void GenerateCase(const int index, const int N, const int R, const int B) {
  int sol = Solve(N, R, B);
  {
    std::ostringstream os;
    os<<"case_"<<index<<".in";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d %d\n", N, R, B);
    fclose(F);
  }
  {
    std::ostringstream os;
    os<<"case_"<<index<<".out";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d\n", sol);
    fclose(F);
  }
}

void GenerateCases() {
  GenerateCase(0, 90,         1, 91);
  GenerateCase(1, 150,        46, 242);
  GenerateCase(2, 721,        322435, 12);
  GenerateCase(3, 1000,       23, 45);
  GenerateCase(4, 100000,     234, 4353);
  GenerateCase(5, 500000,     8329, 2422342);
  GenerateCase(6, 1170301,    30498503, 2342789);
  GenerateCase(7, 140205351,  4952, 234242);
  GenerateCase(8, 516080302,  892374, 3795);
  GenerateCase(9, 1000000000, 999999999, 1000000000);
}

int main() {
  GenerateCases();
  return 0;
}
