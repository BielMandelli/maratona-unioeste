#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

bool palindrome(deque<char> s){
    for (int i = 0, j = sz(s)-1; i < j; i++, j--)
        if(s[i] != s[j]) return false;
    return true;
}

void print(deque<char> dq){
    
    cout << endl;
}

void solve(){
    string s;
    cin >> s;

    for (int i = min(sz(s), 55); i > 0; i--)
    {
        map<deque<char>, int> seen;
        deque<char> cur, ans;
        for (int j = 0; j < sz(s); j++)
        {
            cur.push_back(s[j]);
            if(sz(cur) > i) cur.pop_front();
            if(sz(cur) == i && palindrome(cur)){
                int last = seen[cur];
                if(last){
                    if(last <= j){
                        if(!sz(ans)) ans = cur;
                        ans = min(cur, ans);
                    }
                }
                else seen[cur] = j+i;
            }
        } 
        if(sz(ans)) {
            for(int j = 0; j < sz(ans); j++)
                cout << ans[j];        
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}