class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
          vector<vector<bool>> dp(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (helper(i, j, 0, word, board, dp)) return true;
                }
            }
        }
        return false;
    }
    
private:
    bool helper(int i, int j, int pos, string& s, vector<vector<char>>& board, vector<vector<bool>>& dp) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || dp[i][j] || pos >= s.length() || board[i][j] != s[pos]) return false;
        if (pos == s.length() - 1) return true;
        dp[i][j] = true;
        if (helper(i - 1, j, pos + 1, s, board, dp) || helper(i, j + 1, pos + 1, s, board, dp) || helper(i + 1, j, pos + 1, s, board, dp) || helper(i, j - 1, pos + 1, s, board, dp)) 
            return true;
        dp[i][j] = false;
        return false;
    }
};