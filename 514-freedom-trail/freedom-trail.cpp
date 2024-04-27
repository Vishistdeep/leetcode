class Solution {
public:
    int findRotateSteps(string ring, string key) {
      int n=ring.size();
        int m=key.size();
        // cout<<n<<" "<<m;
        // queue<vector<int>> q;
        vector<int> arr[26];
        for(int i=0;i<n;i++){
            arr[ring[i]-'a'].push_back(i);
        }
        // q.push({0,-1,0});
        // int s=1;
        // int ans=INT_MAX;
        // while(q.size()){
        //     s=q.size();
        //     while(s--){
        //         auto ele=q.front();
        //         q.pop();
        //         int state=ele[0];
        //         int ind_key=ele[1];
        //         int steps=ele[2];
        //         if(ind_key==m-1){
        //             ans=min(ans,steps+m);
        //             continue;
        //         }
        //         if(ind_key!=-1 && dp[state][ind_key]!=-1 && dp[state][ind_key]<steps) continue;
        //         char c=key[ind_key+1];
        //         for(int& i: arr[c-'a']){
        //             int x=min(abs(i-state),abs(min(state,i)+n-max(state,i)));
        //             if(dp[i][ind_key+1]!=-1 && dp[i][ind_key+1]<steps+x) continue;
        //             dp[i][ind_key+1]=steps+x;
        //             q.push({i,ind_key+1,steps+x});
        //         }
        //     }
        // }
        // return ans;
        vector<int> dp(n,0);
        for(int i=m-2;i>=0;i--){
            vector<int> vec;
            for(int& ind: arr[key[i]-'a']){
                int res=INT_MAX;
                for(int& j: arr[key[i+1]-'a']){
                    res=min(res,min(abs(j-ind),abs(min(j,ind)+n-max(j,ind)))+ dp[j]);
                }
                vec.push_back(res);
            }
            int k=0;
            for(int& ind: arr[key[i]-'a']){
                dp[ind]=vec[k++];
            }
        }
        int ans=INT_MAX;
        for(int& ind: arr[key[0]-'a']){
            ans=min(ans,min(abs(ind-0),abs(n-ind))+ dp[ind]);
        }
        return ans+m;  
    }
};