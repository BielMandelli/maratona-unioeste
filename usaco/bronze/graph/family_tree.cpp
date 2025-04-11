#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

map<string, string> mother;
map<string, vector<string>> adj;
map<string, int> family; 
int family_id = 0;

void dfs(string cow, int id) {
    family[cow] = id;
    for (auto next : adj[cow]) {
        if (!family.count(next))
            dfs(next, id);
    }
}

int level(string child, string ancestor) {
    int gen = 0;
    while (mother.count(child)) {
        child = mother[child];
        gen++;
        if (child == ancestor) return gen;
    }
    return -1;
}

signed main() {
    bieo;
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    for (int i = 0; i < n; i++) {
        string m, c;
        cin >> m >> c;
        mother[c] = m;
        adj[m].push_back(c);
        adj[c].push_back(m); 
    }

    for (auto [cow, _] : adj) {
        if (!family.count(cow)) {
            dfs(cow, family_id++);
        }
    }

    if (family[s1] != family[s2]) {
        cout << "NOT RELATED" << endl;
        return 0;
    }

    if (mother[s1] == mother[s2]) {
        cout << "SIBLINGS" << endl;
        return 0;
    }

    int gen = level(s1, s2);
    if (gen != -1) {
        cout << s2 << " is the ";
        for (int i = 0; i < gen - 2; i++) cout << "great-";
        if (gen >= 2) cout << "grand-";
        cout << "mother of " << s1 << endl;
        return 0;
    }

    gen = level(s2, s1);
    if (gen != -1) {
        cout << s1 << " is the ";
        for (int i = 0; i < gen - 2; i++) cout << "great-";
        if (gen >= 2) cout << "grand-";
        cout << "mother of " << s2 << endl;
        return 0;
    }

    string curr = mother[s1];
    int aunt_level = 0;
    while (!curr.empty()) {
        if (mother[s2] == mother[curr] && s2 != curr) {
            cout << s2 << " is the ";
            for (int i = 0; i < aunt_level; i++) cout << "great-";
            cout << "aunt of " << s1 << endl;
            return 0;
        }
        curr = mother[curr];
        aunt_level++;
    }

    curr = mother[s2];
    aunt_level = 0;
    while (!curr.empty()) {
        if (mother[s1] == mother[curr] && s1 != curr) {
            cout << s1 << " is the ";
            for (int i = 0; i < aunt_level; i++) cout << "great-";
            cout << "aunt of " << s2 << endl;
            return 0;
        }
        curr = mother[curr];
        aunt_level++;
    }

    cout << "COUSINS" << endl;

    return 0;
}
