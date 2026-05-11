#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void dfs(pair<int, int> start, vector<vector<int>> &graph, vector<vector<int>> &is_visited) {
    int r = start.first, c = start.second;
    int n = graph.size(), m = graph[0].size();
    is_visited[r][c] = 1;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i=0; i<4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(is_visited[nr][nc] == 1 || graph[nr][nc] == 0) continue;

        dfs({nr, nc}, graph, is_visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> m >> n >> k;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        while (k--) {
            int x, y;
            cin >> x >> y;

            grid[y][x] = 1;
        }

        vector<vector<int>> is_visited(n, vector<int>(m, 0));

        int cnt = 0;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                if (is_visited[r][c]==1 || grid[r][c] == 0) continue; 

                dfs({r, c}, grid, is_visited);
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}