/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int path_Sum = 0;
        if(root == nullptr)
            return path_Sum;
        
        path_Sum += hasPathSum(root,sum);
        
        if(root->left == nullptr && root->right == nullptr){
            return path_Sum;
        }
        
        path_Sum+=pathSum(root->left, sum);  
        path_Sum+=pathSum(root->right, sum);
                
        return path_Sum;
    }
    
    int hasPathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(root == nullptr)
            return 0;

        if((targetSum == root->val) ){
            count+=1;
        }
        if( (root->left == nullptr && root->right == nullptr)){
            return count;
        }
        count +=  hasPathSum(root -> left,(targetSum - root->val)) ;        
        count +=  hasPathSum(root -> right,(targetSum - root->val)) ;

        return count;
    }
};
