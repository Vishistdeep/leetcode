class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int MAX_SUM = -1e9;
        int max_sum_that_ends_here = 0;
        int left_sum = 0, right_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_sum_that_ends_here += nums[i];
            MAX_SUM = std::max(max_sum_that_ends_here, MAX_SUM);
            max_sum_that_ends_here = std::max(max_sum_that_ends_here, 0);
            right_sum += nums[i];
        }
        int max2 = 0;
        for (const auto num: nums){
            MAX_SUM = std::max(MAX_SUM, right_sum + max2);
            right_sum -= num;
            left_sum += num; 
            max2 = std::max(max2, left_sum);
        }
        return MAX_SUM;   
    }
};