 #include <bits/stdc++.h>       
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl;}
template<typename H, typename ...T>
void dbg_out(string s, H h, T... t){
    do{cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(auto &x : a) cin >> x.first >> x.second;

    int final, gas;
    cin >> final >> gas;

    for (int i = 0; i < n; i++)
    {
        a[i].first = abs(final-a[i].first);
    }
    
    priority_queue<int> pq;

    int cur = gas;
    int ans = 0;

    sort(all(a));

    for (int i = 0; i < n; i++)
    {
        while(cur < a[i].first){
            if(pq.empty()) {
                cout << -1 << endl;
                return;
            }

            cur += pq.top();
            pq.pop();
            ans++;
        }

        if(cur >= a[i].first) pq.push(a[i].second);
    }

    while (cur < final)
    {
        if(pq.empty()) {
            cout << -1 << endl;
            return;
        }

        cur += pq.top();
        pq.pop();
        ans++;
    }
    
    cout << ans << endl;
}

signed main(){
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
