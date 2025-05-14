#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    int s,m,h;
    h = n/3600; n%=3600;
    m = n/60; n%=60;
    s = n;

    cout << h << ":" << m << ":" << s << endl;
    
    return 0;
}
