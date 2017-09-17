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
    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null) return Collections.emptyList();
        
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        
        
        while (!st.isEmpty()) {
            TreeNode t = st.pop();
            if (t.left != null) st.push(t.left);
            if (t.right != null) st.push(t.right);
            result.add(t.val);
        }
        
        Collections.reverse(result);
        return result;
    }
}