class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() < 2){
            return true;
        }
        int frontPointer = 0; 
        int lastPointer = s.length() - 1; 
        while(frontPointer <= lastPointer){
            while(!isalnum(s[frontPointer])){
                if(frontPointer < s.length())
                    frontPointer++;
                else
                    return true;
            }
            while(!isalnum(s[lastPointer])){
                lastPointer--;
            }
            if(tolower(s[frontPointer]) != tolower(s[lastPointer])){
                return false;
            }
            frontPointer++;
            lastPointer--;
            
        }
    return true;

    }
};
