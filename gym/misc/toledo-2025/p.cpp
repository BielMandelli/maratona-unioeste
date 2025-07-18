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
    for (int i = 1, j = n-1; i <= n; i++, j--)
    {   
        int cur = 0;
        for(;cur < j; cur++) cout << " ";
        for (int k = i; k > 0; k--)
        {
            cout << "*" << (k-1 > 0 ? " " : "");
        }
        cout << endl;
    }
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}