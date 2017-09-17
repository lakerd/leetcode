/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) h
 * }
 */
public class Solution {
    public int sumNumbers(TreeNode root) {
        if (root == null)
            return 0;
        return solve(root, 0);
    }
    
    public int solve(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        }
        return Math.max(sum * 10 + root.val, 
                solve(root.left, sum * 10 + root.val) 
                + solve(root.right, sum * 10 + root.val));
    }
}