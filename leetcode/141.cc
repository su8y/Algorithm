/**
 * 141: https://leetcode.com/problems/linked-list-cycle/?envType=problem-list-v2&envId=v1pdb9am
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(true) {
            if (slow->next == nullptr) return false;
            slow = slow->next;
            for(int i=0;i<2;i++){
                if(fast->next == nullptr) return false;
                fast = fast->next;
            }
            if (slow == fast) return true;
        }
        return false;
    }
    // TC: O(N) SC: O(N)
    // bool hasCycle(ListNode *head) {
    //     set<ListNode*> s;
    //     while(head) {
    //         if (s.count(head) > 0) return true;
            
    //         s.insert(head);
    //         head = head->next;
           
    //     }
    //     return false;
    // }
};
