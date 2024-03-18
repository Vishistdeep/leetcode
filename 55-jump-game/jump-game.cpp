class Solution {
public:
    bool canJump(vector<int>& nums) {
          int maxIndex = nums[0], n = nums.size(); 

        for (int i = 0; i < n; ++i) {
            if (maxIndex >= n - 1){
                 return true;
                 }

            if (nums[i] == 0 && maxIndex == i) {
                return false;
                }

           if (i + nums[i] > maxIndex) {
            maxIndex = i + nums[i];
            }
        }

        return true;
        
    }
};