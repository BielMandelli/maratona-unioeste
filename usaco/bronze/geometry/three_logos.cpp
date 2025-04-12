#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    vector<int> x(3),y(3);
    vector<char> c = {'A', 'B', 'C'};
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

    int s = x[0]*y[0] + x[1]*y[1] + x[2]*y[2];
    int sq = sqrt(s);

    if(sq*sq != s) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < 3; i++)
    {
        if(x[i] > sq or y[i] > sq){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> v;
    for(int i = 0; i < 3; i++)
    {
        if(y[i] == sq) swap(x[i],y[i]);
        if(x[i] == sq) v.push_back(i);
    }

    if(v.size() == 3)
    {
        cout << sq << endl;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < y[i]; j++)
            {
                for(int k = 0; k < sq; k++) cout << c[i];
                cout << endl;
            }
        }
        return 0;
    }

    if(v.size() == 1)
    {
        int cur = y[v[0]];
        int le = sq - cur;
        int co = 0;
        for(int i = 0; i < 3;i++)
        {
            if(i != v[0])
            {
                if(y[i] == le) swap(x[i] , y[i]);
                if(x[i] == le) co++;
            }
        }

        if(co == 2)
        {
            cout << sq << endl;
            for(int i = 0; i < cur; i++)
            {
                for(int j = 0; j < sq; j++) cout << c[v[0]];
                cout << endl;
            }
            int o1 = (v[0] + 1) % 3;
            int o2 = (o1 + 1) % 3;
            for(int i = 0; i < le; i++)
            {
                for(int j = 0; j < y[o1]; j++) cout << c[o1];
                for(int j = 0; j < y[o2]; j++) cout << c[o2];
                cout << endl;
            }
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}