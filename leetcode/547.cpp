class Solution {
public:
    struct Node {
        int val;
        int prov;
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        stack<Node> s;
        int len = isConnected.size();
        vector<bool> is_visited(len, false);
        int num_prov = 0;

        for (int n=0; n<len; ++n) {
            if (is_visited[n]) continue;
            num_prov++;
            int c_prov = num_prov;

            s.push(Node(n, c_prov));
            is_visited[n] = true;

            while (!s.empty()) {
                Node c_node = s.top();
                s.pop();

                for (int m=0; m<len; ++m) {
                    if (is_visited[m]) continue;
                    if (!isConnected[c_node.val][m]) continue;

                    s.push(Node(m, c_prov));
                    is_visited[m] = true;
                }
            }
        }

        return num_prov;
    }
};

