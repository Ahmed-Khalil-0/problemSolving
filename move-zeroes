class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }

        int zerosCounter = 0;
        int lastNoneZero = 0; 
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                nums[lastNoneZero] = nums[i];
                lastNoneZero++;
            }else
            {
                zerosCounter++;
            }
 
        }
        for(int k = nums.size()-1; k >= (nums.size()-zerosCounter);k--){
            if(k > 0)
                nums[k] = 0;
            else
                return;
        }
    }
};
