class Solution {
public:
    int largestAltitude(vector<int>& gain) {
	    int max = 0;
	    int l = gain.size();
	    int sum = 0;
	    for (int i=0; i<l; ++i) {
		    sum += gain[i];
		    if (max < sum) max = sum;
	    }

	    return max;
    }
};

