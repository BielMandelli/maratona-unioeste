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

    string c1, c2, lix, nx, year;
    vector<string> y = {
        "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"
    };
    map<string, int> mp;

    int mx = 12, i = 1;
    for (auto ss : y){
        mp[ss] = i;
        i++;
    }
    
    map<string, int> ans, yr;
    ans["Bessie"] = 0;
    yr["Bessie"] = mp["Ox"];
    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> lix >> lix >> nx >> year >> lix >> lix >> c2;

        int go = mp[year];
        int base = yr[c2];

        int dist = 0;

        if(nx == "previous") {
            dist = (base - go + 12) % 12;
            if(!dist) dist = 12;
            dist = -dist;
        } else {
            dist = (go - base + 12) % 12;
            if(!dist) dist = 12;
        }

        ans[c1] = ans[c2] + dist;
        yr[c1] = mp[year];
    }
    
    cout << abs(ans["Elsie"]) << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
