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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        if((root -> right == nullptr && root -> left == nullptr )){
            return root;
        }
        TreeNode*  temp = nullptr;
        invertTree(root -> left);
        invertTree(root -> right);
        // inverting the nodes 
        temp = root->left;
        root -> left = root-> right; 
        root -> right = temp;
        return root;
    }
};
