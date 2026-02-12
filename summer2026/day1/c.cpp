#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void solve(){
    string s;
    cin >> s;

    stack<pair<int,int>> st;

    int ans = 0, h = 1, parity = 0;

    int wh = 0, bl = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(st.empty()){
            h = 1;
            parity = 0;
        } 

        if(s[i] == '(') {
            st.push({i, 0});
        } else {
            
            auto [fr,sc] = st.top();
            st.pop();
            int b = i - fr;
            if(parity) bl += b*h;
            else wh += b*h;
            cout << i << " " << b << " " << parity << endl;

            parity = !parity;
            h++;
        }
    }
    
    cout << wh - bl << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
}