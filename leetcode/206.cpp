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
    ListNode* reverseList(ListNode* head) {
    
        if (head == nullptr) return nullptr;
        ListNode *n_node = head->next;
        if(n_node == nullptr) return head;

        ListNode *p_node = nullptr;
        ListNode *c_node = head;
        while (c_node != nullptr) {
            n_node = c_node->next;
            c_node->next = p_node;
            p_node = c_node;
            c_node = n_node;
        }

        return p_node;
        }
};

