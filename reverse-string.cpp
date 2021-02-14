class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0 || s.size() == 1){
            return;
        }
        char temp = ' ';
        for(int i = 0;i<s.size()/2;i++){
            temp = s[i];    
             s[i] = s[(s.size()-1) - i];
            s[(s.size()-1) - i] = temp;
        }
    }
};
