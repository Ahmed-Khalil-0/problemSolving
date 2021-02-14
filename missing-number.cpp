class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int shouldBe = 0;
        int exists = 0;
        int i = 0;
        for(i; i < nums.size();i++){
            shouldBe += i;
            exists += nums[i];
        }
        shouldBe += i;
        return shouldBe-exists;
    }
};
