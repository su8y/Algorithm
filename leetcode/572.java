/** 572. Subtree of Another Tree */
class Solution {
    private boolean isSame(TreeNode q, TreeNode p) {
        if (q == null && p == null) { return true; }
        if (q == null || p == null) { return false; }
        if (q.val != p.val) { return false; }

        boolean answer = true;
        answer &= isSame(q.left, p.left);
        answer &= isSame(q.right, p.right);

        return answer;
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // 빠른 실패
        if (root == null && subRoot == null) return true;

        // BFS(FIFO Algorithm)
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (isSame(cur, subRoot)) {
                return true;
            }
            if (cur.left != null) { q.offer(cur.left); }
            if (cur.right != null) { q.offer(cur.right); }
        }
        
        // return false if its not same.
        return false;
    }
}
