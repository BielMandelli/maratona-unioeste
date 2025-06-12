#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)a.size())

struct hero {
    int power, cost, desc;
};

hero constr(int p, int c, int desc) {
    hero h;
    h.cost = c;
    h.desc = desc;
    h.power = p;
    return h;
}

map<string, hero> mh;

void init(){
    mh["Shadow"] = (constr(6,4,0));
    mh["Gale"] = (constr(5,3,0));
    mh["Ranger"] = (constr(4,2,0));
    mh["Anvil"] = (constr(7,5,0));
    mh["Vexia"] = (constr(3,2,0));
    mh["Guardian"] = (constr(8,6,0));
    mh["Thunderheart"] = (constr(6,5,1));
    mh["Frostwhisper"] = (constr(2,1,0));
    mh["Voidclaw"] = (constr(3,1,0));
    mh["Ironwood"] = (constr(3,1,0));
    mh["Zenith"] = (constr(4,6,2));
    mh["Seraphina"] = (constr(1,1,3));
}

int abi(int hb, int n, int loc){
    if(hb==1) if(n == 4) return 6;
    if(hb==2) if(loc == 1) return 5;
    if(hb==3) return n-1;
    return 0;
}

void solve(){
    init();
    
    int fp1 = 0, fp2 = 0, tp1 = 0, tp2 = 0;
    for (int i = 0; i < 3; i++)
    {
        int p1 = 0, p2 = 0;
        for (int j = 0; j < 2; j++)
        {
            int n;
            cin >> n;
            for (int k = 0; k < n; k++)
            {
                string s;
                cin >> s;
                if(!(j%2)) {
                    if(mh[s].desc > 0) p1 += abi(mh[s].desc, n, i);
                    p1 += mh[s].power;
                }
                else {
                    if(mh[s].desc > 0) p2 += abi(mh[s].desc, n, i);
                    p2 += mh[s].power;
                }
            }
        }
        // cout << "loc" << i+1 << " p1 " << p1 << " p2 " << p2 << endl;
        tp1 += p1; tp2 += p2;
        if(p1 > p2) fp1++;
        else if(p1 < p2) fp2++;
    }
    
    if(fp1 == fp2) {
        if(tp1 > tp2) fp1++;
        else if(tp1 < tp2) fp2++;
    }

    cout << ((fp2<fp1) ? "Player 1" : (fp2>fp1) ? "Player 2" : "Tie") << endl;
}

signed main(){
    fastio;
    int t=1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}