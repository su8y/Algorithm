/*
 * [160] Intersection of Two Linked Lists https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/7313924/video-this-is-based-on-the-same-principl-bx1i/
 *
 * 각 headA, headB를 거꾸로 탐색하여서 memory가 같은지 equals 연산을 한다. `==`
 * - [x] 맨 뒤 노드가 다르면 그 즉시 nullptr 반환 (겹치는 노드가 없음)
 * - [x] 각 head노드들을 거꾸로 탐색 
 * - [x] 탐색하면서 같은 것들에 대해서 갱신
 * - [x] single linked-list 이기 때문에 거꾸로 하는 연산에 대한 작업을 만듬
 */

// @lc code=start
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
    // 11.35%, 5.63%
    // 9.71%, 5.63%
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodeSet;

        while(headA != nullptr) {
            nodeSet.insert(headA);
            headA = headA->next;
        }
        while(headB != nullptr) {
            if (nodeSet.count(headB) == 1) return headB;
            headB = headB->next;
        }

        return nullptr;
    }

    // runtime, memory: 27.02%, 5.63%
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* answer = nullptr;
        
    //     // store stack 
    //     deque<ListNode*> stackA;
    //     deque<ListNode*> stackB;
    //     while (headA != nullptr) {
    //         stackA.push_back(headA); 
    //         headA = headA->next;
    //     }
    //     while (headB != nullptr) {
    //         stackB.push_back(headB);
    //         headB = headB->next;
    //     }
        

    //     // logic
    //     while(!stackA.empty() && !stackB.empty()) {
    //         if (stackA.back() == stackB.back()) answer = stackA.back();
    //         else break;
    //         stackA.pop_back();
    //         stackB.pop_back();
    //     }
        
    //     return answer;
    // }
};
