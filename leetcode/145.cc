/** 145: https://leetcode.com/problems/binary-tree-postorder-traversal/?envType=problem-list-v2&envId=v1pdb9am
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postOrder(root, v);
        return v;
    }

private:
    void postOrder(TreeNode* head, vector<int> &v) {
        if (head == nullptr) return;
        postOrder(head->left, v);
        postOrder(head->right, v);
        v.push_back(head->val);
    }
};
