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
        ListNode* slow_ptr = head, *fast_ptr = head;

        while (fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }


        ListNode* prev_ptr = nullptr;
        ListNode* current_ptr = slow_ptr;

        while(current_ptr) {
            ListNode* next_ptr = current_ptr->next;
            current_ptr->next = prev_ptr;
            prev_ptr = current_ptr;
            current_ptr = next_ptr;
        }
        ListNode* front_ptr = head;
        ListNode* end_ptr = prev_ptr;

        int ans = 0;
        while(end_ptr) {
            ans = max(ans, front_ptr->val + end_ptr->val);
            front_ptr = front_ptr->next;
            end_ptr = end_ptr->next;
        }

        return ans;
    }
};
