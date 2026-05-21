#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

#define int long long

void solve(){
    string s;
    cin >> s;

    stack<pair<int,int>> st;

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') {
            st.push({i, 0});
            cnt++;
        } else {
            int maxh = 0;

            while(st.top().second > 0){
                maxh = max(maxh, st.top().second);
                st.pop();
            }
            st.top().second += maxh+1;

            ans += (i-st.top().first) * st.top().second * (cnt%2 ? 1 : -1);
            cnt--;
        }
    }
    
    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
}