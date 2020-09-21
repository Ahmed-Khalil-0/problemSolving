class Solution {
public:
    int climbStairs(int n) {
        //if((n < 2)){
           // return 1;
        //}
        //return (climbStairs(n-1) + climbStairs(n-2));
    //}
        int first = 1;
        if(n == 1)
            return first;
        int second = 2;
        if(n == 2)
            return second;
        int thrid = 0;
        for(int i = 3; i <= n;i++){
           thrid = first + second; 
            first = second; 
            second = thrid;
        }
        return thrid;
    }
};
