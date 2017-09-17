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
    public int findBottomLeftValue(TreeNode root) {
        return find(root, 1, new int[]{root.val, 0});
    }
    
    public int find(TreeNode root, int level, int[] state) {
        if (level > state[1] && root != null) {
            state[0] = root.val;
            state[1] = level;
        }

        if (root.left != null) find(root.left, level + 1, state);
        if (root.right != null) find(root.right, level + 1, state);
        
        return state[0];
    }
}