

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <optional>

int32_t MakeBestSelection(const int32_t my_rating, const std::vector<int32_t>& theirs, const std::vector<bool>& assigned) {
  std::optional<int32_t> selected = std::nullopt;
  for(int32_t j=0; j<theirs.size(); ++j) {
    if(assigned[j]) {
      continue;
    }
    if(!selected.has_value()) {
      selected = j;
      // Can defeat their `j`-th player 
      if(my_rating > theirs[selected.value()]) {
        return selected.value();
      }
      continue;
    }
    // At this point we know that `selected` has value, I cannot defeat that player 
    if(my_rating > theirs[j]) {
      // This is the strongest player I can defeat
      return j;
    }
  }
  assert(selected.has_value());
  assert(!assigned[selected.value()]);
  return selected.value();
}

int32_t SolveSlow(const int32_t N, const std::vector<int32_t>& A, const std::vector<int32_t>& B) {
  std::vector<bool> assigned(N, false);
  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  int32_t n_defeated = 0;
  for(int32_t i=N-1; i>=0; --i) {
    const int32_t selected = MakeBestSelection(A[i], B, assigned);
    assigned[selected] = true;
    if(A[i] > B[selected]) {
      ++n_defeated;
    }
  }
  return n_defeated;
}

int main() {
  int32_t N;
  std::cin >> N;
  std::vector<int32_t> A(N);
  std::vector<int32_t> B(N);
  for(int32_t i=0;i<N;++i) {
    std::cin >> A[i];
  }
  for(int32_t i=0;i<N;++i) {
    std::cin >> B[i];
  }
  return 0;
}