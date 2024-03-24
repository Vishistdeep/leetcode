class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<string> s = strs;
        for(int i=0;i<s.size();i++){
            sort(s[i].begin(),s[i].end());
        }

        vector<vector<string>> ans;
        unordered_map<string,int> mp;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i]) != mp.end())
                ans[mp[s[i]]].push_back(strs[i]);
            else{
                vector<string> st;
                st.push_back(strs[i]);
                ans.push_back(st);
                mp[s[i]] = ans.size()-1;
            }
        }

        return ans; 
    }
};