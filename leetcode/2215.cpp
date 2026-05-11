class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	    set<int> set_nums1(nums1.begin(), nums1.end());
	    set<int> set_nums2(nums2.begin(), nums2.end());

	    vector<int> nums1_only;
	    for (auto i: set_nums1) {
		    if (!set_nums2.count(i)) nums1_only.push_back(i);
	    }

	    vector<int> nums2_only;
	    for (auto i: set_nums2) {
		    if (!set_nums1.count(i)) nums2_only.push_back(i);
	    }

	    return {nums1_only, nums2_only};
        
    }
};

