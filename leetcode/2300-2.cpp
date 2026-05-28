class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int s_len = spells.size();
        int p_len = potions.size();
        vector<int> res(s_len);

        sort(potions.begin(), potions.end());
        for (int i=0; i<s_len; ++i) {
            int s = spells[i];

            // lower bound style binary search for success boundary b
            int left = 0, right = p_len; // [left, right) answer boundary
            long long potions_bound = (success + s -1) / s;

            while (left < right) {
                int mid = (left + right - 1) / 2;
                if (potions[mid] >= potions_bound) right = mid;
                else left = mid + 1;
            }

            int b = left;

            res[i] = p_len - b;
        }

        return res;
    }
};

