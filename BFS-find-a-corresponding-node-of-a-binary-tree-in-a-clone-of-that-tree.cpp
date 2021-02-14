/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> originalQ;        
        queue<TreeNode*> clonedQ;

        originalQ.push (original);        
        clonedQ.push (cloned);

        while(!originalQ.empty()){
            TreeNode* originalPop = originalQ.front();  
            originalQ.pop();  
            TreeNode* clonedPop = clonedQ.front();
            clonedQ.pop();
            
            if(originalPop == target){
                return clonedPop;
            }

            if(originalPop->left != nullptr){
                originalQ.push (originalPop->left);                
                clonedQ.push (clonedPop->left);
            }
            
            if(originalPop->right != nullptr){
                originalQ.push (originalPop->right);                
                clonedQ.push (clonedPop->right);
            }
        }
        return nullptr;
    }
};
