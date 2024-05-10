class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int n=nums.size(),ans=INT_MAX;
        vector<int>p(n+1,0);
        for (int i=1;i<=n;i++) p[i]=p[i-1]+nums[i-1];
        for (int i=n;i>=0 && p[i]>=target;i--) {
            int j=upper_bound(p.begin(),p.end(),p[i]-target)-p.begin();
            ans=min(ans,i-j+1);
        }
        return ans==INT_MAX?0:ans;
    }
};