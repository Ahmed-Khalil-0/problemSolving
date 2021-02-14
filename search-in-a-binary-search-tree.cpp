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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        if(root->val != val && (root->left == nullptr && root->right == nullptr)){
            return nullptr;
        }else if(root->val == val){
            return root;
        }
        TreeNode * rootL = searchBST(root->left, val);        
        TreeNode * rootR =searchBST(root->right, val);
        
        if(rootL != nullptr && rootL->val == val){
            return rootL;
        }else if(rootR != nullptr &&rootR->val == val){
            return rootR;
        }

    return nullptr;
    }
};
