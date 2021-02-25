class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return getAllSubsets(nums, 0);
    }
    vector<vector<int>> getAllSubsets(vector<int>& nums, int index){
        vector<vector<int>> allsubsets;
        if(index == nums.size()-1){
            vector<int> baseCase;
            baseCase.push_back(nums[index]);
            allsubsets.push_back(baseCase);
            return allsubsets;
        }else{
            allsubsets = getAllSubsets(nums, index + 1);
            int item = nums[index];
            vector<vector<int>> newSubsetCollector;
            for(int i = 0; i <= allsubsets[0].size();i++){
                for(vector<int> set:allsubsets){
                    set.insert(set.begin() + i, item);
                    newSubsetCollector.push_back(set);    
                }
            }
            
        allsubsets = newSubsetCollector;
        return allsubsets;
        }

    }
};
