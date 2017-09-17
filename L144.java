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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> nodes = new ArrayList<>();
        traverse(root, nodes);
        return nodes;
    }
    
    public static void traverse(TreeNode root, List<Integer> nodes) {
        if (root == null) return;
        nodes.add(root.val);
        traverse(root.left, nodes);
        traverse(root.right, nodes);
    }
}