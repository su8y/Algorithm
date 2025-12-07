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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* root = head;
        ListNode* l = list1;
        ListNode* r = list2;
        while(l && r) {
            if (l->val < r->val) {
                root->next = l;
                l = l->next;
            } else {
                root->next = r;
                r = r->next;
            }
            root = root->next;
        }
        if (l) {
            root->next = l;
        }  
        if (r) { 
            root->next = r;
        }

        return head->next;
    }
};
