class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int>::iterator it = digits.begin();
        int carry = 1;
        int temp = 0;
        for(int i = digits.size()-1; i >= 0; i--){
            temp = digits[i];
            digits[i] = (digits[i] + carry)%10;
            carry = (temp + carry)/10;
            if(!carry)
                break;                
        }
        if(carry)
            digits.insert(it, carry);
        return digits;
    }
};
