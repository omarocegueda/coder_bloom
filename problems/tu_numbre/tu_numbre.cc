#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
int N, M;
std::string s;
void Print(std::string current, std::vector<bool>& used) {
  if(current.size()==N) {
    std::cout << current << std::endl;
    return;
  }
  for(int i=0;i<M;++i) {
    if(used[i]) {
      continue;
    }
    used[i] = true;
    Print(current+s[i], used);
    used[i] = false;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::cin >> N >> M >> s;
  std::sort(s.begin(), s.end());
  std::vector<bool> used(M);
  Print("",used);

  
  return 0;
}