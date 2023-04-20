#include <iostream>
int Solve(int R, int V, int J, int N, int r, int v, int j, int b) {
  for(int rr=r; rr<=1000; ++rr) {
    int vv = rr * R;
    if(vv<v) {
      continue;
    }
    int jj = vv * V;
    if(jj<j) {
      continue;
    }
    int bb = jj * J;
    if(bb<b) {
      continue;
    }
    return bb - b;
  }
  return -1;
}

int main() {
  int R, V, J, N;
  int r=0, v=0, j=0, b=0;
  std::cin >> R >> V >> J >> N;
  for(int i=0;i<N;++i) {
    std::string s;
    std::cin >> s;
    if(s == "rata") {
      ++r;
    } else if(s == "venado") {
      ++v;
    } else if (s== "jaguar") {
      ++j;
    } else if (s== "bufalo"){
      ++ b;
    }
  }
  std::cout << Solve(R,V,J,N,r,v,j,b) << std::endl;
  return 0;
}
