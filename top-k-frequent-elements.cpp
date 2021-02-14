class Solution {
    struct Item{
        int element;
        int priority;
        Item(int element, int priority)
        : element(element), priority(priority)
    {
    }
    };
    struct Comparepriority {
    bool operator()(Item const& p1, Item const& p2)
    {
        // return "true" if "p1" is ordered 
        // before "p2", for example:
        return p1.priority < p2.priority;
    }
};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return nums;
        }
        vector<int> vec;
        unordered_map<int, int> umap; 
        priority_queue<Item ,vector<Item>,Comparepriority> pq;

        for(int i = 0; i < nums.size();i++){
            //this element does not exists.
            if(umap.find(nums[i]) == umap.end()){
                umap[nums[i]] = 1;
            }else{
                umap[nums[i]] += 1;
            }
        }
        for(const auto &p:umap){
            pq.push(Item(p.first, p.second));
        }
        for (int i = 0;i<k;i++){
            vec.push_back(pq.top().element);
            pq.pop();
        }
        return vec;
    }
};
