#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<int> query(vector<int> const &a){
    cout << "next ";
    for (int i = 0; i < a.size() - 1; i++) cout << a[i] << ' ';
    cout << a.back() << endl;

    int n;
    cin >> n;
    vector<int> g(10);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++) g[s[j]-'0'] = i;
    }
    return g;
}

void solve(){
    query({0,1});
    vector<int> g = query({1});
    while(g[0] != g[1]){
        query({0,1});
        g = query({1});
    }

    while(g[1] != g[2]){
        g = query({0,1,2,3,4,5,6,7,8,9});
    }

    cout << "done" << endl;
}

signed main()
{
    // bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}