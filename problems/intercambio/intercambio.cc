#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>

int FindNext(int current, const std::vector<int>& person_to_gift) {
  const int N = person_to_gift.size();
  int next = (current + 1) % N;
  while(next!=current) {
    if(person_to_gift[next]==-1) {
      return next;
    }
    next = (next+1) % N;
  }
  return -1;
}

std::vector<int> Choose(const int person, const int n_steal, std::vector<int>& gift_to_person, std::vector<int>& person_to_gift, int depth=0) {
  assert(person_to_gift[person]==-1);
  std::vector<int> best;
  // Choose one gift.
  for(int gift = 0; gift < gift_to_person.size(); ++gift) {
    const int current_holder = gift_to_person[gift];
    const bool stolen = current_holder != -1;
    if(n_steal <= 0 && stolen) {
      continue;
    }
    // Assign.
    gift_to_person[gift] = person;
    person_to_gift[person] = gift;
    if(stolen) {
      person_to_gift[current_holder] = -1;
    }
    int next = FindNext(person, person_to_gift);
    if(next == -1) {
      // Solved.
      if(best.empty() || person_to_gift[person]<best[person]) {
        best = person_to_gift;
      }
    } else {
      // Recurse.
      std::vector<int> opt = Choose(next, n_steal - stolen, gift_to_person, person_to_gift, depth+1);      
      if(best.empty() || opt[person]<best[person]) {
        best = opt;
      }
    }
    // Backtrack
    gift_to_person[gift] = current_holder;
    person_to_gift[person] = -1;
    if(stolen) {
      person_to_gift[current_holder] = gift;
    }
  }
  return best;
}

std::vector<int> Solve(const int N, const int K) {
  std::vector<int> gift_to_person(N, -1);
  std::vector<int> person_to_gift(N, -1);
  std::vector<int> sol = Choose(0, K, gift_to_person, person_to_gift);
  for(int i=0;i<N;++i) {
    sol[i] = sol[i]+1;
  }
  return sol;
}

void GenerateCase(const int index, const int N, const int K) {
  std::vector<int> sol = Solve(N, K);
  {
    std::ostringstream os;
    os<<"case_"<<index<<".in";
    FILE *F=fopen(os.str().c_str(), "w");
    fprintf(F, "%d %d\n", N, K);
    fclose(F);
  }
  {
    std::ostringstream os;
    os<<"case_"<<index<<".out";
    FILE *F=fopen(os.str().c_str(), "w");
    for(int i=0;i<N;++i) {
      fprintf(F, "%d ", sol[i]);
    }
    fprintf(F, "\n");
    fclose(F);
  }
}

void GenerateCases() {
  GenerateCase(0, 3, 3);
  GenerateCase(1, 3, 4);
  GenerateCase(2, 4, 2);
  GenerateCase(3, 4, 6);
  GenerateCase(4, 5, 1);
  GenerateCase(5, 5, 3);
  GenerateCase(6, 5, 5);
  GenerateCase(7, 6, 2);
  GenerateCase(8, 6, 3);
  GenerateCase(9, 6, 4);
}

int main() {
  GenerateCases();
  return 0;
  int N, K;
  std::cin >> N >> K;
  const std::vector<int> sol = Solve(N, K);
  for(int gift : sol) {
    std::cout << gift << " ";
  }
  std::cout << std::endl;
  return 0;
}

