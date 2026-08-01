/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;

        ListNode* ptr = head;
        while(ptr) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }

        int len = nums.size();
        int maxSum = 0;
        for(int i=0; i<len/2; i++) {
            maxSum = max(maxSum, nums[i] + nums[len - 1 - i]);
        }

        return maxSum;
    }
};
