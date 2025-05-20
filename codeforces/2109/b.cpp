    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define bieo cin.tie(0)->sync_with_stdio(0)
    #define endl '\n'

    int fastexp(int x) {
        if (x <= 1) return 0;

        int cur = 1;
        int exp = 0;

        while (cur < x) {
            cur *= 2; 
            exp++;
        }

        return exp;
    }

    int main() {
        bieo;

        int t;
        cin >> t;
        
        while (t--) {
            int n, m, a, b;
            cin >> n >> m >> a >> b;

            int distT, distB, distL, distR, startH, startV;

            distT = a;
            distB = n-a+1;
            distL = b;
            distR = m-b+1;

            startV = fastexp(m) + fastexp(min(distT, distB));
            startH = fastexp(n) + fastexp(min(distL, distR));

            cout << min(startV, startH) + 1 << endl;
        }

        return 0;
    }
