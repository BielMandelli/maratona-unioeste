#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

	int p1,p2,c1,c2;
    cin >> p1 >> c1 >> p2 >> c2;

    int x = p1*c1, y = p2*c2;
    cout << (x == y ? 0 : x > y ? -1 : 1) << endl;
}
