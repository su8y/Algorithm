/** 104. Maximum Depth of Binary Tree */
class Solution {
    public int maxDepth(TreeNode root) {

        if (root == null) { return 0; }

        // 자기 자신의 깊이는 1이다.
        int leftMaximumDepth = maxDepth(root.left);
        int rightMaximumDepth = maxDepth(root.right);
        return 1 + Math.max(leftMaximumDepth, rightMaximumDepth);
    }
}
