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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> vec;
        if(root == nullptr)
            return vec;
        if( (root->left == nullptr && root->right == nullptr)){
            if(root->val == targetSum){
                vector<int> vec1;
                vec1.push_back(root-> val);
                vec.push_back(vec1);
                return vec;
            }else{
                return vec; 
            }
        }
        
        //returned path from the left path.
        vector<vector<int>> vecL = pathSum(root-> left, (targetSum - root->val));    
        if(vecL.size() > 0){
            for(vector<int> v:vecL){
                v.insert(v.begin(), root->val);
                vec.push_back(v);
            }
        }
        
        vector<vector<int>> vecR = pathSum(root-> right, (targetSum - root->val));
        if(vecR.size() > 0){
            for(vector<int> v:vecR){
                v.insert(v.begin(), root->val);
                vec.push_back(v);
            }
        }
        
        return vec;
    }
};
