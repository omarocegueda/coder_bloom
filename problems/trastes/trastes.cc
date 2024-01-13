#include <string.h>

#include <iostream>
#include <queue>
#include <string>
#include <vector>

int32_t dRow[4] = {-1, -1, 1, 1};
int32_t dCol[4] = {-1, 1, 1, -1};

struct Cell{
  int32_t r, c;
  Cell(): r(0), c(0) {}
  Cell(const int32_t r_, const int32_t c_): r(r_), c(c_) {}
};

bool Valid(const Cell& cell, const std::vector<std::string>& A) {
  if(cell.r<0 || cell.r>A.size()) {
    return false;
  }
  if(cell.c<0 || cell.c>A[0].size()) {
    return false;
  }
  return A[cell.r][cell.c] == '.';
}

bool Feasible(const std::vector<std::string>&A, const int col) {
  bool visited[8][8];
  memset(visited, 0, sizeof(visited));
  if(A[0][col] == '*') {
    return false;
  }
  std::queue<Cell> Q;
  Q.push(Cell(0, col));
  visited[0][col] = true;
  while(!Q.empty()) {
    const Cell current = Q.front();
    Q.pop();
    for(int dir = 0; dir<4; ++dir) {
      const Cell next(current.r+dRow[dir], current.c+dCol[dir]);
      if(!Valid(next, A)) {
        continue;
      }
      if(visited[next.r][next.c]) {
        continue;
      }
      if(next.r == 7) {
        return true;
      }
      Q.push(next);
      visited[next.r][next.c] = true;
    }
  }
  return false;
}

int main() {
  std::vector<std::string> A(8);
  for(int i=0;i<8;++i) {
    std::cin >>A[i];
  }
  for(int col=0; col<8; ++col) {
    if(A[0][col] == '*') {
      continue;
    }
    if(!Feasible(A, col)) {
      std::cout << "Ana" << std::endl;
      return 0;
    }
  }
  std::cout << "Bob" << std::endl;
  return 0;
}
