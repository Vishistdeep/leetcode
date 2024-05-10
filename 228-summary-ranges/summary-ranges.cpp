class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
     if(nums.size()==0)return {};
        vector<string> ans;
        int i=0;
        int j=1;
        int x=1;
        while(j<nums.size()){
            if(nums[i]+x==nums[j]){
                j++;
                x++;
            }
            else{
                x=1;
                string temp="";
                if(nums[i]==nums[j-1]){
                    string a=to_string(nums[i]);
                    temp+=a;
                    ans.push_back(temp);
                    i=j;
                    j++;
                }
                else{
                    string a=to_string(nums[i]);
                    temp+=a;
                    temp+="->";
                    string b=to_string(nums[j-1]);
                    temp+=b;
                    ans.push_back(temp);
                    i=j;
                    j++;
                }
            }
        }
        string temp="";
        if(nums[i]==nums[j-1]){
                    string a=to_string(nums[i]);
                    temp+=a;
                    ans.push_back(temp);
                }
                else{
                    string a=to_string(nums[i]);
                    temp+=a;
                    temp+="->";
                    string b=to_string(nums[j-1]);
                    temp+=b;
                    ans.push_back(temp);
                }
        return ans;    
    }
};