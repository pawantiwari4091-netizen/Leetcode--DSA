/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int curr_node_val = node->val;
        int next_val = node->next->val;
        node->val = next_val;
        node->next->val = curr_node_val;
        ListNode* n = node->next;
        node->next = node->next->next;
        n->next = NULL;
        delete n;
    }
};