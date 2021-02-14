class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalIndices = nums1.size() + nums2.size();
        int medianIndex = 0;
        double temp1 = 0;        
        double temp2 = 0;
        bool even = false;
        int p1 = 0; 
        int p2 =0;
        if(totalIndices%2 == 0){
            medianIndex = totalIndices/2;
            even = true;
        }else{
            medianIndex = totalIndices/2;
        }
        for(int i = 0; i <= medianIndex; i++){
            int num2=INT_MAX;int num1=INT_MAX;
            if(p1 < nums1.size())
                num1 = nums1[p1]; 
            if(p2 < nums2.size())
                num2 = nums2[p2];
            if((nums1.size() != 0)  && (num1 < num2)){
                if(even){
                    temp2 = temp1;  
                }
                temp1 = num1; 
                p1++;
            }else if((nums2.size() != 0)){
                if(even){
                    temp2 = temp1;  
                }
                temp1 = num2; 
                p2++;
            }
        }
        if(even){
            return (double)((temp1 + temp2) / 2);   
        }
         return (double)temp1; 
    }
};
