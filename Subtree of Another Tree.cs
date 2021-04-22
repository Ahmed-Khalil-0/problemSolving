/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool IsSubtree(TreeNode s, TreeNode t) {
        StringBuilder s1 = traversTree(s);
        StringBuilder s2 = traversTree(t);
        
        Console.WriteLine(s1.ToString());        
        Console.WriteLine(s2.ToString());

        if((s1.ToString()).IndexOf(s2.ToString())!= -1)
            return true;
        else 
            return false; 
    }
    private StringBuilder traversTree(TreeNode node){
        StringBuilder result = new StringBuilder();
        if(node == null){
            result.Append("X");
            return result;

        }
        result.Append(','+(node.val).ToString() + "," );
        
        result.Append(traversTree(node.left));        
        result.Append(traversTree(node.right));

        return result;
    }
}
