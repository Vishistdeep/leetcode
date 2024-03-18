class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
             }
         }   
        

        
    }
}; //sort(nums.begin(), nums.end());