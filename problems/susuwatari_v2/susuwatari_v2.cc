#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <fstream>


int64_t Solve(const int64_t N, const int64_t C, const int64_t S, const int64_t t, const int64_t T) {
  const int64_t max_rounds = ((T / t) + 1) / 2;  // The Susuwatari will carry coal at most `max_rounds` times.
  const int64_t min_pieces_per_round = (N+max_rounds-1)/max_rounds;  // Othewise we will not move all N pieces in the `max_rounds` rounds.
  const int64_t min_susuwatari_per_piece = (C + S - 1) / S; // Othewise the pieces would be too heavy.
  return min_pieces_per_round * min_susuwatari_per_piece;
}

int64_t Incorrect1(const int64_t N, const int64_t C, const int64_t S, const int64_t t, const int64_t T) {
  const int64_t max_rounds = ((T / t) + 1) / 2;  // The Susuwatari will carry coal at most `max_rounds` times.
  const int64_t min_pieces_per_round = N/max_rounds;  // Othewise we will not move all N pieces in the `max_rounds` rounds.
  const int64_t min_susuwatari_per_piece = (C + S - 1) / S; // Othewise the pieces would be too heavy.
  return min_pieces_per_round * min_susuwatari_per_piece;
}

int64_t Incorrect2(const int64_t N, const int64_t C, const int64_t S, const int64_t t, const int64_t T) {
  const int64_t max_rounds = (T / t) / 2;  // The Susuwatari will carry coal at most `max_rounds` times.
  const int64_t min_pieces_per_round = (N+max_rounds-1)/max_rounds;  // Othewise we will not move all N pieces in the `max_rounds` rounds.
  const int64_t min_susuwatari_per_piece = (C + S - 1) / S; // Othewise the pieces would be too heavy.
  return min_pieces_per_round * min_susuwatari_per_piece;
}

int64_t Incorrect3(const int64_t N, const int64_t C, const int64_t S, const int64_t t, const int64_t T) {
  const int64_t max_rounds = ((T / t) + 1) / 2;  // The Susuwatari will carry coal at most `max_rounds` times.
  const int64_t min_pieces_per_round = (N+max_rounds-1)/max_rounds;  // Othewise we will not move all N pieces in the `max_rounds` rounds.
  const int64_t min_susuwatari_per_piece = C / S; // Othewise the pieces would be too heavy.
  return min_pieces_per_round * min_susuwatari_per_piece;
}

int64_t Incorrect4(const int64_t N, const int64_t C, const int64_t S, const int64_t t, const int64_t T) {
  const int64_t max_rounds = (T / t) / 2;  // The Susuwatari will carry coal at most `max_rounds` times.
  const int64_t min_pieces_per_round = N/max_rounds;  // Othewise we will not move all N pieces in the `max_rounds` rounds.
  const int64_t min_susuwatari_per_piece = C / S; // Othewise the pieces would be too heavy.
  return min_pieces_per_round * min_susuwatari_per_piece;
}

const int64_t kMaxT = 1000000000000000000;

void GenerateCase(const int32_t case_index, const int64_t min_rand, const int64_t max_rand, std::default_random_engine& engine) {
  std::cerr << "Generating case "<< case_index<<std::endl;
  std::uniform_int_distribution<int64_t> uniform_NCt(min_rand, max_rand);
  int64_t N, C, S, t, T;
  int64_t sol;
  bool good = false;
  while(!good) {
    N = uniform_NCt(engine);
    C = uniform_NCt(engine);
    t = uniform_NCt(engine);
    std::uniform_int_distribution<int64_t> uniform_S(C-C/2, C+C/2);
    S = uniform_S(engine);
    std::uniform_int_distribution<int64_t> uniform_T(t, 10*t);
    T = uniform_T(engine);
    sol = Solve(N, C, S, t, T);
    int num_incorrect = 0;
    num_incorrect += Incorrect1(N, C, S, t, T)!=sol;
    num_incorrect += Incorrect2(N, C, S, t, T)!=sol;
    num_incorrect += Incorrect3(N, C, S, t, T)!=sol;
    num_incorrect += Incorrect4(N, C, S, t, T)!=sol;
    good = num_incorrect>=3; // at least 2 solutions incorrect solutions detected
    
  }
  // Write input
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".in";
    
    std::ofstream F;
    F.open (os.str());
    F<<N<<" "<<C<<" "<<S<<" "<<t<<" "<<T<<std::endl;
    F.close();
  }
  // Write output
  {
    std::ostringstream os;
    os<<"case_"<<case_index<<".out";
    std::ofstream F;
    F.open (os.str());
    const int64_t sol = Solve(N, C, S, t, T);
    F << sol << std::endl;
    F.close();
  }
}


void GenerateCases() {
  std::random_device rd;
  std::default_random_engine engine(rd());

  GenerateCase(0, 1, 10, engine);
  GenerateCase(1, 100, 1000, engine);
  GenerateCase(2, 1000, 10000, engine);
  GenerateCase(3, 10000, 100000, engine);
  GenerateCase(4, 100000, 1000000, engine);
  GenerateCase(5, 1000000, 10000000, engine);
  GenerateCase(6, 10000000, 100000000, engine);
  GenerateCase(7, 100000000, 1000000000, engine);
  GenerateCase(8, 100000000, 1000000000, engine);
  GenerateCase(9, 100000000, 1000000000, engine);
}


void Solve() {
  int64_t N, C, S, t, T;
  std::cin >> N >> C >> S >> t >> T;
  std::cout << Solve(N, C, S, t, T) << std::endl;
}

int main() {
  Solve();
  return 0;
  GenerateCases();
  return 0;
}

