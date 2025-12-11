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

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int n;
    cin >> n;

    int siz = 0;
    vector<pair<int, string>> a(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        string s;
        getline(cin, s);

        a[i].first = l;
        a[i].second = s;
    }
    cout << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
    
}