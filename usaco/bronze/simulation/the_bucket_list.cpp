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

    vector<pair<pair<int,int>, int>> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first.first >> t[i].first.second >> t[i].second;
    }

    sort(all(t));
    
    int ans = 0, disp = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    for (int i = 0; i < n; i++)
    {
        if(i != 0) while(t[i].first.first > p.top().first){
            disp += p.top().second;
            p.pop();
        }

        while(disp < t[i].second) {
            disp++;
            ans++;
        }

        disp -= t[i].second;
        p.push({t[i].first.second, t[i].second});
    }
    
    // while(!p.empty()){
    //     disp += p.top().second;
    //     p.pop();
    // }

    cout << ans << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
