#include <iostream>
#include <cassert>

int64_t Solve(const int64_t N, const int64_t C, const int64_t S, const int64_t t, const int64_t T) {
  const int64_t max_rounds = ((T / t) + 1) / 2;  // The Susuwatari will carry coal at most `max_rounds` times.
  const int64_t min_pieces_per_round = (N+max_rounds-1)/max_rounds;  // Othewise we will not move all N pieces in the `max_rounds` rounds.
  const int64_t min_susuwatari_per_piece = (C + S - 1) / S; // Othewise the pieces would be too heavy.
  return min_pieces_per_round * min_susuwatari_per_piece;
}

void Solve() {
  int64_t N, C, S, t, T;
  std::cin >> N >> C >> S >> t >> T;
  assert(1 <= N && N<=1000000000);
  assert(1 <= C && C<=1000000000);
  assert(1 <= S && S<=1000000000);
  assert(1 <= t && t<=1000000000);
  assert(1 <= T && T<=1000000000000);
  std::cout << Solve(N, C, S, t, T) << std::endl;
}

int main() {
  Solve();
  return 0;
}

