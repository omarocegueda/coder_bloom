#include <bits/stdc++.h>
using namespace std; 

#define f(i,a,b) for(int i = a; i < b; i++)
#define fa(i,a,b) for(int i = a; i >= b; i--)

int n, m; 

vector <string> get(vector <string> v, char u){
    vector <string> ans; 
    if(u == '^'){
        int n = v.size(); 
        ans.resize(2*n);

        f(i,0,n){
            int m = v[i].size();  
            f(j,0,m)  ans[i].push_back(v[i][j]); 
        } 
        f(i,n+1,2*n){
            int m = v[2*n-1-i].size(); 
            f(j,0,m)  ans[i].push_back(v[2*n-1-i][j]); 
        }
    }
    if(u == '>'){
        int n = v.size(); 
        ans.resize(n); 
        f(i,0,n){
            int m = v[i].size(); 
            fa(j,m-1,0) ans[i].push_back(v[i][j]); 
            f(j,0,m) ans[i].push_back(v[i][j]); 
        }
    }
    if(u == '<'){
        int n = v.size(); 
        ans.resize(n); 
        f(i,0,n){
            int m = v[i].size(); 
            f(j,0,m) ans[i].push_back(v[i][j]); 
            fa(j,m-1,0) ans[i].push_back(v[i][j]); 
        }
    }
    if(u == 'V'){
        int n = v.size(); 
        ans.resize(2*n);

        f(i,n+1,2*n){
            int m = v[2*n-1-i].size(); 
            f(j,0,m)  ans[i].push_back(v[2*n-1-i][j]); 
        }
        f(i,0,n){
            int m = v[i].size();  
            f(j,0,m)  ans[i].push_back(v[i][j]); 
        } 
    }
    return ans; 
}
int main(){
    cin >> n >> m; 
    vector <string> v(n); 


    f(i,0,n){
        v[i].resize(m); 
        f(j,0,m) cin >> v[i][j]; 
    }

    int t; cin >> t; 
    string s; cin >> s; 

    fa(i,t-1,0){
        v = get(v, s[i]); 
    }
    int l = v.size(); 
    f(i,0,l){
        for(char c: v[i]) cout << c; 
        cout << "\n"; 
    }
    return 0; 
}
