#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())
#define ld long double

void dbg_out(string s) { cerr << endl; }
template <typename H, typename... T>
void dbg_out(string s, H h, T... t)
{
    do
    {
        cerr << s[0];
        s = s.substr(1);
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


template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}


void solution() {
    int n, k;
    cin >> n >> k;

    queue<int> disp;
    vector<int> a(n), cnt(n+1);
    for(auto &x : a) {
        cin >> x;
        cnt[x]++;
    }

    string s = pi(s);
}

signed main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution();
    }
}
