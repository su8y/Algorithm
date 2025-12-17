/** 144: https://leetcode.com/problems/binary-tree-preorder-traversal/description/?envType=problem-list-v2&envId=v1pdb9am
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorderTraverse(root, v);
        return v;


    }
private:
    void preorderTraverse(TreeNode* head, vector<int> &v) {
        if (head == nullptr) return;
        v.push_back(head->val);
        preorderTraverse(head->left, v);
        preorderTraverse(head->right, v);
    }
};
