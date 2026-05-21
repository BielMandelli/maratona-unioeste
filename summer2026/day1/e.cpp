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

#define int long long   

int n;
void solution(){
    vector<int> ans;
    queue<int> q;

    for (int i = 0,x; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    
    stack<int> wait;

    int mn = 1;

    while (!q.empty())
    {
        int cur = q.front();

        if (cur == mn){
            ans.push_back(cur);
            mn++;
            q.pop();
        } else if(!wait.empty() && wait.top() == mn){
            ans.push_back(wait.top());
            wait.pop();
            mn++;
        } else {
            wait.push(cur);
            q.pop();
        }
    }

    while(!wait.empty()){
        ans.push_back(wait.top());
        wait.pop();
    }
    
    bool valid = true;
    for (int i = 0; i < sz(ans)-1; i++)
    {
        if(ans[i]+1 != ans[i+1]) valid = false;
    }
    
    cout << (valid ? "yes" : "no") << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    while(cin >> n && n != 0){
        solution();
    }
    
}
