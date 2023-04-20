#include <vector>
#include <iostream>


void Flip(std::vector<int64_t> &A, std::size_t p) {
  for(std::size_t i = p, j = A.size()-1; i<j; ++i, --j) {
    std::swap(A[i], A[j]);
  }
}

bool IsSortedP(const std::vector<int64_t>& A, bool increasing) {
  for(std::size_t i= 1; i<A.size();++i) {
    if(increasing && (A[i] < A[i-1])) {
      return false;
    }
    if((!increasing) && (A[i] > A[i-1])) {
      return false;
    }
  }
  return true;
}
bool IsSorted(const std::vector<int64_t>& A) {
  return IsSortedP(A, true) || IsSortedP(A, false);
}


int main(){
  int N;
  std::cin >>  N;
  std::vector<int64_t> A(N);
  for(int i=0;i<N;++i) {
    std::cin >> A[i];
  }
  int M;
  std::cin >> M;
  for(int j=0;j<M;++j) {
    int p;
    std::cin >> p;
    Flip(A, p);
  }
  std::cout << (IsSorted(A)?"Ordenada":"No ordenada") << std::endl;
  return 0;
}

