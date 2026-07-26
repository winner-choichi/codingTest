class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX;
        int middle = INT_MAX;

        for (int n: nums) {
            if (n <= small) {
                small = n;
            } else if (n <= middle) {
                middle = n;
            } else return true;
        }

        return false;
    }
};
