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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *even_list = head, *odd_list = nullptr;
        ListNode *even_last = head, *odd_last = nullptr;
        while(1) {
            if (even_last->next == nullptr) {
                if (odd_list == nullptr) return even_list;
                even_last->next = odd_list;
                odd_last->next = nullptr;
                // cout << "1: " << even_last->val << ' ' << odd_last->val << '\n';
                return even_list;
            } else {
                if (odd_list == nullptr) {
                    odd_list = even_last->next;
                    odd_last = odd_list;
                    // cout << "2: " << even_last->val << ' ' << odd_last->val << '\n';
                } else {
                    odd_last->next = even_last->next;
                    odd_last = odd_last->next;
                    // cout << "3: " << even_last->val << ' ' << odd_last->val << '\n';
                }
            }

            if (odd_last->next == nullptr) {
                even_last->next = odd_list;
                // cout << "4: " << even_last->val << ' ' << odd_last->val << '\n';
                return even_list;
            } else {
                even_last->next = odd_last->next;
                even_last = even_last->next;
                // cout << "5: " << even_last->val << ' ' << odd_last->val << '\n';
            }
        }
    }
};

