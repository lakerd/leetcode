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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return Collections.emptyList();
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        
        List<List<Integer>> result = new ArrayList<>();
        
        while (true) {
            int count = q.size();
            if (count == 0) break;
            ArrayList<Integer> tmp = new ArrayList<>();
            while (count > 0) {
                TreeNode t = q.poll();
                tmp.add(t.val);
                if (t.left != null) q.add(t.left);
                if (t.right != null) q.add(t.right);
                count--;
            }
            result.add(tmp);
        }
        
        return result;
    }
}