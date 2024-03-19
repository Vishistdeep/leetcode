class Solution {
public:
 bool result(int i, string &s, vector<int> &vec, vector<string> &wordDict){
        if(i==s.size()) {
            return true;
            }
        if(vec[i]!=-1) {
            return vec[i];
            }
        for(int j=i;j<s.size();j++){
            string v= s.substr(i,j-i+1);
            if(find(wordDict.begin(),wordDict.end(),v)!=wordDict.end()){
                if(result(j+1,s,vec,wordDict)) {
                    return vec[i]=true;
                    }
            }
        }
        return vec[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> vec(n+1,-1);
        return result(0,s,vec,wordDict);
    }
};
   