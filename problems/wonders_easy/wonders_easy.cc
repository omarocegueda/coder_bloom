#include <iostream>
#include <algorithm>
#include <random>
#include <sstream>
#include <cassert>

std::vector<std::string> GetCandidates() {
  static const std::vector<std::string> candidates = {
    "ChichenItza",
    "ChristRedeemer",
    "GreatWall",
    "MachuPicchu",
    "Petra",
    "RomanColosseum",
    "TajMahal",
    "Acropolis",
    "Alhambra",
    "Angkor",
    "EasterIslandStatues",
    "EiffelTower",
    "HagiaSophia",
    "KyomizuTemple",
    "Kremlin",
    "NeuschwansteinCastle",
    "PyramidsOfGiza",
    "StatueOfLiberty",
    "Stonehenge",
    "SydneyOperaHouse",
    "TimbuktuMali"};
  return candidates;
}

void GenerateCase(int case_index, int N, int M, std::default_random_engine& engine) {
  std::vector<std::string> all_candidates = GetCandidates();
  
  shuffle(all_candidates.begin(), all_candidates.end(), engine);
  
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, M);
    for(int i=0;i<N;++i) {
      fprintf(F, "%s\n", all_candidates[i].c_str());
    }
    fclose(F);
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    FILE *F = fopen(os.str().c_str(), "w");
    fprintf(F, "unused");
    fclose(F);
  }
}

void GenerateCases() {
  unsigned seed = time(nullptr);
  auto engine = std::default_random_engine(seed);
  
  GenerateCase(0, 1, 1, engine);
  GenerateCase(1, 4, 2, engine);
  GenerateCase(2, 7, 3, engine);
  GenerateCase(3, 8, 4, engine);
  GenerateCase(4, 9, 9, engine);
  GenerateCase(5, 11, 4, engine);
  GenerateCase(6, 11, 7, engine);
  GenerateCase(7, 13, 2, engine);
  GenerateCase(8, 13, 11, engine);
  GenerateCase(9, 14, 5, engine);
  GenerateCase(10, 14, 9, engine);
  GenerateCase(11, 15, 1, engine);
  GenerateCase(12, 15, 14, engine);
}


void PrintNames(const std::vector<std::string>& names, const std::vector<int>& combination) {
  for(int i : combination) {
    std::cout << names[i] <<" ";
  }
  std::cout << std::endl;
}

void Combine(int start, int N, int M, const std::vector<std::string>& names, std::vector<int>& combination) {
  if(M==0) {
    PrintNames(names, combination);
    return;
  }
  for(int i=start; i<N; ++i) {
    combination[combination.size()-M] = i;
    Combine(i+1, N, M-1, names, combination);
  }
}

int main() {
  GenerateCases();
  return 0;
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> names(N);
  for(int i=0;i<N;++i) {
    std::cin >> names[i];
    assert(names[i].size()<=20);
  }
  std::sort(names.begin(), names.end());
  std::vector<int> combination(M);
  Combine(0, N, M, names, combination);
  return 0;
}
