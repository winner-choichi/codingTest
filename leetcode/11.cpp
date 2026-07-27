class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();

        int left = 0, right = len - 1;

        long long max_area = 0;
        while (left < right) {
            int lh = height[left], rh = height[right];
            long long area;
            if (lh > rh) {
                area = (long long) (right - left) * rh;
                right--;
            } else {
                area = (long long) (right - left) * lh;
                left++;
            }
            if (max_area < area) max_area = area;
        }

        return max_area;
    }
};
