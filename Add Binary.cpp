class Solution {
public:
    string addBinary(string a, string b) {
        string s ="";
        int carry = 0;
        char a1;
        char b2;
        int sa = a.size();
        int sb = b.size();
        while(true){
            
            if(sa > 0){
                sa--; 
                a1 = a[sa];
            }else
                a1 = '0';
            if(sb > 0){
                sb--;
                b2 = b[sb];
            }else
                b2 = '0';
            s += (((a1 - '0') + (b2 - '0') + carry) % 2) + '0';
            carry = ((a1 - '0') + (b2 - '0') + carry) / 2;
            
            if( sa == 0  && sb == 0)
                break; 
        }
        
        if(carry)
            s+= carry + '0';
        
        std::reverse(s.begin(),s.end());
        
        return s;
        }
    
};
