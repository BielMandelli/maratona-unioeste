#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<int> seq, cur;
bool valid = true, sequence = false;
int x, i = 0;

int query(){
    cin >> x;
    cur.push_back(x);
    if(x != (seq[i%25])){
        cout << "? flip" << endl;
        cin >> x;
    }
    
    return x;
}

void solve()
{
    srand(time(NULL));
    for (int i = 0; i < 25; i++) seq.push_back(rand()%2);

    while (valid)
    {
        query();
        if(cur.size() >= 25){
            for (int j = 0; j < 25; j++)
            {
                if(seq[24 - j] != cur[cur.size() - j - 1]) break;
                if(j == 24) sequence = true;
            }
        }

        if(sequence){
            cout << "! " << cur.size() - seq.size() << endl;
            return;
        }
        
        cout << "? right" << endl;
        i++;
    }
    
}

signed main()
{
    // bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}