#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
int main() {
  int N;
  std::cin >> N;
  std::vector<std::pair<std::string, std::string>> original_list;
  original_list.reserve(N/2);
  for(int i=0;2*i<N;++i) {
    std::string s;
    std::cin >> s;
    const std::string left = s.substr(0, s.size()/2);
    const std::string right = s.substr(s.size()/2, s.size()/2);
    original_list.push_back({left, right});
  }
  
  std::unordered_map<std::string, std::string> names;
  for(int i=0;i<N;++i) {
    std::string pattern, name;
    std::cin >> pattern >> name;
    names[pattern] = name;
  }
  std::vector<std::pair<std::string, std::string>> final_list;
  final_list.reserve(N/2);
  for(const auto&[left, right] : original_list) {
    final_list.push_back({names[left], names[right]});
    
  }
  std::sort(final_list.begin(), final_list.end());
  for(const auto&[left, right] : final_list) {
    std::cout << left << " " << right << std::endl;
  }
  return 0;
}

