#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#define int long long

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int n;
    cin >> n;
    
    vector<int> cnt(n+1), a(n);
    vector<pair<int,int>> io(n+1);

    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(!cnt[a[i]]) io[a[i]] = {i, -1};
        cnt[a[i]]++;
        
        io[a[i]] = {io[a[i]].first, i};
    }

    vector<int> a2;

    for (int i = 1; i <= n; i++) if (cnt[i]) a2.push_back(i);

    if(sz(a2) == 1){
        cout << 0 << endl;
        return;
    }

    int mxEx = 0, mxIn = cnt[a2[0]];

    for (int i = 1; i < sz(a2); i++)
    {
        int cur = a2[i], prv = a2[i-1];

        int keepmxEx = max(mxEx, mxIn);
        int keepmxIn = 0;

        bool valid = true;
        if (cur == prv + 1 && io[cur].second >= io[prv].first) valid = false;
    
        if(valid) keepmxIn = cnt[cur] + max(mxEx, mxIn);
        else keepmxIn = cnt[cur] + mxEx;

        mxEx = keepmxEx; mxIn = keepmxIn;
    }

    cout << n - max(mxIn, mxEx) << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}