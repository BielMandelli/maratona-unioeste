#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int n;
    cin >> n;

    int aux;
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        ans.insert(aux);
    }
    
    cout << ans.size() << endl;
    
    return 0;
}