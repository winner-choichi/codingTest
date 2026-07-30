class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int sp = 0, lp = len-1, cnt = 0;
        while (sp < lp) {
            int sum = nums[sp] + nums[lp];
            if (sum == k) {
                cnt++;
                sp++;
                lp--;
            }
            else if (sum > k) lp--;
            else sp++;
        }

        return cnt;
    }
};
