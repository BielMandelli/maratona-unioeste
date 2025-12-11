#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MX = 100;
    static int sg[MX+1][MX+1];

    for (int i = 0; i <= MX; i++){
        for (int j = 0; j <= MX; j++){
            if (i == 0 && j == 0){
                sg[i][j] = 0;
                continue;
            }

            vector<int> seen;

            for (int u = 1; u <= i; u++) seen.push_back(sg[i - u][j]);

            for (int u = 1; u <= j; u++) seen.push_back(sg[i][j - u]);

            int mn = min(i, j);
            for (int u = 1; u <= mn; u++)
                seen.push_back(sg[i - u][j - u]);

            sort(seen.begin(), seen.end());
            seen.erase(unique(seen.begin(), seen.end()), seen.end());

            int g = 0;
            while (binary_search(seen.begin(), seen.end(), g)) g++;
            sg[i][j] = g;
        }
    }

    int n;
    cin >> n;
    int xr = 0;

    while (n--) {
        int l, c;
        cin >> l >> c;
        xr ^= sg[l][c];
    }

    cout << (xr ? 'Y' : 'N') << "\n";
}
