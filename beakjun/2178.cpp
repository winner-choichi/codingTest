#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int r=0; r<n; ++r) {
        cin >> grid[r];
    }

    vector<vector<int>> is_visited(n, vector<int>(m, 0 ));
    queue<pair<int, int>> q;
    is_visited[0][0] = 1;
    q.push({0, 0});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        // cout << r << " " << c << '\n';

        int current_depth = is_visited[r][c];
        for (int d=0; d<4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            if (grid[nr][nc] == '0' || is_visited[nr][nc] != 0) continue;

            is_visited[nr][nc] = current_depth + 1;
            q.push({nr, nc});

            if (nr == n - 1 && nc == m - 1) {
                cout << is_visited[n - 1][m - 1] << '\n';
                return 0;
            }
        }

    }
}