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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root-> left == nullptr && root ->right== nullptr){
            return 1;
        }
        
        int valueL = 0;
        valueL = valueL + maxDepth(root -> left);
        int valueR = 0;
        valueR = valueR + maxDepth(root -> right); 
       if(valueL >= valueR){
            return valueL+1;
        }else{
            return valueR+1;
        }
    }
};
