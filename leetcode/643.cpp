class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
	    long long max = accumulate(nums.begin(), nums.begin()+k, 0LL);
	    long long w_sum = max;

	    int l = nums.size();
	    for (int i=1; i<l-k+1; ++i) {
		    w_sum = w_sum - nums[i-1] + nums[i+k-1];
		    if (max < w_sum) max = w_sum;
	    }

	    return (double) max / k;
    }
};

