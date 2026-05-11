#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> is_visited_dfs, is_visited_bfs;

void dfs(int start) {
    stack<int> s;
    s.push(start);

    while(!s.empty()){
        int now = s.top();
        s.pop();
        if (!is_visited_dfs[now]) cout << now << " ";
        is_visited_dfs[now] = 1;
        for (int next: graph[now]) {
            if(!is_visited_dfs[next]) {
                s.push(next);
            }
        }
    }
}

void bfs(int start) {
    queue<int> q;
    is_visited_bfs[start] = 1;
    q.push(start);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int next: graph[now]) {
            if (!is_visited_bfs[next]){
                is_visited_bfs[next] = 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;
    
    graph.resize(n+1);
    is_visited_bfs.resize(n+1, 0);
    is_visited_dfs.resize(n+1, 0);

    while(m--) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (auto& g: graph) {
        sort(g.begin(), g.end(), [](int a, int b) {
            return a > b;
        });
    }

    dfs(v);
    cout << "\n";

    for (auto& g: graph) {
        sort(g.begin(), g.end(), [](int a, int b) {
            return a < b;
        });
    }
    bfs(v);

    return 0;
}