#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'
const int MOD = 1e9+7;

int fastexp(int x,int y){
    int ans = 1; 
    x = x % MOD;
    while (y)
    { 
        if(y%2) ans = ans * x % MOD;
        x = x * x % MOD;
        y /= 2;
    } 
    return ans;
}

int calc(vector<int> &a){
    int n = a.size();
    if (n == 1) return a[0];

    int x = a[0];
    for (auto &y : a) y = y - x;
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    
    for (int i = 0; i < n - 1; i++) pq.push({a[i] + a[i + 1], {i, i + 1}});

    vector<int> b;
    for (int i = 0; i < n-1; i++)
    {
        auto v = pq.top();
        pq.pop();
        b.push_back(v.first);
        v.second.second++;
        if (v.second.second < n)
        {
            v.first = a[v.second.first] + a[v.second.second];
            pq.push(v);
        }
    }
    a.clear();
    
    int ans = calc(b);
    ans += (fastexp(2, n - 1) * x) % MOD;
    ans %= MOD;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = calc(a);

    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}