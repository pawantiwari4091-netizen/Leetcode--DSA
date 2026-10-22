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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* one = head;
        ListNode* oneprev = NULL;

        int i = 1;
        while (i < left) {
            oneprev = one;
            one = one->next;
            i++;
        }

        ListNode* two = one;
        while (i < right) {
            two = two->next;
            i++;
        }

        ListNode* twonext = two->next;

        ListNode* prev = NULL;
        ListNode* curr = one;

        for (int i = left; i <= right; i++) {
            ListNode* t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }

        if (oneprev != NULL) {
            oneprev->next = prev;
        } else {
            head = prev;
        }

        one->next = twonext;

        return head;
    }
};
