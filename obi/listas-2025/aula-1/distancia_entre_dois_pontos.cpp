#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    double x1,y1,x2,y2;
    
    cin >> x1 >> y1 >> x2 >> y2;

    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    cout << setprecision(4) << fixed;
    cout << dist << endl;

    return 0;
}
