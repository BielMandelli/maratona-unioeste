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

#define int long long

int getMult(int x){
    if(x <= 9) return 1;
    else if(x <= 19) return 2;
    else if(x <= 29) return 3;
    else if(x <= 39) return 4;
    else return 5;
}

void solution(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> pts(n, 0);

    int seq = 0, base = 0, unlock = -1;

    for(int i = 0; i < n; i++){
        if(s[i] == 'X'){
            seq = 0;
        }
        else if(s[i] == 'H'){
            seq++;
            pts[i] = getMult(seq);
            if(seq == 15 && unlock == -1) unlock = i + 1; 
        }
    }


    for(int x : pts) base += x;

    if(unlock == -1){ 
        cout << base << endl;
        return;
    }

    int mx = 0, cur = 0, cnt = 0;
    int l = unlock, r = unlock;

    while(r < n){
        cur += pts[r];
        r++;
        cnt++;
        
        mx = max(mx, cur);
        if(cnt == k){
            cnt--;
            cur -= pts[l];
            l++;
        }
    }
    

    cout << base + mx << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
