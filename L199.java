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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;
        
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        
        while (true) {
            int size = q.size();
            if (size == 0) break;
            
            TreeNode last = null;
            for (int i = 0; i < size; i++) {
                TreeNode peek = q.pollFirst();
                if (peek != null) {
                    if (peek.left != null) q.add(peek.left);
                    if (peek.right != null) q.add(peek.right);
                    last = peek;
                }
            }
            
            result.add(last.val);
        }


        return result;
    }
}