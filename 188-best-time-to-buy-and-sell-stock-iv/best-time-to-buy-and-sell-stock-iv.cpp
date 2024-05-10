class Solution {
public:
int dp[1002][102][2];

    int maxProfit(int k, vector<int>& prices) {
      auto maximize = [&](int &x, int  y) {
			if (x < y) {
				x = y;
				return true;
			}
			return false;
		};

    	int n = prices.size();		
		const int INF = 1e9 + 1;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				dp[i][j][0] = dp[i][j][1] = -INF;
		dp[0][0][0] = 0; dp[0][1][1] = -prices[0];

		for (int i = 0; i + 1 < n; i++)
			for (int j = 0; j <= k; j++) {
				maximize(dp[i + 1][j][0], dp[i][j][0]);		
				maximize(dp[i + 1][j][1], dp[i][j][1]);
				maximize(dp[i + 1][j + 1][1], dp[i][j][0] - prices[i + 1]);
				maximize(dp[i + 1][j][0], dp[i][j][1] + prices[i + 1]);
			}

		int ans = 0;
		for (int i = 0; i <= k; i++) maximize(ans, dp[n - 1][i][0]);
		return ans;	  
    }
};