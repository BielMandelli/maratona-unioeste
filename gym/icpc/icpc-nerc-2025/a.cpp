#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MAXX = 2e5+123;
bitset<MAXX> sum, sumAtt, ans;

void solution(){
    int n;
    cin >> n;

    int last = -1;

    vector<int> val(n), att;
    vector<string> op(n), type(n);

    for (int i=0; i<n; i++){
        cin >> op[i] >> val[i] >> type[i];

        if(op[i] == "=") {
            last = i;
            if(type[i] == "async") att.push_back(val[i]);
        }
    }

    if(last == -1){
        cout << "1" << endl;
        return;
    }

    sort(all(att));
    att.erase(unique(all(att)), att.end());

    sum[0] = 1;
    int need = 0;

    for(int i = last+1; i < n; i++){
        need += val[i];
    }

    for(int i = 0; i <= last; i++){
        if(op[i] == "+" && type[i] == "async") sum |= (sum << val[i]);
    }

    for(int v : att){
        sumAtt |= (sum << v);
    }

    ans |= (sum << (val[last] + need));
    ans |= (sumAtt << need);

    for(int i = last + 1; i < n; i++){
        if(type[i] == "async"){
            sum |= (sum << val[i]);
            sumAtt |= (sumAtt << val[i]);
        }

        need -= val[i];
        ans |= (sumAtt << need);
    }

    cout << ans.count() << endl;
}

signed main(){
    fastio;
    int cases=1;
    //cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }

}