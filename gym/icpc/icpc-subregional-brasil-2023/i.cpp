#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int n;
vector<vector<int>> d, o;

bool floyd_warshall() {
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0) return 1;

	return 0;
}

int solve(){
    cin >> n;
    d.resize(n, vector<int>(n));
    o.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> o[i][j];
            d[i][j] = o[i][j];
        }

    floyd_warshall();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (o[i][j] != d[i][j]) return -1;
            
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            bool can = false;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j && o[i][j] == o[i][k] + o[k][j]) {
                    can = true;
                    break;
                }
            }
            if (can) ans++;
        }
    
    return ans;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) cout << solve() << endl;
    
    return 0;
}