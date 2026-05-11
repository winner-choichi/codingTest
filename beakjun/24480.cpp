#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int order = 1;

void dfs(int now) {
    visited[now] = order;
    ++order;

    for (int i: graph[now]) {
        if (!visited[i]) dfs(i);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    graph.resize(n+1);
    visited.resize(n+1, false);
    
    while (m--) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (auto& i: graph) {
        sort(i.begin(), i.end(), [](const int a, const int b) {
            return a > b;
        });
    }

    dfs(r);

    for (int i=1; i<visited.size(); ++i) {
        cout << visited[i] << '\n';
    }
    
    return 0;
}