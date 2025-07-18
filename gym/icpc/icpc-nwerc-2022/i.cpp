#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve()
{
    int l,r;
    cin >> l >> r;

    vector<int> pa, pb;
    for (int i = l; i <= r; i++)
    {
        string s;
        cin >> s;
        if(s == "Fizz" or s == "FizzBuzz") pa.push_back(i);
        if(s == "Buzz" or s == "FizzBuzz") pb.push_back(i);
    }
    
    int a,b;
    if(!pa.size()) a = r+1;
    else if(pa.size() == 1) a = pa.back();
    else a = pa[1]-pa[0];

    if(!pb.size()) b = r+2;
    else if(pb.size() == 1) b = pb.back();
    else b = pb[1]-pb[0];

    cout << a << " " << b << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}