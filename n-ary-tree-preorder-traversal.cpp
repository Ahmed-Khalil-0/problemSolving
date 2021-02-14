/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> vec;
        if(root == nullptr){
            return vec;
        }
        if((root->children).empty()){
             vec.push_back(root-> val);
            return vec;
        }
        
        for(int i = 0; i < (root->children).size();i++){
            vector<int> returnedResult = preorder((root->children)[i]);
            vec.insert(vec.end(),returnedResult.begin(),returnedResult.end());
        }
         vec.insert(vec.begin(),root->val);
        return vec;
    }
};
