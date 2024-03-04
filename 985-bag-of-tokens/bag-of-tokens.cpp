class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
         sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int max_score = 0;
        int start = 0;
        int end = n - 1;
        
        while (start <= end) {
            if (power >= tokens[start]) {
                power -= tokens[start];
                score += 1;
                start += 1;
                max_score = max(max_score, score);
            } else if (score > 0) {
                power += tokens[end];
                score -= 1;
                end -= 1;
            } else {
                break;
            }
        }
        
        return max_score;
        
        
    }
};