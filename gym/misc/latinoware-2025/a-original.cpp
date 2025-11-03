#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
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

void solution(){
    string s;
    getline(cin, s);
    cout << "What is the name of your team?" << endl;
    cout << "Our name is " << s << "." << endl;
    cout << "My apologies, I did not understand. What is your team name?" << endl;
    cout << "We are team " << s << "." << endl;
    cout << "I am really sorry. Could you please repeat it once again?" << endl;
    for(auto &x : s) x = toupper(x);
    cout << "WE ARE TEAM " << s << "!!!" << endl;
    cout << "Oh, now I see. Here are your badges. Good luck!" << endl;
}

signed main(){
    // fastio;
    int cases = 1;
    // cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}