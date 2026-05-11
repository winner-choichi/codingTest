#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> is_visited;

void dfs(int now) {
    is_visited[now] = 1;

    for (auto next: graph[now]) {
        if (!is_visited[next]) dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n+1);
    is_visited.resize(n+1, 0);

    while(m--) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);

    int count = 0;
    for (int i: is_visited) {
        count += i;
    }

    cout << count - 1 << '\n';

    return 0;
}