class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int s_len = spells.size();
        int p_len = potions.size();
        vector<int> res(s_len);

        sort(potions.begin(), potions.end());
        for (int i=0; i<s_len; ++i) {
            int s = spells[i];

            // binary search for success boundary b
            // long long potions_bound = ceil(success / s);
            long long potions_bound = (success + s -1) / s;
            auto b_iter = lower_bound(potions.begin(), potions.end(), potions_bound);

            int b = b_iter - potions.begin();

            res[i] = p_len - b;
        }

        return res;
    }
};

