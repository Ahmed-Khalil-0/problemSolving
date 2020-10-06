class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int beginOfWindow = 0;        
        int endOfWindow = 0;
        int visitedIndex = 0;
        int longestSubset = 0;
        bool visitedChar[265] = {false};
        for(int i = 0; i < s.size();i++){
            visitedIndex = s[i] - ' ';
            if(visitedChar[visitedIndex]!=true){
                visitedChar[visitedIndex] = true;
                endOfWindow++;
            }else{
                if(s[beginOfWindow] == s[endOfWindow])    
                    beginOfWindow++; 
                else{

                    while(s[beginOfWindow] != s[endOfWindow]){
                        visitedIndex = s[beginOfWindow] - ' ';
                        visitedChar[visitedIndex] = false;
                        beginOfWindow++;
                    }
                     beginOfWindow++;
                }
                endOfWindow++;
            }
            if(longestSubset < (endOfWindow - beginOfWindow))
                    longestSubset = (endOfWindow - beginOfWindow);
        }
        return longestSubset;
    }
};
