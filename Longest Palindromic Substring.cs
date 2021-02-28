public class Solution {
    public string LongestPalindrome(string s) {
        string result = "";
        int left = s.Length - 1; 
        for(int i = left; i >= 0;i--){
            for(int j = 0; j < left;j++){
                //Console.WriteLine("s[i] " +s[i]+ " s[j] " +s[j]);
                if(s[i] == s[j]){
                    //Console.WriteLine("====s[i] " +s[i]+ " s[j] " +s[j]);
                    if(i+1-j > 0&&IsPalindrom(s.Substring(j, i+1-j))){
                        if(result.Length < s.Substring(j, i+1-j).Length){
                            result = s.Substring(j, i+1-j);
                        }
                        
                    }
                }
            }
        }
        if(result.Length > 0)
            return result;
        return Convert.ToString(s[0]);
    }
    private bool IsPalindrom(string s){
        int left = s.Length-1; 
        int right = 0;
        while(right < left){
            if(s[left] != s[right]){
                return false;
            }
            right++;
            left--;
        }
        return true;
    }
}
