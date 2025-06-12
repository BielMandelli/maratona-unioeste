#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main()
{
    bieo;
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) cout << c;
        else if (a == c) cout << b;
        else cout << a;

        cout << endl;
    }

    return 0;
}
