#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

vector<int> comp = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int conv(int n){
    string s = to_string(n);
    if(s.size() == 1) s = "0" + s;
    string ans = "";

    for (int i = 1; i >= 0; i--)
    {
        if(comp[s[i] - '0'] == -1) return 1e9;
        ans += char(comp[s[i] - '0'] + '0');
    }
    
    return stoll(ans);
}

signed main() {
    bieo;
    int t;
    cin >> t;

    while(t--){
        int h, m, H, M;
        string s;
        cin >> h >> m >> s;
        
        H = (s[0] - '0') * 10 + s[1] - '0';
        M = (s[3] - '0') * 10 + s[4] - '0';
        
        bool valid = false;
        while (!valid)
        {
            if(M == m){
                H++, M = 0;
            }

            if(H == h) H = 0;
            
            if(conv(M) < h && conv(H) < m){
                valid = true;
                break;
            }
            M++;
        }
        
        string ansH = to_string(H), ansM = to_string(M);
        
        if(H < 10) ansH = "0" + ansH;
        if(M < 10) ansM = "0" + ansM;

        cout << ansH << ":" << ansM << endl;
    }

    return 0;
}
