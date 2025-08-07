#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int lef = 0, righ = 0, totalLeft = 0, totalRight = 0; 
bool cur = 0, ast = 0;

void point(int side){
    if(!side){
        lef++;
    } else righ++;
    // dbg(lef, righ);
    if((lef >= 5 && lef-righ >= 2) or lef == 10) {
        lef = 0;
        righ = 0;
        totalLeft++;
    } else if((righ >= 5 && righ-lef >= 2) or righ == 10) {
        lef = 0;
        righ = 0;
        totalRight++;
    }
}

void print(){
    cout << totalLeft << " (" << lef << (!ast ? "\*" : "") << ") - ";
    cout << totalRight << " (" << righ << (ast ? "\*" : "") << ")" << endl;
}

void solve(){
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size(); i++)
    {
        if(totalLeft == 2 or totalRight == 2){
            if(s[i] != 'Q') continue;
            cout << totalLeft << (totalLeft == 2 ? " (winner)" : "") << " - " << totalRight << (totalRight == 2 ? " (winner)" : "") << endl;
            continue;
        }
        if(s[i] == 'S'){
            point(cur);
        } else if(s[i] == 'R'){
            cur = !cur;
            ast = !ast;
            point(cur);
        } else {
            print();
        }
    }
    
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}