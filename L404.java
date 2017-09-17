/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        int[] s = new int[]{0};
        sum(root, s);
        return s[0];
    }
    
    private void sum(TreeNode root, int[] state) {
        if (root == null) return;
        if (root.left != null) { 
            TreeNode left = root.left;
            if (left.left == null && left.right == null)
                state[0] += left.val;
        }
        
        sum(root.left, state);
        sum(root.right, state);
    }
}