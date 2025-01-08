#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
 
vector<int> subordinates(2e5, 0);
vector<vector<int>> hierarchy(2e5);
 
void dfs(int node) {
    for (auto child: hierarchy[node]) {
        dfs(child);
        subordinates[node] += subordinates[child] + 1;
    }
}
 
 
signed main() {
    cin >> n;
 
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
 
        hierarchy[x].push_back(i);
    }
 
    dfs(1);
 
    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    cout << endl;
}