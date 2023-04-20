#include <iostream>
#include <vector>

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

int main() {
  int N, R;
  std::cin >> N >> R;
  const std::vector<int> sol = Solve(N, R);
  for(int gift : sol) {
    std::cout << gift << " ";
  }
  std::cout << std::endl;
  return 0;
}

