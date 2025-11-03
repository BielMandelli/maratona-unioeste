#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <numeric>

using namespace std;

int n;
vector<string> grid;
vector<vector<int>> component;
vector<vector<bool>> visited_comp;
int dr[] = {-1, 0, 1, 0}; // 0:U, 1:R, 2:D, 3:L
int dc[] = {0, 1, 0, -1};

struct DSU {
    vector<int> parent;
    int num_sets;
    DSU(int k) {
        parent.resize(k + 1);
        iota(parent.begin() + 1, parent.end(), 1);
        num_sets = k;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
            num_sets--;
        }
    }
};

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void find_comp_dfs(int r, int c, int comp_id) {
    if (!is_valid(r, c) || visited_comp[r][c] || grid[r][c] == '.') return;
    visited_comp[r][c] = true;
    component[r][c] = comp_id;
    for (int i = 0; i < 4; ++i) {
        find_comp_dfs(r + dr[i], c + dc[i], comp_id);
    }
}

void solve() {
    cin >> n;
    grid.assign(n, string(n, '.'));
    vector<pair<int, int>> black_cells;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '#') {
                black_cells.push_back({i, j});
            }
        }
    }

    if (black_cells.empty()) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '#') {
                if (j + 2 < n && grid[i][j + 1] == '#' && grid[i][j + 2] == '#') {
                    cout << "NO" << endl; return;
                }
                if (i + 2 < n && grid[i + 1][j] == '#' && grid[i + 2][j] == '#') {
                    cout << "NO" << endl; return;
                }
            }
        }
    }

    component.assign(n, vector<int>(n, 0));
    visited_comp.assign(n, vector<bool>(n, false));
    int comp_count = 0;
    for (const auto& cell : black_cells) {
        if (!visited_comp[cell.first][cell.second]) {
            comp_count++;
            find_comp_dfs(cell.first, cell.second, comp_count);
        }
    }

    if (comp_count == 1) {
        cout << "YES" << endl;
        return;
    }

    DSU dsu(comp_count);
    
    // visited[r][c][dir][steps] stores component ID
    vector<vector<vector<vector<int>>>> visited(n, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(3, 0))));
    queue<tuple<int, int, int, int>> q;

    for (const auto& cell : black_cells) {
        int r = cell.first;
        int c = cell.second;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (is_valid(nr, nc) && grid[nr][nc] == '.') {
                if (visited[nr][nc][i][1] == 0) {
                    visited[nr][nc][i][1] = component[r][c];
                    q.push({nr, nc, i, 1});
                }
            }
        }
    }

    while (!q.empty()) {
        auto [r, c, dir, steps] = q.front();
        q.pop();
        int current_comp_id = visited[r][c][dir][steps];

        for (int i = 0; i < 4; ++i) { // new_dir = i
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!is_valid(nr, nc)) continue;

            // Case 1: Connecting to an existing black cell
            if (grid[nr][nc] == '#') {
                if (i != dir) { // Valid connection ONLY if it's a turn
                    dsu.unite(current_comp_id, component[nr][nc]);
                }
                continue;
            }

            // Case 2: Continuing path through a white cell
            int new_steps = (i == dir) ? steps + 1 : 1;
            if (new_steps >= 3) continue;

            // Check for meetings with other paths AT (nr, nc)
            for (int prev_dir = 0; prev_dir < 4; ++prev_dir) {
                for (int prev_steps = 1; prev_steps < 3; ++prev_steps) {
                    int other_comp_id = visited[nr][nc][prev_dir][prev_steps];
                    if (other_comp_id != 0 && dsu.find(other_comp_id) != dsu.find(current_comp_id)) {
                        bool is_opposite = (i == (prev_dir + 2) % 4);
                        if (!is_opposite) { // Valid connection ONLY if it's a corner
                            dsu.unite(current_comp_id, other_comp_id);
                        }
                    }
                }
            }

            if (visited[nr][nc][i][new_steps] == 0) {
                visited[nr][nc][i][new_steps] = current_comp_id;
                q.push({nr, nc, i, new_steps});
            }
        }
    }

    if (dsu.num_sets == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}