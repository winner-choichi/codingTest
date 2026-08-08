class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<pair<bool, int>>> is_visited_grid(grid.size(), vector<pair<bool, int>>(grid[0].size(), {false, 0}));
        
        vector<int> dc = {-1, 1, 0, 0};
        vector<int> dr = {0, 0, -1, 1};

        for(int c=0; c<grid.size(); c++) {
            for(int r=0; r<grid[0].size(); r++) {
                if (grid[c][r] != 2) continue;
                if (is_visited_grid[c][r].first) continue;

                vector<vector<bool>> temp_is_visited_grid(grid.size(), vector<bool>(grid[0].size(), false));

                queue<pair<int, int>> q;
                q.push({c, r});
                temp_is_visited_grid[c][r] = true;
                is_visited_grid[c][r] = {true, 0};

                int minutes = 0;
                while(!q.empty()) {
                    int width = q.size();
                    ++minutes;

                    for (int w=0; w<width; w++) {
                        auto [current_col, current_row] = q.front();
                        q.pop();

                        for (int d=0; d<4; d++) {
                            int col = current_col + dc[d];
                            int row = current_row + dr[d];

                            if (col < 0 || col >= grid.size()) continue;
                            if (row < 0 || row >= grid[0].size()) continue;

                            if (temp_is_visited_grid[col][row]) continue;
                            if (grid[col][row] != 1) continue;

                            q.push({col, row});
                            temp_is_visited_grid[col][row] = true;
                            if (!is_visited_grid[col][row].first) is_visited_grid[col][row] = {true, minutes};
                            else is_visited_grid[col][row] = {true, min(is_visited_grid[col][row].second, minutes)};
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int c=0; c<grid.size(); c++) {
            for (int r=0; r<grid[0].size(); r++) {
                if(grid[c][r] == 1 && !is_visited_grid[c][r].first) return -1;
                ans = max(ans, is_visited_grid[c][r].second);
            }
        }

        return ans;   
    }
};
