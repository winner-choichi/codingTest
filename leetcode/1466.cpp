class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);

        for(auto& v: connections) {
            int from = v[0];
            int to = v[1];

            graph[from].push_back({to, 1});
            graph[to].push_back({from, 0});
        }

        stack<int> st;
        st.push(0);

        vector<bool> is_visited(n, false);
        is_visited[0] = true;

        int cnt = 0;
        while(!st.empty()) {
            int currentNode = st.top();
            st.pop();

            for (auto& p: graph[currentNode]) {
                if (!is_visited[p.first]) {
                    if (p.second) cnt++;
                    st.push(p.first);
                    is_visited[p.first] = true;
                } else {
                    continue;
                }
            }
        }

        return cnt;
    }
};
