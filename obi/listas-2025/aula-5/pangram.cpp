#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26);
    for (int i = 0; i < n; i++)
    {
        char c = tolower(s[i]);
        cnt[c-'a']++;
    }
    
    bool valido = true;
    for (int i = 0; i < 26; i++)
    {
        if(cnt[i] == 0) {
            valido = false;
            break;
        }
    }
    
    cout << (valido ? "YES" : "NO") << endl;

    return 0;
}