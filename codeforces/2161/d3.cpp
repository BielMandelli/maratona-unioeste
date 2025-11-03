#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    // A pré-computação continua igual: contamos frequências e posições.
    std::vector<int> count(n + 1, 0);
    std::vector<int> first(n + 1, -1);
    std::vector<int> last(n + 1, -1);

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (count[val] == 0) {
            first[val] = i;
        }
        count[val]++;
        last[val] = i;
    }

    // Pegamos os valores únicos que existem no array.
    std::vector<int> unique_vals;
    for (int i = 1; i <= n; ++i) {
        if (count[i] > 0) {
            unique_vals.push_back(i);
        }
    }

    if (unique_vals.size() <= 1) {
        std::cout << 0 << "\n";
        return;
    }

    // Variáveis que substituem a tabela de DP.
    // Inicializamos com o resultado para o primeiro valor único.
    long long kept_excluding_prev = 0; // Se não pegamos o primeiro valor, temos 0.
    long long kept_including_prev = count[unique_vals[0]]; // Se pegamos, temos sua contagem.

    // Iteramos a partir do segundo valor único.
    for (size_t i = 1; i < unique_vals.size(); ++i) {
        int v_curr = unique_vals[i];
        int v_prev = unique_vals[i-1];

        // 1. Calculamos o máximo mantido EXCLUINDO o valor atual.
        // É simplesmente o melhor resultado que tínhamos do passo anterior.
        long long current_kept_excluding = std::max(kept_excluding_prev, kept_including_prev);

        // 2. Calculamos o máximo mantido INCLUINDO o valor atual.
        long long current_kept_including;
        
        bool conflict = (v_curr == v_prev + 1 && last[v_curr] >= first[v_prev]);

        if (conflict) {
            // Se há conflito, não poderíamos ter incluído o valor anterior.
            current_kept_including = count[v_curr] + kept_excluding_prev;
        } else {
            // Sem conflito, podemos adicionar ao melhor resultado anterior.
            current_kept_including = count[v_curr] + std::max(kept_excluding_prev, kept_including_prev);
        }

        // 3. Atualizamos as variáveis para a próxima iteração.
        kept_excluding_prev = current_kept_excluding;
        kept_including_prev = current_kept_including;
    }

    // O resultado final é o melhor que conseguimos no último passo.
    long long max_kept = std::max(kept_excluding_prev, kept_including_prev);
    std::cout << n - max_kept << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}