class Solution {
public:
    int pivotIndex(vector<int>& nums) {
	    int l = nums.size();
	    vector<int> pre_sum(l+1, 0);
	    for (int i=1; i<=l; ++i) {
		    pre_sum[i] = nums[i-1] + pre_sum[i-1];
	    }

	    for (int i=1; i<=l; ++i) {
		    int left = pre_sum[i-1];
		    int right = pre_sum[l] - pre_sum[i];

		    if (left == right) return i-1;
	    }

	    return -1;
    }
};

