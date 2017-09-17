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
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        List<Integer> result = new ArrayList<>();
        
        if (root == null) {
            return result;
        }
        
        
        TreeNode cur = root;
        
        while (cur != null || !st.isEmpty()) {
            if (cur != null) {
                st.push(cur);
            	cur = cur.left;
            } else {
                cur = st.pop();
                result.add(cur.val);
                cur = cur.right;
            }
        }
        
        return result;
    }
}