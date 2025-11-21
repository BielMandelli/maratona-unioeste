#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl;}
template<typename H, typename ...T>
void dbg_out(string s, H h, T... t){
    do{cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void banana(vector<vector<char>> a){
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "--------------------" << endl;
}

int compareMat (vector<vector<char>> &a, vector<vector<char>> &b, int type){
    bool invc = false, invr = false;
    if (type == 1) invc = true;
    else if (type == 2) invr = true;
    else {
        invr = true;
        invc = true;
    }

    int diff = 0;
    for (int i = 0, i2; i < a.size(); i++)
    {
        if(invr) i2 = a.size()-i-1;
        else i2 = i;
        for (int j = 0, j2; j < a.size(); j++)
        {
            if(invc) j2 = a.size()-j-1;
            else j2 = j;

            if(a[i][j] != b[i2][j2]) diff++;
        }
    }

    return diff;
}

char alter(char cur){
    return (cur == '.' ? '#' : '.');
}

void solution(){
    int n, u;
    cin >> n >> u;

    int q = n/2;
    vector<vector<char>> m(n, vector<char>(n)), 
    a(q, vector<char>(q)), 
    b(q, vector<char>(q)), 
    c(q, vector<char>(q)), 
    d(q, vector<char>(q));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if(i < q){
                if(j < q) a[i%q][j%q] = m[i][j];
                else b[i%q][j%q] = m[i][j];
            } else {
                if(j < q) c[i%q][j%q] = m[i][j];
                else d[i%q][j%q] = m[i][j];
            }
        }
    }
    
    
    // banana(b);
    // banana(c);
    
    cout << compareMat(a, b, 1) + compareMat(a, c, 2) + compareMat(a, d, 3) << endl;
    while(u--){
        int r,cl;
        cin >> r >> cl;
        r--; cl--;
        m[r][cl] = alter(m[r][cl]);
        if(r < q){
            if(cl < q) a[r%q][cl%q] = m[r][cl];
            else b[r%q][cl%q] = m[r][cl];
        } else {
            if(cl < q) c[r%q][cl%q] = m[r][cl];
            else d[r%q][cl%q] = m[r][cl];
        }

        int ans = 0;
        // banana(a);
        // banana(d);
        ans = compareMat(a, b, 1) + compareMat(a, c, 2) + compareMat(a, d, 3);
        cout << ans << endl;
    }
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
