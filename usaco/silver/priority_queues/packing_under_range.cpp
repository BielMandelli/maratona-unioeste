#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    set<int> lw;
    map<int, vector<int>> mp;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin >> l >> r;
        mp[l].push_back(r);
        lw.insert(l);
    }
    
    lw.insert(1000000000+7);
    bool valid = true;
    int i=(*lw.begin());
    while(i<=1000000000){
        for(auto &v : mp[i]) pq.push(v);
        int cur = pq.top();
        pq.pop();
        if(pq.empty()) i = (*lw.lower_bound(i+1));
        else {
            if(pq.top()<=i) {
                valid = false;
                break;
            }
            i++;
        }
    }
    
    if(!pq.empty()) valid = false;
    
    cout << (valid ? "YES" : "NO") << endl;
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}