#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int query(string s, int a, int b){
    cout << s << ' ' << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

int sum(int a, int b){
    int andx, orx;
    a++,b++;
    andx = query("and", a, b);
    orx = query("or", a, b);

    int xorx = ~andx & orx;

    return 2*andx+xorx;
}

void solve(){
    int n,k;
    cin >> n >> k;

    int a,b,c;
    a = sum(0,1);
    b = sum(0,2);
    c = sum(1,2);

    vector<int> ans;
    ans.push_back((a+b-c)/2);
    ans.push_back(a-ans[0]);
    ans.push_back(b-ans[0]);

    for (int i = 3; i < n; i++)
    {
        ans.push_back(sum(i-1, i) - ans[i-1]);
    }

    sort(ans.begin(), ans.end());
    cout << "finish " << ans[k-1] << endl;
}

signed main()
{
    // bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}


