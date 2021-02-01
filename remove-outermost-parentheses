class Solution {
public:
    string removeOuterParentheses(string S) {
        
        if(S == "")
            return S;
        
        stack<char> temp;
        string r = "";
        for(char c : S){
            if(c == '('){
                if(temp.size()>0)
                    r+= '(';
                temp.push(c);
            }else if(c == ')'){
                if(temp.size()>1)
                    r+= ')';
                temp.pop();
            }
        }
        return r;
    }
};
