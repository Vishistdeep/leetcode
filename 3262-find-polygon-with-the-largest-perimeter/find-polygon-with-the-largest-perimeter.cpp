class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n = nums.size();
       long long sum=0;
      for(int j=0;j<n;j++){
        sum=sum+nums[j];
      }
    for(int i=n-1;i>1;i--){
        if(nums[i]<sum-nums[i]){
            return sum;
        }else{
            sum=sum-nums[i];
        }
    }
      
      return -1;
        
    }
};