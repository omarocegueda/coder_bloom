#include <iostream>
#include <vector>
#include <string>

inline void Set(const int i, const int j, char c, std::vector<std::string>& out) {
  if(0<=i && i< out.size() && 0<=j && j<out[0].size()) {
    out[i][j] = c;
  }
}

void Paint(const int i0, const int j0,  char color, const std::vector<std::string> P, std::vector<std::string>& out) {
  for(int i=0;i<P.size();++i) {
    for(int j=0;j<P[0].size();++j) {
      if(P[i][j]=='*') {
        Set(i0+i, j0+j, color, out);
      }
    }
  }
}

int main() {
  const std::vector<std::string> P = {
  ".......*........",
  "..............*.",
  "................",
  ".......*....*...",
  ".......*........",
  "...***.**.......",
  "......********..",
  "*.....******....",
  ".....*******...*",
  "....********....",
  "...*...****.*...",
  "*.......**......",
  "........*..*....",
  ".*.....*...*....",
  "............*...",
  "..*............."};
  std::vector<std::string> out(300, std::string(300, '.'));
  int N;
  std::cin >> N;
  for(int i=0;i<N;++i) {
    int i0, j0;
    std::string color;
    std::cin >> i0 >> j0 >> color;
    Paint(i0, j0, color[0], P, out);
  }
  int a = 0;
  int r = 0;
  for(const std::string& s : out) {
    for(const char c : s) {
      if(c=='a') {
        ++a;
      } else if (c=='r') {
        ++r;
      }
    }
  }
  std::cout << a << " "<< r << std::endl;

  return 0;
}
