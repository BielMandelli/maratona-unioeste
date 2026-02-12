#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

int allc(vector<int> atk, vector<int> def, vector<int> cards){

    int dmg = 0;

    bool can = true;
    int cnt = 0;
    for (int i = 0; i < sz(def); i++)
    {
        for (int j = 0; j < sz(cards); j++)
        {
            if(def[i] < cards[j]) {
                cards[j] = -1;
                cnt++;
                break;
            }
        }
    }

    for (int i = 0; i < sz(atk); i++)
    {
        for (int j = 0; j < sz(cards); j++)
        {
            // cout << atk[i] << " " << cards[j] << endl;
            if(atk[i] <= cards[j]) {
                dmg += abs(atk[i]-cards[j]);
                cards[j] = -1;
                cnt++;
                break;
            }
        }
    }

    if(cnt == sz(atk) + sz(def)) for(auto &x : cards) if(x > 0) dmg+= x;

    // cout << dmg << endl;
    return dmg;
}

int atkc(vector<int> atk, vector<int> cards){
    int dmg = 0;
    for (int i = 0; i < sz(atk); i++)
    {
        for (int j = sz(cards)-1; j >= 0; j--)
        {
            if(atk[i] <= cards[j]) {
                dmg += abs(atk[i]-cards[j]);
                cards[j] = -1;
                break;
            }
        }
    }
    // cout << dmg << endl;
    return dmg;
}

void solve(){
    int n,m;
    cin >> n >> m;

    vector<int> atk, def, cards(m);
    for (int i = 0; i < n; i++)
    {
        string s;
        int v;
        cin >> s >> v;

        if(s == "ATK") atk.push_back(v);
        else def.push_back(v);
    }
    
    for(auto &x : cards) cin >> x;

    sort(all(cards));
    sort(all(atk));
    sort(all(def));

    int ans = 0;
    if(m >= n) ans = allc(atk, def, cards);
    ans = max(ans, atkc(atk, cards));

    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}