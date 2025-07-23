#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<int> ans(n);
    vector<pair<pair<int,int>, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());

    int cur = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < n; i++)
    {
        if(pq.empty() or pq.top().first >= a[i].first.first){
            cur++;
            pq.push({a[i].first.second, cur});
            ans[a[i].second] = cur;
        } else {
            pair<int,int> mn = pq.top();
            pq.pop();
            pq.push({a[i].first.second, mn.second});
            ans[a[i].second] = mn.second;
        }
    } 
    
    cout << cur << endl;
    for(auto x : ans) cout << x << " ";
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}