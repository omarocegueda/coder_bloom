#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
int IntersectionSize(const std::vector<std::string>& a, const std::unordered_set<std::string>& b) {
  int cnt = 0;
  for(const std::string& s : a) {
    if(b.find(s)!=b.end()) {
      ++cnt;
    }
  }
  return cnt;
}
int main() {
  std::vector<std::pair<std::string, std::unordered_set<std::string>>> M={
    {"Invierno", {"Orion", "Geminis", "Tauro", "Osa Menor"}},
    {"Primavera", {"Leo", "Virgo", "Osa Menor"}},
    {"Verano", {"Escorpion", "Sagitario", "Cygnus", "Osa Menor"}},
    {"Otono", {"Pegaso", "Piscis", "Osa Menor"}}};
  int n;
  std::cin >> n;
  std::cin.ignore();
  std::vector<std::string> list(n);
  for(int i=0;i<n;++i) {
    std::getline(std::cin, list[i]);
  }

  int max_seen = -1;
  std::vector<std::string> best_seasons;
  for(int i=0;i<M.size();++i) {
    const std::string& season = M[i].first;
    const std::unordered_set<std::string>& seen = M[i].second;
    const int opt = IntersectionSize(list, seen);
    if(opt < max_seen) {
      continue;
    }
    if(max_seen < opt) {
      max_seen = opt;
      best_seasons.clear();
    } 
    best_seasons.push_back(season);
  }
  for(const std::string& season: best_seasons) {
    std::cout << season << std::endl;
  }
  return 0;
}
