class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       int l=0,pmin=-1,pmax=-1;
       long res=0;
       for(int r=0;r<nums.size();r++){
        int n=nums[r];
        if(n<minK || n>maxK){
            l=r+1;
            pmin=-1;
            pmax=-1;

        }
        else{
            if(n==minK){
                pmin=r;

            }
            if(n==maxK){
                pmax=r;
            }
            res+=max(0,min(pmin,pmax)-l+1);
        }

       } 
       return res;
    }
};