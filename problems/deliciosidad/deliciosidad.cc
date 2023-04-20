#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>

#define REP(i,n) for(int i=0,n_=(n);i<n_;i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FOR(i,a,b) for (int i=a,b_=b;i<=(b_);i++)
#define DEB(x) cerr<<#x<<":"<<x<<"\n"
using namespace std;

priority_queue<pair<int,int>> Q[370];
void KeepK(int d, int id, priority_queue<pair<int,int>>&w) {
  w.push(make_pair(-d,id));
  while (w.size()>7) w.pop();
}
int mask[10000];
int SolveRec(vector<pair<int,int>>*D, int pos) {
  if(pos>=7) return 0;
  int mx=-1;
  //DEB(pos);
  //DEB(D[pos].size());
  REP(i,D[pos].size()){
    if (mask[D[pos][i].second]) continue;
    mask[D[pos][i].second]=true;
    int t=SolveRec(D,pos+1);
    mask[D[pos][i].second]=false;
    if (t<0){
       continue;
    }
    mx = max(mx, t-D[pos][i].first);
    
  }
  return mx;
  
}
int Solve(int X) {
  memset(mask,0,sizeof (mask));
  priority_queue<pair<int,int>> QQ;
  vector<pair<int,int>> D[7];
  REP(i,7){
    if (Q[i+X].empty()) return -1;
    QQ=Q[i+X];
    while (!QQ.empty()){
      D[i].push_back(QQ.top());
      QQ.pop();
    }
  }
  //REP(i,7){REP(j,D[i].size())printf("(%d,%d) ", -D[i][j].first, D[i][j].second);printf("\n");}
  //return 0;
  return SolveRec(&D[0],0);
}

int main () {
  int n;
  cin>>n;
  REP(i,n) {
    int a,b,d;
    cin>>a>>b>>d;
    FOR(k,a,b) {
      KeepK(d,i,Q[k]);
    }
  }
  //DEB("go");
  int mx=-1,id=-1;
  FOR(i, 1, 365-7) {
    int s=Solve(i);
   // DEB(s);
    if (s>mx) {
      
      mx=s;
      id=i;
    }
  }
  if (mx>0)
    cout<<mx<<" "<<id<<"\n";
  else
    cout << "Quiero viajar\n";
  return 0;
}
