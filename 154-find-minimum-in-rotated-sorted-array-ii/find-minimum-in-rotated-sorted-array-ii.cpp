class Solution {
public:
    int findMin(vector<int>& nums) {
    /* int small = 0,large = nums.size() - 1, mid = small + ( large - small)/2;
     while(small < large)
     {
      if( nums[mid] > nums[large] )
      {
          small = mid + 1;
      }
      else if ( nums[mid] < nums[large])
     {
         large = mid;
     }
    
     else if(nums[large] == nums[large - 1])
     {
         large --;
     }
     else{
         small++;
     }
     mid = small + (large - small)/2;
     }
     return nums[small];*/
     int min=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(min>nums[i])
            min=nums[i];
        }
        return min;
    }
};