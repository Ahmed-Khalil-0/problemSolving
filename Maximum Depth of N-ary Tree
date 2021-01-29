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
    int maxDepth(Node* root) {
        if(root == nullptr)
            return 0;
        if((root->children).empty()){
            return 1;
        }
        
        int max = 0;
        for(int i = 0; i < (root -> children).size(); i++){
            int temp = maxDepth((root -> children)[i]);
            if (temp >  max){
                max = temp;
            }
        }
        return max + 1;
    }
};
