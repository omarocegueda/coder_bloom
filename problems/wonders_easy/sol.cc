#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <sstream>
#include <cassert>

std::vector<std::string> ReplaceNamesAndSort(const std::vector<std::string>& names, const std::vector<int>& combination) {
  std::vector<std::string> replaced;
  for(int i : combination) {
    replaced.push_back(names[i]);
  }
  std::sort(replaced.begin(), replaced.end());
  return replaced;
}

void Combine(int start, int N, int M, const std::vector<std::string>& names, std::vector<int>& combination, std::vector<std::vector<std::string>> *out) {
  if(M==0) {
    out->push_back(ReplaceNamesAndSort(names, combination));
    return;
  }
  for(int i=start; i<N; ++i) {
    combination[combination.size()-M] = i;
    Combine(i+1, N, M-1, names, combination, out);
  }
}

std::vector<std::vector<std::string>> GetExpected() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::string> names(N);
  for(int i=0;i<N;++i) {
    std::cin >> names[i];
  }
  std::vector<int> combination(M);
  std::vector<std::vector<std::string>> expected;
  Combine(0, N, M, names, combination, &expected);
  return expected;
}


int main() {
  std::vector<std::vector<std::string>> expected = GetExpected();
  unsigned seed = time(nullptr);
  auto engine = std::default_random_engine(seed);
  //shuffle(expected.begin(), expected.end(), engine);
  for(auto& item : expected) {
    //shuffle(item.begin(), item.end(), engine);
    for(const std::string& name:item) {
      std::cout << name << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
