#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template <typename H, typename... T>
void dbg_out(string s, H h, T... t)
{
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int INF = 1e9;
#define int long long

void solution()
{
    int n;
    string s;
    cin >> n >> s;  

    deque<char> dq;

    int ans = 1, cur = 1;
    char last = '0';
    
    string lastString = s;
    for (int i = 0; i < n; i++)
    {
        string news;
        news += lastString[n-1];
        lastString.pop_back();
        news += lastString;

        // cout << "cur i : " << i << " string: " << news << endl;
        cur = 1;

        last = '0';
        for (int j = 0; j < n; j++)
        {
            if(last == '0') last = news[j];
            else {
                if(last != news[j]) cur++;
                last = news[j];
            }
        }
        
        lastString = news;
        ans = max(ans, cur);
    }
    
    cout << ans << endl;
}

signed main()
{
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}
