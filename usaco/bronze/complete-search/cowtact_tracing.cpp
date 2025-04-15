#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;
int n, T;
vector<bool> cowsinf;

struct Shake
{
    int t,x,y;
    bool operator<(const Shake &tmp) { return t < tmp.t; }
};

vector<Shake> shakes;

bool consistent(int patient, int k){
    vector<bool> tmpinf(n);
    vector<int> nshakes(n);
    tmpinf[patient] = true;

    for(Shake sh : shakes) {
        if(tmpinf[sh.x]) { nshakes[sh.x]++;}
        if(tmpinf[sh.y]) { nshakes[sh.y]++;}
        if(nshakes[sh.x] <= k && tmpinf[sh.x]) { tmpinf[sh.y] = true;}
        if(nshakes[sh.y] <= k && tmpinf[sh.y]) { tmpinf[sh.x] = true;}
    }
    for (int i = 0; i < n; i++) if(tmpinf[i] != cowsinf[i]) return false;
    return true;
}

signed main()
{
    fastio;

    string s;
    cin >> n >> T >> s;
    
    shakes.resize(T);
    cowsinf.resize(n);
   
    unordered_set<int> pacient;

    int minK = T, maxK = -1;
    
    for (int i = 0; i < n; i++) cowsinf[i] = (s[i] == '1');
    
    for(Shake &sh : shakes) {
        cin >> sh.t >> sh.x >> sh.y;
        sh.t--, sh.x--, sh.y--;
    }

    sort(shakes.begin(), shakes.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            if(consistent(i, j)){
                pacient.insert(i);
                minK = min(minK, j);
                maxK = max(maxK, j);
            }
        }
    }
    
    cout << pacient.size() << " " << minK << " " << (maxK == T ? "Infinity" : to_string(maxK)) << endl;

    return 0;
}