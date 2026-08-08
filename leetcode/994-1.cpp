class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        for (int c=0; c<grid.size(); c++){
            for (int r=0; r<grid[0].size(); r++){
                if (grid[c][r] == 2) q.push({c, r});
            }
        }

        // vector<int> dc = {-1, 1, 0, 0};
        // vector<int> dr = {0, 0, -1, 1};
        const int dc[] = {-1, 1, 0, 0};
        const int dr[] = {0, 0, -1, 1};

        int minutes = 0;
        while (!q.empty()) {
            int width = q.size();

            for (int w=0; w<width; w++) {
                auto [col, row] = q.front();
                q.pop();

                for (int d=0; d<4; d++){
                    int c = col + dc[d];
                    int r = row + dr[d];

                    if (c < 0 || c >= grid.size()) continue;
                    if (r < 0 || r >= grid[0].size()) continue;
                    if (grid[c][r] != 1) continue;

                    grid[c][r] = 2;

                    q.push({c, r});
                }
            }
            if(!q.empty()) ++minutes;
        }


        for (int c=0; c<grid.size(); c++){
            for (int r=0; r<grid[0].size(); r++){
                if (grid[c][r] == 1) return -1;
            }
        }

        return minutes;
        
    }
};
