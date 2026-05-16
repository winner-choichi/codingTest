class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        
        int cnt_zeros=0, pos_a_zero=-1;
        long long int mul=1;
        for (int i=0; i<len; ++i) {
            if (nums[i]==0) {
                cnt_zeros++;
                pos_a_zero = i;
                continue;
            }

            mul *= nums[i];
            // cout << mul << '\n';
        }

        vector<int> res(len, 0);
        if (cnt_zeros>=2) {
            return res;
        }
        else if (cnt_zeros==1){
            res[pos_a_zero] = mul;
            return res;
        } else {
            for (int i=0; i<len; ++i) {
                res[i] = mul / nums[i];
            }
            return res;
        }
    }
};

