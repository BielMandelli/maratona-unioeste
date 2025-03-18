#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    
    int n, c, p, i;

    cin >> n >> c;

    set<int> inf;

    for (int k = 0; k < c; k++)
    {
        cin >> p >> i;
        int x;
        for (int j = 0; j < i; j++)
        {
            cin >> x;
            inf.insert(x);
        }
    }
    
    auto it = inf.begin();
    for (int i = 1; i <= n; i++)
    {
        if(*it != i) cout << i << endl;
        else it++;
    }
    
}