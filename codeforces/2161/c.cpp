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

#define int long long

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int sum = 0;
    for(auto &y : a) {
        cin >> y;
        sum += y;
    }

    sort(all(a));

    deque<int> mx;
    queue<int> mn;
    int mxP = sum/x;
    for (int i = 0; i < n; i++) {
        if(i < n-mxP) mn.push(a[i]);
        else mx.push_back(a[i]);
    }
    
    int s = 0, p = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int cur;

        if(!mx.empty() && ((s%x) + mx.back()) >= x){
            cur = mx.back();
            mx.pop_back();
            p += cur;
        } else if(!mn.empty()){
            cur = mn.front();
            mn.pop();
        } else {
            cur = mx.front();
            mx.pop_front();
        }

        dbg(cur, s, p);
        ans.push_back(cur);
        s += cur;
    }
    
    cout << p << endl;
    for(auto y : ans) cout << y << " ";
    cout << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}