#include <bits/stdc++.h>
#define int long long
using namespace std;
int rows, cols;

int processLayer(vector<vector<char>>& grid, int layer) {
    char sequence[4] = {'X', 'X', 'X', 'X'};
    int x = layer, y = layer;
    int perimeter = 2 * (rows + cols) - (8 * layer) - 1;
    int count = 0;
    int direction = 0;

    while (perimeter--) {
        sequence[0] = sequence[1];
        sequence[1] = sequence[2];
        sequence[2] = sequence[3];
        sequence[3] = grid[x][y];

        count += (sequence[0] == '1' && sequence[1] == '5' && sequence[2] == '4' && sequence[3] == '3') ? 1 : 0;

        if (direction == 0) {
            if (y < cols - layer - 1) {
                y++;
            } else {
                direction = 1;
            }
        }
        if (direction == 1) {
            if (x < rows - layer - 1) {
                x++;
            } else {
                direction = 2;
            }
        }
        if (direction == 2) {
            if (y > layer) {
                y--;
            } else {
                direction = 3;
            }
        }
        if (direction == 3) {
            if (x > layer) {
                x--;
            } else {
                y++;
                direction = 0;
            }
        }
    }

    return count;
}

void findPatterns() {
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int layers = min(rows, cols) / 2;
    int totalMatches = 0;

    for (int layer = 0; layer < layers; layer++) {
        totalMatches += processLayer(grid, layer);
    }

    cout << totalMatches << endl;
}

signed main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        findPatterns();
    }
}
