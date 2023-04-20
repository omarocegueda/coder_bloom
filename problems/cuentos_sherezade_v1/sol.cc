#include <cassert>
#include <iostream>

const int64_t kMax = 1000000000000;

bool Solve(const int64_t N, const int64_t A, const int64_t I0, const int64_t Imax) {
  std::cerr<<"JOOG: N="<<N<<", A="<<A<<", I0="<<I0<<"Imax="<<Imax<<std::endl;
  if(I0 == 0) {
    return false;
  }
  if(Imax == 1) {
    // All stories must be interesting
    return A==N;
  }
  // Now we know: 1<=I0 && 2<=Imax
  return (I0+A) > (N-A); // Remove the Imax ceiling: go all the way up, then all the way down
  // Strategy: Tell I0-1 non-interesting stories first. Worst case, interest will be I=1 and we have room to alternate up and down (because 2<=Imax). This is equivalent to removing the Imax ceiling.
}

void ValidateInput(const int64_t A, const int64_t B, const int64_t I0, const int64_t Imin, const int64_t Imax) {
  std::cerr << A << " " << B << " " << I0 << " " << Imin << " "<<Imax << std::endl;
  assert(0<=A && A<=kMax);
  assert(0<=B && B<=kMax);
  assert(0<=Imax && Imax<=kMax);
  assert(0<=Imin && Imin<=Imax);
  assert(Imin<=I0 && I0<=Imax);
}

int main(){
  int64_t A, B, I0, Imin, Imax;
  std::cin >> A >> B >> I0 >> Imin >> Imax;
  ValidateInput(A, B, I0, Imin, Imax);
  std::cout << (Solve(A+B, A, I0-Imin, Imax-Imin)?"SI":"NO") << std::endl;
  return 0;
}

