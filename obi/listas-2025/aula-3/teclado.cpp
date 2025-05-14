#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<vector<char>> telefone = {
        {}, {}, 
        {'a', 'b', 'c'}, 
        {'d', 'e', 'f'}, 
        {'g', 'h', 'i'}, 
        {'j', 'k', 'l'}, 
        {'m', 'n', 'o'}, 
        {'p', 'q', 'r', 's'}, 
        {'t', 'u', 'v'}, 
        {'w', 'x', 'y', 'z'}
    };

    int ans = 0;
    while (n--) {
        string s2;
        cin >> s2;

        if (s2.size() != s.size()) continue;

        bool valid = true;
        for (int i = 0; i < s.size(); i++) {
            char letra = s2[i];
            int digito = s[i] - '0';

            if (find(telefone[digito].begin(), telefone[digito].end(), letra) == telefone[digito].end()) {
                valid = false;
                break;
            }
        }

        if (valid) ans++;
    }

    cout << ans << endl;
    return 0;
}
