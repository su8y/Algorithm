/** 100. Same Tree */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) { return true; }

        if (p == null || q == null) { return false; }
        if (p.val != q.val) { return false; }

        boolean answer = true;
        answer &= isSameTree(p.left, q.left);
        answer &= isSameTree(p.right, q.right);

        return answer;
    }
}
