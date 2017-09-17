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
    public List<String> binaryTreePaths(TreeNode root) {
        if (root == null) return Collections.emptyList();
        ArrayList<String> paths = new ArrayList<>();
        
        findPath(root, "", paths);

        return paths;
    }
    
    public void findPath(TreeNode root, String current, List<String> paths) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            if (current.length() == 0)
                paths.add(String.valueOf(root.val));
            else
                paths.add(current + "->" + root.val);
            return;
        }
        
        String c;
        if (current.length() == 0) {
            c = String.valueOf(root.val);
        } else {
            c =  current + "->" + root.val;
        }
        
        findPath(root.left, c, paths);
        findPath(root.right, c, paths);
    }
}