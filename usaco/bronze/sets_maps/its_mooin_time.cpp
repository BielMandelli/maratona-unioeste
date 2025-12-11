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
    int n, f;
    cin >> n >> f;

    string s;
    cin >> s;

    map<string, int> poss;
    set<string> ans;

    for (int i = 0; i < n-2; i++)
    {
        string cur = s.substr(i,3);
        poss[cur]++;
    }
    
    for(auto [k,v] : poss){
        if(k[0] != k[1] && k[1] == k[2] && v >= f) ans.insert(k);
    }

    for (int i = 0; i < n-2; i++)
    {
        map<string, int> poss2 = poss;

        for (int j = max(0, i-2); j <= min(n-3, i+2); j++)
        {
            string cur = s.substr(j, 3);
            if(sz(cur) == 3) poss[cur]--;
        }
        
        for (int j = 0; j < 3; j++)
        {
            string cur = s.substr(i, 3);
            poss[cur]--;

            for (int c = 0; c < 26; c++)
            {
                cur[j] = 'a'+c;
                if(sz(cur) == 3 && cur[0] != cur[1] && cur[1] == cur[2] && poss[cur] == f-1) ans.insert(cur); 
            }
        }
        poss = poss2;
    }
    
    
    cout << sz(ans) << endl;
    for (auto ss : ans) cout << ss << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
