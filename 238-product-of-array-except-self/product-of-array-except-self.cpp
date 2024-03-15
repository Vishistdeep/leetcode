class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int>ans(nums.size(),0);{
        int count_zero = 0,n = nums.size();
        long long product = 1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                count_zero++;
                }
            else{
                 product *= nums[i];
                 }        }
        if(count_zero > 1){
        return ans;
        }
        else if(count_zero == 1){
            for(int i=0;i<n;i++){
                if(nums[i] != 0){
                    ans[i] = 0;
                    }
                else {
                    ans[i] = product;
                    }
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans[i] = product/nums[i];
            }
        }
        return ans;
        }

        
    }
};