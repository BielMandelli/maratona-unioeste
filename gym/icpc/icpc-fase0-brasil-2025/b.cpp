#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 26; 
const int MAXN = 1e5 + 5;

int n;
vector<int> tree[MAXN];
char edgeLabel[MAXN]; 
int pi[MAXN];         
int aut[MAXN][ALPHA]; 
int res = 0;

string path; 

void iteracao_kmp (char ch) {
    s.append(ch);
    int i = st.size() - 1;
    for (int i = 0; i < ALPHA; i++)
        {
            if (i > 0 && c != st[i])
                aut[i][c] = aut[p[i - 1]][c];
            else
                aut[i][c] = i + (c == st[i]);
        }
    }

void dfs(int v) {
    for (int u : tree[v]) {
        iteracao_kmp(u);
        dfs(u);

        path.pop_back(); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> parent(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
        tree[parent[i]].push_back(i);
    }

    string labels;
    cin >> labels;
    for (int i = 2; i <= n; ++i) {
        edgeLabel[i] = labels[i - 2];
    }

    dfs(1); 

    cout << res << '\n';
    return 0;
}
