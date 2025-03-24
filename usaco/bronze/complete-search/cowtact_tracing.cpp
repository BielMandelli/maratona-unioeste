#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int n, t;
    cin >> n >> t;
    set<int> infected;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        if(c == '1') infected.insert(i);
    }

    set<int> p0;
    int a,b,c;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
    }
    
    
    

    return 0;
}