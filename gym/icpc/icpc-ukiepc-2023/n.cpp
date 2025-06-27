#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)

string gen(int id) {
    string name;
    while (true) {
        name += 'a' + (id % 26);
        id /= 26;
        if (id <= 0) break;
        id--;
    }
    reverse(name.begin(), name.end());
    return name;
}

void solve() {
    int n;
    cin >> n;

    map<string, string> mp;
    int id = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s.pop_back(); 

        if (s.find('.') != string::npos) {
            while (s.back() == '0') s.pop_back();
            if (s.back() == '.') s.pop_back();
        }

        if (!mp.count(s)) mp[s] = gen(id);

        id++;
        cout << mp[s] << endl;
    }
}

int main() {
    bieo;
    solve();
    return 0;
}
