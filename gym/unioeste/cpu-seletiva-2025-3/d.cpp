#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

void dfs(int node, int parent, vector<vector<int>> &tree, vector<int> &ans){
    for(auto child : tree[node]){
        if(child != parent){
            ans[child] = ans[node] + 1;
            dfs(child, node, tree, ans);
        }
    }
}

signed main(){
    beeu;
    int t;
    cin >> t;
    while(t--){
        int n, st, en;
        cin >> n >> st >> en;

        vector<vector<int>> tree(n+1);
        vector<int> ans(n+1);

        for(int i = 0; i < n-1; i++){
            int x,y;
            cin >> x >> y;

            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        ans[en] = 0;
        dfs(en, -1, tree, ans);

        vector<int> p(n);
        iota(p.begin(), p.end(), 1);

        sort(p.begin(), p.end(), [&] (int a, int b){
            return ans[a] > ans[b];
        });

        if(ans[st] == -1) cout << -1 << endl;
        else {
            for (int x : p) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
} 
