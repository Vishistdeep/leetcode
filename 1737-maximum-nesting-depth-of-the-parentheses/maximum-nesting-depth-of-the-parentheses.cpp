class Solution {
public:
    int maxDepth(string s) {
         int n = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                n++; 
            } else if (s[i] == ')') {
                n--; 
            }
            ans = max(ans, n); 
        }

        return ans;
    }
};