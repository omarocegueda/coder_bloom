#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using Intervalos = vector<pair<int64_t,int64_t>>;

int solve(int mx, const Intervalos& C, const Intervalos& A) {
  vector<int> dp(mx);
  unordered_set<int> clases;
  vector<vector<int>> add(mx);
  vector<vector<int>> rem(mx);
  vector<vector<int>> start(mx);
  vector<vector<int>> stop(mx);
  for (int i = 0; i != C.size(); ++i) {
    auto [a, b] = C[i];
    add[a].push_back(i);
    rem[b].push_back(i);
  }
  for (int i = 0; i != A.size(); ++i) {
    auto [a, b] = A[i];
    start[a].push_back(i);
    stop[b].push_back(i);
  }
  int rv = 0;
  unordered_set<int> actividades;
  for (int i = 0; i != mx; ++i) {
    clases.insert(add[i].begin(), add[i].end());
    if (i > 0) dp[i] = max(dp[i], dp[i-1]);
    if (!clases.empty()) {
      actividades.clear();
      for (auto j : rem[i]) clases.erase(j);
    } else {
      // Iniciar actividades
      actividades.insert(start[i].begin(), start[i].end());
      // Terminar actividades
      for (int ai : stop[i]) {
        // cerr << i << ": Terminando " << ai << endl;
        if (actividades.erase(ai)) {
          auto &r = dp[A[ai].second + 1];
          r = max(r, dp[A[ai].first] + 1);
        }
      }
    }
    rv = max(rv, dp[i]);
  }
  // cerr << "Total " << rv << endl;
  return rv;
}

void collect(map<int64_t,int>& mp, Intervalos& v) {
  for (auto [a, b] : v) {
    mp.emplace(a, -1);
    mp.emplace(b, -1);
    mp.emplace(b + 1, -1);
  }
}
void compress(map<int64_t,int>& mp, Intervalos& v) {
  for (auto &[a, b] : v) {
    a = mp[a];
    b = mp[b];
  }
}

void assign(map<int64_t,int>& mp) {
  int i = 0;
  for (auto& [k, v] : mp) v = i++;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<pair<int64_t,int64_t>> C(n);
  for (auto &c : C) cin >> c.first >> c.second;
  int64_t f; int m; cin >> m;
  vector<pair<int64_t,int64_t>> A(m);
  for (auto &a : A) cin >> a.first >> a.second >> f;
  if (f <= 0) {
    cout << "0\n";
    return 0;
  }

  map<int64_t, int> mp;
  collect(mp, A);
  collect(mp, C); 
  assign(mp); 
  compress(mp, A);
  compress(mp, C);  
  int sin_clases = solve(mp.size(), {}, A);
  int con_clases = solve(mp.size(), C, A);
  //cout << f * sin_clases <<" "<<f*con_clases << '\n';
  cout << f * (sin_clases -con_clases) << '\n';
  return 0;
}