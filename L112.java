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
    public boolean hasPathSum(TreeNode root, int sum) {
        return hasSum(root, sum, 0);
    }
    
    public static boolean hasSum(TreeNode root, int finalSum, int currentSum) {
        if (root == null) return false;
        if (root.left == null && root.right == null && root.val + currentSum == finalSum) return true;
        return hasSum(root.left, finalSum, root.val + currentSum) || hasSum(root.right, finalSum, root.val + currentSum);
    }
}