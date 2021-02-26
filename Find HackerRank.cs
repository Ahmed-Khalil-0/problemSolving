using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    private static List<string> statements;
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        statements = new List<string>();
        int count = Convert.ToInt32(Console.ReadLine());
        for(int i = 0;i < count;i++){
            statements.Add(Console.ReadLine());
        }
        WhereWordIs(statements);
    }
    static private void WhereWordIs( List<string> statements){
        foreach(string s in statements){
            splitStatement(s);
        }
    } 
    
    static private void splitStatement(string s){
        string[] words = s.Split(' ');
        if(words.Length > 0 && words[0] == "hackerrank"){
            if(words[words.Length-1] =="hackerrank"){
                Console.WriteLine("0");
            }else{
                Console.WriteLine("1");
            }
        }else if(words.Length > 0 && words[words.Length-1] == "hackerrank"){
            if(words[0] =="hackerrank"){
                Console.WriteLine("0");
            }else
                Console.WriteLine("2");
        }else{
            Console.WriteLine("-1");
        }
    }
}
