#include <bits/stdc++.h>
using namespace std;

void flush_and_read(string& response) {
    cout.flush();
    cin >> response;
    if (response == "-1") exit(0);  // erro fatal
}

void solve_case(int n) {
    string res;

    // Etapa 1: usar "digit" 4 vezes para reduzir x
    for (int i = 0; i < 4; ++i) {
        cout << "digit" << endl;
        flush_and_read(res);
    }

    // Agora x <= 81. Testamos todos os possíveis valores
    for (int s = 1; s <= 81; ++s) {
        if (n % s == 0) {
            int mul = n / s;
            // Tentamos ir de s para n com 3 comandos:
            // 1. add (s - 1) para tornar x = s
            cout << "add " << s - 1 << endl;
            flush_and_read(res);
            // 2. div s
            cout << "div " << s << endl;
            flush_and_read(res);
            // 3. mul (n / s)
            cout << "mul " << mul << endl;
            flush_and_read(res);
            break;
        }
    }

    // Verificar se conseguimos fazer x == n
    cout << "!" << endl;
    flush_and_read(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve_case(n);
    }
    return 0;
}

