class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;

        //sum all the nums 
        for(int i:nums)
            leftSum += i;
        int pivot = 0; 
        //substract or sum the first
        for(int i = 0; i<nums.size();i++){
            pivot = nums[i];
            leftSum -= pivot;   
            //cout<<"rightsum -> "<<rightSum <<" ,leftsum -> " <<leftSum<< " ,pivot -> "<<pivot<<endl; 
            if(leftSum == rightSum){
                return i;
            }
            rightSum += pivot;
        }
        return -1;
    }
};
