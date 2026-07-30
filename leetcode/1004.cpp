class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int left, right;

        int max = 0;
        if (k==0){
            int ptr = 0;
            while (true) {
                while (ptr < len && nums[ptr] == 0) ptr++;
                left = ptr;
                while (ptr < len && nums[ptr] == 1) ptr++;
                right = ptr;

                int current_cnt = right - left;
                if (max < current_cnt) max = current_cnt;

                left = ptr;

                if (left >= len) return max;
            } 
        } else {
            left = 0;
            right = 0;
            int remaining_k = k;

            while (right < len && (nums[right] == 1 || remaining_k > 0)) {
                if (nums[right] == 0) remaining_k--;
                right++;
            }
            max = right - left;

            while (true) {
                while(nums[left] == 1) left++;
                remaining_k++;
                left++;

                right++;
                remaining_k--;
                while(right < len && nums[right] == 1) right++;

                int current_cnt = right - left;
                if (max < current_cnt) max = current_cnt;

                if (right >= len) break;
            }
            
        }

        return max;
    }
};
