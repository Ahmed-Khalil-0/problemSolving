class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_Max = nums[0] ; 
        int global_Max = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            current_Max = max(nums[i] , current_Max + nums[i]);
            global_Max = max(global_Max, current_Max);
        }
        return global_Max;
    }
};
