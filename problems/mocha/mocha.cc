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
int DP[2][10110];
int C[110],R[110],M[110];
int main (){
  memset(DP,-1,sizeof(DP));
  int N,D,E,r;
  cin>>N>>D>>E>>r;
 DEB(N);DEB(D);  
  REP(i,N) {
    cin>>C[i]>>R[i]>>M[i];
  }
  C[N]=-10;
  R[N]=-1;
  M[N]=0;
  N++;
  int cur=0;
  int pre=1;
  DP[pre][E]=r;
  int MXD=E;
  REP(i,D) {
    int nMXD=0;
    REP(j,MXD+1){
      if (DP[pre][j]==-1) continue;
      int rx = DP[pre][j];
      int cx=j;
      REP(w,N){
        if (M[w]>rx) continue;
        if (cx-C[w]<0) continue;
        if (rx+R[w]<0) continue;
        int cn=cx-C[w];
        int rn=rx+R[w];
//	DEB(i);DEB(cn);DEB(rn);
        nMXD=max(cn,nMXD);
        if (DP[cur][cn]==-1 || DP[cur][cn]<rn) {
          DP[cur][cn]=rn;
        }
      }
    }
    cur=(cur+1)%2;
    pre =(pre+1)%2;
    memset(DP[cur],-1,sizeof (DP[cur]));
    MXD=nMXD;
  }
  int res=0;
  REP(i,MXD){
    res = max(res,DP[pre][i]);
  }
  if(res<=r) cout<<"Pa pronto es tarde\n";
  else
  cout<<res<<"\n";
  return 0;
}