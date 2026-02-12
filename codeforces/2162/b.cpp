#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int long long

bool palindrome(string s){
    for (int i = 0, j = s.size()-1; i < j; i++, j--)
    {
        if(s[i] != s[j]) return false;
    }
    return true;
}

bool non(string s, int l, int r){
    for (int i = 1; i < sz(s); i++)
        if (s[i] < s[i-1]) return false;
    return true;
}

bool check(string s, int l, int r){
    string newS, remove;
    for (int i = 0; i < s.size(); i++)
    {
        if(l<=i && i<= r) remove.push_back(s[i]);
        else newS.push_back(s[i]);
    }
    dbg(remove);
    if(palindrome(newS)) return true;
    return false;
}

void ans(int l, int r){
    if(!l && !r) cout << 0 << endl;
    else {
        cout << r-l+1 << endl;
        for(int i = l; i<=r; i++) cout << i+1 << " ";
        cout << endl;
    }
}

void solution(){
    int n;
    string s;
    cin >> n >> s;
    bool can = true;
    dbg(n);

    set<pair<int,int>> range;
    if(palindrome(s)) { ans(0,0); return; }
    
    for (int i = 0; i < n; i++)
    {
        string snew;
        int j = i+1;
        bool can = 1, turn = 0;
        if(s[i] == '1') turn = 1;
        range.insert({i, i});
        while(can && j < n) {
            if(s[j] == '1') turn = 1;
            if(s[j] == '0' && turn) break; 
            range.insert({i,j});
            j++;
        }
    }

    for(auto [l,r] : range){
        if(check(s, l, r)) {ans(l,r); return;}
    }
    cout << -1 << endl;
    // cout << "------------" << endl;
}

signed main(){
    fastio;
    int t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}