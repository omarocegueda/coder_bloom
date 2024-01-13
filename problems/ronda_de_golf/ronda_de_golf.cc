#include <algorithm>
#include <iostream>
#include <vector>

struct Player {
  std::string name;
  int32_t score;
  bool operator < (const Player& other) const{
    if(score == other.score) {
      return name < other.name;
    }
    return score < other.score;
  }
};

int main() {
  std::vector<int32_t> P(18);
  for(int i=0;i<18;++i) {
    std::cin >> P[i];
  }
  int32_t N;
  std::cin >> N;
  std::vector<Player> players(N);
  for(Player& player : players) {
    std::cin >> player.name;
    player.score = 0;
    for(int j=0;j<18;++j) {
      int32_t s;
      std::cin >> s;
      player.score += s - P[j];
    }
  }
  std::sort(players.begin(), players.end());
  for(const Player& player : players) {
    std::cout << player.name << " ";
    if(player.score==0) {
      std::cout << "E";
    } else if(player.score>0) {
      std::cout << "+" << player.score;
    } else {
      std::cout << player.score;
    }
    std::cout << std::endl;
  }
  return 0;
}