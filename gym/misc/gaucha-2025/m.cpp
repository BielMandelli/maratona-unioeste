#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

string s;
vector<int> kmp(string& cur){
    vector<int> p(cur.size());
	for (int i = 1, j = p[i-1]; i < cur.size(); i++) {
		while (j and cur[j] != cur[i]) j = p[j-1];
		if (cur[j] == cur[i]) j++;
		p[i] = j;
	}
	return p;
}


void solve(){
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    string newS = rev + "#" + s;
    vector<int> p = kmp(newS);

    int mx = p.back(); 
    int ans = s.size() - mx;

    cout << ans << endl;
}

signed main(){  
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}