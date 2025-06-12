#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, t, b=0;
    cin >> n >> t;
    vector<int> books(n);

    for (auto &x : books) cin >> x;

    int aux = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        for (;j < n && aux + books[j] <= t; j++)
        {
            aux += books[j];
        }
        aux -= books[i];
        b = max(b, j - i);
    }

    cout << b << endl;

    return 0;
}
