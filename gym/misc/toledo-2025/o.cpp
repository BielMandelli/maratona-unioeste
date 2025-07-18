#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!i or !j or i+1 == n or j+1 == n) a[i][j] = '*';
            if(i == j) a[i][j] = '*';
            if(i+j == n-1) a[i][j] = '*';
        }
    }
    

    for(auto x : a){
        for(auto y : x) cout << y;
        cout << endl;
    }
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}