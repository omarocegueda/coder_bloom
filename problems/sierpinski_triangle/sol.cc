#include <iostream>
#include <vector>
#include <string>

void PrintTriangle(int N, int r0, int c0, std::vector<std::string>& out) {
  if(N == 3) {
    out[r0][c0] = 'X';
    out[r0][c0+1] = 'X';
    out[r0][c0+2] = 'X';
    out[r0-1][c0+1] = 'X';
    return;
  }
  int NN = (N - 1) / 2;
  PrintTriangle(NN, r0, c0, out);
  PrintTriangle(NN, r0, c0+NN+1, out);
  PrintTriangle(NN, r0-(NN+1)/2, c0+(NN+1)/2, out);
}

void FillTriangle(std::vector<std::string>& out) {
  for(int r = out.size()-1, c0=0; r>=0; --r, ++c0) {
    for(int c = c0; c<out[r].size()-c0; ++c) {
      out[r][c] = '.';
    }
  }
}

void Print(const std::vector<std::string>& out) {
  for(auto l : out) {
    std::cout << l<< std::endl;
  }
  std::cout << std::endl;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<std::string> out((N+1)/2, std::string(N,' '));
  FillTriangle(out);
  PrintTriangle(N, (N+1)/2-1, 0, out);
  Print(out);
  return 0;
}
