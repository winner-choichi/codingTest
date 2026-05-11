#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> is_visited;
int order = 1;

void bfs(int start){
    queue<int> q;
    q.push(start);
    is_visited[start] = order++;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next: graph[now]) {
            if (!is_visited[next]){
                q.push(next);
                is_visited[next] = order++;
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
    is_visited.resize(n+1, 0);

    while(m--) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<=n; ++i) {
        sort(graph[i].begin(), graph[i].end(), [](int a, int b) {
            return a>b;
        });
    }

    bfs(r);

    for (int i=1; i<=n; ++i) {
        cout << is_visited[i] << '\n';
    }

    return 0;
}