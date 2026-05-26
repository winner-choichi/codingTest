class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int len = grid.size();
        map<vector<int>, int> r_seq, c_seq;
        for (vector<int>& r: grid) {
            r_seq[r] ++;
        }

        for (int c=0; c<len; ++c) {
            vector<int> col(len);
            for (int r=0; r<len; ++r) {
                col[r] = grid[r][c];
            }
            c_seq[col] ++;
        }

        int res = 0;
        for (auto& [r, r_cnt]: r_seq) {
            int c_cnt = c_seq[r];
            res += c_cnt * r_cnt;
        }

        return res;
    }
};

