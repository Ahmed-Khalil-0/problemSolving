class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return getAllSubsets(nums, 0);
    }
    
    vector<vector<int>> getAllSubsets(vector<int>& nums, int index){
        vector<vector<int>> allsubsets;
        if(nums.size() == index){
            vector<int> empty = {};
            allsubsets.push_back(empty);
        }else{
            allsubsets = getAllSubsets(nums, index + 1);
            int item = nums[index];
            vector<vector<int>> newSubsetCollector;
            for(vector<int> subset:allsubsets){
                vector<int> newSubset;
                newSubset.insert(newSubset.end(), subset.begin(), subset.end());
                newSubset.push_back(item);
                newSubsetCollector.push_back(newSubset);
            }
            allsubsets.insert(allsubsets.end(), newSubsetCollector.begin(), newSubsetCollector.end());
        }
        return allsubsets;
    }
};
