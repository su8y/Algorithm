/**
 * 83. https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *root = head;
        ListNode *tmp = head;

        while(head) {
            while (head && head->val == tmp->val) head = head->next;
            tmp->next = head; // head is nullable
            tmp = tmp->next; // tmp is nullable (pointer)
        }
        return root;
    }
};
