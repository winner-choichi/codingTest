#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);

    for (int i=0; i<n; ++i){
        cin >> grid[i];
    }

    vector<vector<bool>> is_visited(n, vector<bool>(n, false));
    vector<int> apartment_complexes;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r=0; r<n; ++r){
        for (int c=0; c<n; ++c) {
            if(grid[r][c]!='0'&&!is_visited[r][c]) {
                queue<pair<int, int>> q;
                is_visited[r][c] = true;
                apartment_complexes.push_back(1);
                q.push({r, c});

                while (!q.empty()) {
                    pair<int, int> now = q.front();
                    q.pop();

                    for (int d=0; d<4; ++d) {
                        int nr = now.first + dr[d];
                        int nc = now.second + dc[d];

                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                        if (is_visited[nr][nc]) continue;

                        if (grid[nr][nc] == '0') continue;

                        is_visited[nr][nc] = true;
                        q.push({nr, nc});
                        ++apartment_complexes.back();
                    }
                }
            }
        }
    }

    sort(apartment_complexes.begin(), apartment_complexes.end());

    cout << apartment_complexes.size() << '\n';

    for (int i: apartment_complexes) {
        cout << i << '\n';
    }

    return 0;
}