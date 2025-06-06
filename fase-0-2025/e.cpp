#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
vector<int> divs;

void precalc(int y){
    for (int i = 1; i*i <= y; i++)
    {
        if(!(y%i)) {
            divs.push_back(i);
            if(y/i != i) divs.push_back(y/i);
        }
    }
}

signed main() {
    bieo;

    int x = 1, y, k;
    cin >> y >> k;
    precalc(y);
    
    sort(divs.begin(), divs.end());

    int i = 0;
    // cout << "x " << x << " k " << k << endl;
    while (k && i < divs.size()-1)
    {
        int inxt = i+1;
        while(inxt < divs.size()){
            if(divs[inxt] % divs[i] == 0) break;
            inxt++;
        }
        
        int prox = divs[inxt];
        int dist = (prox - x)/divs[i];
        k -= min(dist, k);
        x += dist * divs[i];

        // cout << "x " << x << " k " << k << " dist " << dist << endl;
        i = inxt;
    }
    
    if(k) x += y*k;
    // cout << "x " << x << " k " << k << endl;
    
    cout << x << endl;
        
    return 0;
}
