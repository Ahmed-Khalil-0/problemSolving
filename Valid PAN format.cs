using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    private static List<string> pins;
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        pins = new List<string>();
        int count = Convert.ToInt32(Console.ReadLine());
        for(int i = 0;i < count;i++){
            pins.Add(Console.ReadLine());
        }
        IsValidPin(count,pins);
    }
    
    static private void IsValidPin(int inputCount, List<string> pins){
        foreach(string s in pins){
            if((s.Length < 10)|| (!IsMatch(s))){
                Console.WriteLine("NO");
            }else{
                Console.WriteLine("YES");
            }
        }
    }
    
     static private bool IsMatch(string s){
        for(int i = 0;i<5;i++){
            if((!System.Char.IsLetter(s[i])) || (!System.Char.IsUpper(s[i]))){
                return false;
            } 
        }
        for(int i = 5;i<9;i++){
            if(!System.Char.IsDigit(s[i])){
                return false;
            } 
        }
        if((!System.Char.IsLetter(s[9])) || (!System.Char.IsUpper(s[9])))
        return false;
        
        return true;
     }
}
