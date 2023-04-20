#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cassert>

std::vector<std::string> Split(const std::string &input) {
  std::istringstream iss(input);
  std::string item;
  
  std::vector<std::string> split;
  while (std::getline(iss, item, ' ')) {
    split.push_back(item);
  }
  return split;
}

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
  std::ifstream data_in("data.in", std::ifstream::in);
  int N, M;
  data_in >> N >> M;
  std::vector<std::string> names(N);
  for(int i=0;i<N;++i) {
    data_in >> names[i];
  }
  std::vector<int> combination(M);
  std::vector<std::vector<std::string>> expected;
  Combine(0, N, M, names, combination, &expected);
  std::sort(expected.begin(), expected.end());
  return expected;
}

std::vector<std::vector<std::string>> GetActualAndSort(const std::size_t expected_items_per_line, const std::size_t max_lines) {
  std::string line;
  
  std::vector<std::vector<std::string>> actual;
  std::size_t n_lines = 0;
  while(n_lines < max_lines && std::getline(std::cin, line)) {
     std::vector<std::string> combination = Split(line);
     if(combination.size() != expected_items_per_line) {
       std::cerr << "Received a combination with the wrong number of elements: " << line << std::endl;
     }
     std::sort(combination.begin(), combination.end());
     actual.push_back(combination);
  }
  std::sort(actual.begin(), actual.end());
  return actual;
}


int main() {
  // Read from "data.in" the input that was given to the contestant's program, and return the answer given by the official solution.
  std::vector<std::vector<std::string>> expected = GetExpected();
  assert(!expected.empty());
  // Read from standard input the solution given by the contestant's program. Verify that the contestant's output contains the 
  // expected amount of lines, and that each line contains the expected amount of strings. Return the sorted solution.
  std::vector<std::vector<std::string>> actual = GetActualAndSort(expected[0].size(), expected.size());
  // Since both `actual` and `expected` are now sorted, we can just compare them for equality.
  if (actual != expected) {
    std::cout << 0.0 << std::endl;
    return 0;
  }
  std::cout << 1.0 << std::endl;
  return 0;
}

