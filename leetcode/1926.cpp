class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> is_visited(maze.size(), vector<bool>(maze[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        is_visited[entrance[0]][entrance[1]] = true;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int last_r = maze.size() - 1, last_c = maze[0].size() - 1;

        bool is_entrance = true;
        while (!q.empty()) {
            auto [current_pos, current_d] = q.front();
            q.pop();

            int r = current_pos.first, c = current_pos.second;

            if (!is_entrance && (r == 0 || r == last_r)) return current_d;
            if (!is_entrance && (c == 0 || c == last_c)) return current_d;

            for (int d=0; d<4; ++d) {
                int nr = r + dy[d], nc = c + dx[d];
                if (nr<0 || nr>last_r || nc<0 || nc>last_c) continue;
                if (maze[nr][nc]!='+' && !is_visited[nr][nc]){
                    q.push({{nr, nc}, current_d+1});
                    is_visited[nr][nc] = true;
                }
            }

            if (is_entrance) is_entrance = false;
        }

        return -1;
        
    }
};

