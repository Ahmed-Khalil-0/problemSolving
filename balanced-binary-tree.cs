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
    public bool IsBalanced(TreeNode root) {
        bool p = true;
        CBT(root, ref p);
        return p;
    }
    
    private int CBT(TreeNode root, ref bool p){
        if(root == null){
            return 0; 
        }
        
        int L = 0;
        if(p){
            L = CBT(root.left, ref p);
        }
        int R = 0; 
        if(p){
            R = CBT(root.right, ref p);
        }
        
        if(Math.Abs(L-R) >= 2){
            p = false; 
            return 0; 
        }
        return Math.Max(L,R) + 1;
    }
}
