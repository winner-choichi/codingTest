#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<vector<int>> graph;
vector<pair<bool, int>> visited;
int order = 1;

void dfs(int now) {
    visited[now] = {true, order};
    ++order;

    for (auto next: graph[now]) {
        if(!visited[next].first) dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    graph.resize(n+1);
    visited.resize(n+1, {false, 0});

    while(m--) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<=n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(r);

    bool flag = 1;
    for (const auto& [n_visited, n_order]: visited) {
        if (flag) {
            flag = 0;
            continue;
        }
        cout << n_order << "\n";
    }

    return 0;
}