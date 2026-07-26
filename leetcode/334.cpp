class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        vector<int> vals(len, 2);

        int leftMin = nums[0];
        for (int i=0; i<len; i++) {
            if (leftMin<nums[i]) {
                vals[i]--;
            }
            else if (leftMin > nums[i]) {
                leftMin = nums[i];
            } }

        int rightMax = nums[len-1];
        for (int i=len-1; i>=0; i--) {
            if (rightMax>nums[i]) {
                vals[i]--;
            }
            else if (rightMax < nums[i]) {
                rightMax = nums[i];
            }
        }

        for (const auto& val : vals) {
            if (val <= 0) return true;
        }

        return false;
    }
};
