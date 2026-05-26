class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int p_len = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int s: spells) {
            int i=0, f=p_len;

            while (1) {
                int c = (i + f)/2;
                if (1LL * s * potions[c] >= success) {
                    if (c<=0 || (long long)s * potions[c-1] < success) {
                        res.push_back(p_len - c);
                        break;
                    } else {
                        f = c;
                    }
                } else {
                    if (c == p_len-1) {
                        res.push_back(0);
                        break;
                    }
                    i = c;
                }
            }
        }

        return res;
    }
};

