#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n, s;
    cin >> n >> s;

    vector<int> b(n);
    multiset<int, greater<int>> freq;
    int sum = 0, i = 0;
    for (auto &x : b)
    {
        cin >> x;
        freq.insert(x);
        sum += x;
        i++;
    }

    int ans = 0;
    while (sum > s)
    {
        auto it = freq.begin();
        int half = (*it % 2) ? (*it / 2) + 1 : *it / 2; 
        sum -= half;
        int ex = *it-half;
        if(ex > 0) freq.insert(ex);
        freq.erase(it);
        ans++;
    }

    cout << ans << endl;

    return 0;
}