class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordCount = 0;
        int i = s.size() - 1;
        //cleaning whiet speaces
        while((i >= 0) && (s[i] == ' '))
            i--;
        while((i >= 0) && (s[i] != ' ')){
            wordCount++;
            i--;
        }
        return wordCount;
    }
};
