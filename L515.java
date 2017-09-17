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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        
        if (root == null) return result;
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        
        q.add(root);
        
        while (true) {
            
            int size = q.size();
            if (size == 0) break;
            
            int max = q.peek().val;
            while (size-- > 0) {
                TreeNode t = q.poll();
                if (t.val > max) max = t.val;
                
                if (t.left != null) q.add(t.left);
                if (t.right != null) q.add(t.right);
            }
            
            result.add(max);
        }
        
        return result;

    }
}