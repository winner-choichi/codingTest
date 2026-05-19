/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *n_node;
 *     ListNode() : val(0), n_node(nullptr) {}
 *     ListNode(int x) : val(x), n_node(nullptr) {}
 *     ListNode(int x, ListNode *n_node) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len=0;
        ListNode* n_node = head;
        while(n_node != nullptr) {
            len++;
            n_node = n_node->next;
        }

        int c_num = floor(len / 2);

        if (c_num == 0) return nullptr;

        ListNode* c_node = head, *p_node;
        for (int i=0; i<c_num; ++i) {
            p_node = c_node;
            c_node = c_node->next;
        }

        n_node = c_node->next;
        p_node->next = n_node;

        return head;
    }
};

