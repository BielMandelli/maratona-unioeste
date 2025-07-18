#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void solve(){
    string s;
    getline(cin, s);

    bool print = true;
    for (int i = 0; i < s.size(); i++)
    {
        if(print){
            cout << char(toupper(s[i]));
            print = false;
        }
        else if(s[i] == ' ') print = true;
    }
    cout << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    cin.ignore();
    for (int i=0; i<t; i++) solve();
}