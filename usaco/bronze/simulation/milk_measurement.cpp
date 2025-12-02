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

    vector<tuple<int,string,char, int>> c(n);
    map<string, int> vl;
    map<int,int> cnt;
    for(auto &[d,s,ch,v] : c) {
        cin >> d >> s >> ch >> v; 
        vl[s] = 0;
        cnt[d]++;
    }

    sort(all(c));

    // for(auto [a,b,cd,d] : c) cout << a << " " << b << " " << cd << " " << d << endl;

    int ans = 0;
    map<string, bool> act;
    for(auto [d,s,ch,value] : c){
        dbg(ch);
        vl[s] += (ch == '+' ? value : -value);
        vector<pair<int,string>> cand;
        if(cnt[d] > 1) {cnt[d]--; continue;}
        
        for(auto [k , v] : vl){
            cand.push_back({v, k});
            dbg(d, k, v);
        }
        dbg("--------");
        sort(rall(cand));

        int last = -1e9;
        bool chg = false, alter = false;
        for(auto [v, k] : cand){
            if(last != -1e9) if(last != v or alter) {
                alter = true;
                if(act[k] == true) chg = true;
                act[k] = false;
                continue;
            }

            if(act[k] == false) chg = true;
            act[k] = true;

            last = v;
        }

        if(chg) ans++;
    }

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
