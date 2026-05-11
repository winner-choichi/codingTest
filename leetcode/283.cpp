class Solution {
public:
    void moveZeroes(vector<int>& nums) {
	    int length = nums.size();
	    int *p1 = &nums[0], *p2 = &nums[0];

	    while(1) {
		while(*p1 != 0) {
			if (p1 == &nums[length -1]) return;
			p1 += 1;
		}
		p2 = p1;
		while(*p2 == 0) {
			if (p2 == &nums[length -1]) return;
			p2 += 1;
		}

		int tmp = *p2;
		*p2 = *p1;
		*p1 = tmp;
		p1 += 1;
	    }
    }
};
