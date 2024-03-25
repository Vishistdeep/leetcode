class Solution {
public:
    string countAndSay(int n) {
       /* string ans = "1";
        for(int i = 2;i <= n;i++)
        {
            string temp = ""; 
            int j = 0; 
            while(j < ans.size()) 
            {
                int count = 0;
                char ch = ans[j]; 
                while(j <= ans.size() && ans[j]==ch) 
                {
                    count++; 
                    j++; 
                }
                temp += to_string(count)+ ch; 
            }
            ans = temp; 
        }
        return ans;*/
         if(n == 1)  {
            return "1";

         }
        string s = countAndSay(n-1);

        int i = 0, j = 0;
        string r;

        while(i < s.size()) {
            j = i+1;

            while(j < s.size() && s[j] == s[i]){

            
                ++j;
            }
            string ct = to_string(j-i);
            r += ct + s[i];
            
            i = j;
        }
        return r; 
    }
};