#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

const int N = 20005; 

int n, m;  
int d[4*N], c[4*N], s[4*N];
ll dp[4*N];  
ll a[N], b[N], x[N], y[N]; 
ll val, id; 
vector <int> adj[4*N]; 

set <ll> sa;  
map <ll,int> ma; 

void reduce(){
    for(ll va: sa) ma[va] = ++id; 
    f(i,1,n+1) a[i] = ma[a[i]], b[i] = ma[b[i]]; 
    f(i,1,m+1) x[i] = ma[x[i]], y[i] = ma[y[i]]; 
}

void add(){
    f(i,1,n+1){
        d[a[i]]++, d[b[i]+1]--; 
    }
    f(i,1,id+1){
        c[i] = d[i] + c[i-1];   
    }
    f(i,1,id+1){
        s[i] = s[i-1] + ((c[i] > 0) ? 1 : 0); 
    }
}

int sum(int l, int r){
    return s[r] - s[l-1]; 
}
int main(){
    cin >> n; 
    f(i,1,n+1){
        cin >> a[i] >> b[i];  
        sa.insert(a[i]), sa.insert(b[i]); 
    }
    cin >> m; 
    f(i,1,m+1){
        cin >> x[i] >> y[i] >> val; 
        sa.insert(x[i]), sa.insert(y[i]); 
    }
    std::cerr << "n="<<n << "m="<<m <<std::endl;
    reduce(); 
    add(); 

    vector <pair<int,int>> v; 
    f(i,1,m+1){
        if(sum(x[i], y[i]) > 0) adj[x[i]].push_back(y[i]); 
    }

    fa(i,id,1){
        dp[i] = dp[i+1]; 
        for(int x: adj[i]) dp[i] = max(dp[i], dp[x+1] + 1); 
    }
    cout << max((ll) dp[1] * val, 0LL) << "\n"; 
    return 0; 
}