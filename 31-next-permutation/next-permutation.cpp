class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int hasBig = -1;
        int index = -1;
        for(int i=nums.size()-2;i>=0 && index == -1;i--) { 
            for(int j=nums.size()-1;j>i;j--) {
                if(nums[j]>nums[i]) {
                    if(index == -1) {
                        hasBig = nums[j];
                        index = j;
                    } else if(nums[j]>nums[i] && hasBig>nums[j]) {
                        hasBig = nums[j];
                        index = j;
                    }
                }
            }
            if(index != -1) {
                swap(nums[i], nums[index]);
                sort(nums.begin() + i+1, nums.end());
                break;
            }
        }
        
        if(index==-1) {
            sort(nums.begin(), nums.end());
        }
        return; 
    }
};