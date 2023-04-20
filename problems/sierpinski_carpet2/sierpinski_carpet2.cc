#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <set>
#include <fstream>
#include <random>

// Returns the color of the NxN Sierpinski's carpet at (r, c)
char SierpinskiCarpetColor(const uint64_t N, uint64_t r, uint64_t c) {
  if(N == 1) {
    return '.'; 
  }
  assert(N%3==0);
  uint64_t k = N/3;
  uint64_t ii = r/k;
  uint64_t jj = c/k;
  if(ii==1 && jj==1) {
    return 'X';
  }
  return SierpinskiCarpetColor(k, r%k, c%k);
}

void SolveSingle() {
  uint64_t N;
  uint64_t L;
  std::cin >> N >> L;
  for(uint64_t i=0;i<L;++i) {
    uint64_t r, c;
    std::cin >> r >> c;
    --r;
    --c;
    assert(r >= 0);
    assert(c >= 0);
    assert(r < N);
    assert(c < N);
    std::cout << SierpinskiCarpetColor(N, r, c);
  }
  std::cout<<std::endl;
}

uint64_t mypow(uint64_t base, uint64_t exp) {
  if(exp == 0) {
    assert(base != 0);
    return 1;
  }
  if(exp == 1) {
    return base;
  }
  uint64_t sub = mypow(base, exp/2);
  if(exp%2 == 0) {
    return sub*sub;
  }
  return base*sub*sub;
  
}
void GenerateCase(const int case_index, const uint64_t N, const uint64_t L, std::default_random_engine& generator) {
  assert(N < mypow(2,62));
  std::cerr << "Generating case "<< case_index<< std::endl;
  std::string sol(L, ' ');
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    F << N << " " << L << std::endl;
    std::uniform_int_distribution<int64_t> distribution(1, N);
    for(uint64_t i = 0; i<L; ++i) {
      const uint64_t r = distribution(generator);
      const uint64_t c = distribution(generator);
      F << r << " " << c << std::endl;
      assert(r > 0);
      assert(c > 0);
      assert(r <= N);
      assert(c <= N);
      sol[i] = SierpinskiCarpetColor(N, r-1, c-1);
    }
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    F << sol << std::endl;  
    F.close();
  }
}


void GenerateCases() {
  std::random_device rd;
  std::default_random_engine generator(rd());
  GenerateCase(0, mypow(3, 8), 10, generator);
  GenerateCase(1, mypow(3, 9), 12, generator);
  GenerateCase(2, mypow(3, 10), 25, generator);
  GenerateCase(3, mypow(3, 11), 50, generator);
  GenerateCase(4, mypow(3, 12), 50, generator);
  GenerateCase(5, mypow(3, 14), 100, generator);
  GenerateCase(6, mypow(3, 15), 100, generator);
  GenerateCase(7, mypow(3, 17), 100, generator);
  GenerateCase(8, mypow(3, 18), 100, generator);
  GenerateCase(9, mypow(3, 20), 100, generator);
  GenerateCase(10, mypow(3, 21), 200, generator);
  GenerateCase(11, mypow(3, 23), 250, generator);
  GenerateCase(12, mypow(3, 25), 250, generator);
  GenerateCase(13, mypow(3, 27), 500, generator);
  GenerateCase(14, mypow(3, 29), 500, generator);
  GenerateCase(15, mypow(3, 31), 1000, generator);
  GenerateCase(16, mypow(3, 33), 1000, generator);
  GenerateCase(17, mypow(3, 35), 1000, generator);
  GenerateCase(18, mypow(3, 37), 1000, generator);
  GenerateCase(19, mypow(3, 39), 1000, generator);
}

int main(){
  /*uint64_t lim =mypow(2, 62);
  std::cout << "2^62=" << lim << std::endl;
  for(int i=0;i<50;++i) {
    uint64_t p = mypow(3,i);
    std::cout <<"3^"<<i<<"="<<p<<". ("<<p<<"<"<<lim<<")="<<(p<lim)<<std::endl;
  }*/
  //SolveSingle();
  GenerateCases();
  return 0;
}
