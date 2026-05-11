#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int order = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = order++;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i: graph[now]) {
            if (!visited[i]) {
                visited[i] = order;
                ++order;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    graph.resize(n+1);
    visited.resize(n+1, 0);

    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<graph.size(); ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(r);

    for (int i=1; i<graph.size(); ++i) {
        cout << visited[i] << '\n';
    }

    return 0;
}