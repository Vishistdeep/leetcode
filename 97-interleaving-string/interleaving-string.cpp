class Solution {
public:
 bool solve(int i, int j, int k, vector<vector<vector<int>>>& dp, string s1,
               string s2, string s3) {
        if ((i == s1.length() && j == s2.length() && k == s3.length())) {
            return true;
        }

        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        bool result = false;
        if (i < s1.length() && s1[i] == s3[k]) {
            result = result || solve(i + 1, j, k + 1, dp, s1, s2, s3);
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            result = result || solve(i, j + 1, k + 1, dp, s1, s2, s3);
        }

        return dp[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
         if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<vector<int>>> dp(
            s1.length() + 1,
            vector<vector<int>>(s2.length() + 1,
                                vector<int>(s3.length() + 1, -1)));
        return solve(0, 0, 0, dp, s1, s2, s3); 
    }
};