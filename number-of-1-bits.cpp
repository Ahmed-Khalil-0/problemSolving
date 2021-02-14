class Solution {
public:
    int hammingWeight(uint32_t n) {
        int onesCount = 0;
        for(int i = 0; i < 32; i++){
            if(1&n){
                onesCount++;
            }
            n >>= 1;            
        }
        return onesCount;
    }
};
