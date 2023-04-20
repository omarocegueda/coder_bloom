#include <string>
#include <iostream>

const int64_t kMaxN = 1000; 
const int64_t kMaxM = 1000;

int64_t N, M;
std::string A[kMaxN+1];
std::string T[kMaxN+1];


int64_t SolveFast() {
  int64_t H[kMaxM+1];
  int64_t V[kMaxN+1];
  int64_t total_friends = 0;
  // Precompute horizontal distances
  H[0] = 0;
  for(int i=0;i<N;++i) {
    H[0] += (A[i][0] == 'A');
    total_friends += (A[i][0] == 'A');
  }
  for(int j=1;j<M;++j) {
    H[j] = H[j-1];
    for(int i=0;i<N;++i) {
      H[j] += (A[i][j] == 'A');
      total_friends += (A[i][j] == 'A');
    }
  }
  // Precompute vertical distances
  V[0] = 0;
  for(int j=0;j<M;++j) {
    V[0] += (A[0][j] == 'A');
  }
  for(int i=1;i<N;++i) {
    V[i] = V[i-1];
    for(int j=0;j<M;++j) {
      V[i] += (A[i][j] == 'A');
    }
  }
  // Compute full distances. Start with S[0][0]
  int64_t S[kMaxN+1][kMaxM+1];
  S[0][0] = 0;
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      if(A[i][j] == 'A') {
        S[0][0] += (i+j);
      }
    }
  }
  // Continue with the first row.
  for(int j=1;j<M;++j) {
    S[0][j] = S[0][j-1] + 2*H[j-1] - total_friends;
  }
  // Finally, the rest of the rows.
  for(int i=1;i<N;++i) {
    // Compute the first element of the row.
    S[i][0] = S[i-1][0] + 2*V[i-1] - total_friends;
    // The rest of the elements
    for(int j=1;j<M;++j) {
      S[i][j] = S[i][j-1] + 2*H[j-1] - total_friends;
    }
  }
  // Now return the minimum sum of distances.
  int64_t min_d = S[0][0];
  for(int i=0;i<N;++i) {
    for(int j=0;j<M;++j) {
      if(T[i][j] == 'T') {
        //std::cerr << "S["<< j+1<<","<<N-i<<"]="<<S[i][j] << std::endl;
        min_d = std::min(min_d, S[i][j]);
      }
    }
  }
  return min_d;
}

int main() {
  std::cin >> N >> M;
  for(int i=0; i<N;++i) {
    std::cin >> A[i];
  }
  for(int i=0; i<N;++i) {
    std::cin >> T[i];
  }
  std::cout << SolveFast() << std::endl;
  return 0;
}

