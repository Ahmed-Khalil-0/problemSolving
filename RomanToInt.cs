public class Solution {
    public int RomanToInt(string s) {
        Dictionary<char, int> mapper = new Dictionary<char, int>(){
            {'I',1},
            {'V',5},
            {'X',10},            
            {'L',50},            
            {'C',100},            
            {'D',500},            
            {'M',1000}
            };
            // look at the first char and the sec one 
            // if the first is less in value then the second 
            // abstract the second from the first and then add it to sum
            // esle add to sum directlly

            char[] chars = s.ToCharArray();
            int result = 0;
            for (int i = 0; i < chars.Count(); i++)
            {
                if (((i+1) < chars.Count()) && mapper[chars[i]] < mapper[chars[i + 1]])
                {
                    result += (mapper[chars[i + 1]] - mapper[chars[i]]);
                    i++;
                }
                else
                {
                    result += mapper[chars[i]];
                }
            }
            return result;
    }
}
