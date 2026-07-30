class Solution {
public:
    int count_num_pairs(vector<int>& nums, int k, int sp, int lp) {
        if (sp >= lp) return 0;
        long long sum = nums[sp] + nums[lp];
        if (sum == k) return count_num_pairs(nums, k, sp+1, lp-1) + 1;
        else if (sum > k) return count_num_pairs(nums, k, sp, lp-1);
        else return count_num_pairs(nums, k, sp+1, lp);
    }
    int maxOperations(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return count_num_pairs(nums, k, 0, len-1);
    }
};

