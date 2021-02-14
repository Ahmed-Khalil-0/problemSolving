class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())
            return -1;
        if(haystack.size() == 0 || needle.size() == 0)
            return 0; 
        int subStringPointer = 0;
        int LPS[needle.size()] ;
        createLPS(LPS, needle);
        int i = 0;
       while( i < haystack.size()){
            if(needle[subStringPointer] == haystack[i]){
                subStringPointer++;
                i++;
            }
            else if(needle[subStringPointer] != haystack[i])
            {
                if(subStringPointer != 0)
                    subStringPointer = LPS[subStringPointer-1];
                else
                    i++;
            }
            if(needle.size() == subStringPointer)  {
                return (i - needle.size());
            }
        }
        return -1;
    }
private:
    void createLPS(int LPS[] , string needle){
        int j = 0;
        LPS[0] = 0;
        for(int i = 1; i < needle.size(); i++){
            if(needle[i] == needle[j]){
                LPS[i] = j + 1;
                j++;
            }else{
                while((j != 0) && (needle[j]!= needle[i]))
                    j = LPS[j - 1];
                if(needle[j] != needle[i])
                    LPS[i] = j;
                else
                {
                    LPS[i] = j + 1;
                    j++;
                }
            }
        }
    }
};
