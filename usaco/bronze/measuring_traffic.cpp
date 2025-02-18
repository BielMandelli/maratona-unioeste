#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n;
    cin >> n;

    vector<string> status(n);
    vector<int> minorus(n);
    vector<int> maximus(n);

    for (int i = 0; i < n; i++) cin >> status[i] >> minorus[i] >> maximus[i];
    
    int low = 0, high = INT16_MAX;
    for (int i = n-1; i >= 0; i--)
    {
        if(status[i] == "none"){
            low = max(low, minorus[i]);
            high = min(high, maximus[i]);
        }
        else if(status[i] == "off"){
            low += minorus[i];
            high += maximus[i];
        }
        else if(status[i] == "on"){
            low -= maximus[i];
            high -= minorus[i];
            low = max(0LL, low);
        }
    }

    cout << low << " " << high << endl;

    low = 0, high = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if(status[i] == "none"){
            low = max(low, minorus[i]);
            high = min(high, maximus[i]);
        }
        else if(status[i] == "off"){
            low -= maximus[i];
            high -= minorus[i];
            low = max(0LL, low);
        }
        else if(status[i] == "on"){
            low += minorus[i];
            high += maximus[i];
        }
    }
    
    cout << low << " " << high << endl;

    return 0;
}