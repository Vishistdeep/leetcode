class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> lengths(26, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int idx = c - 'a';
            // doesnt loop arnd
            int lowerBound = max(0, idx - k);
            int upperBound = min(26, idx + k + 1);
            int longest = 0;
            for (; lowerBound < upperBound; lowerBound++) {
                longest = max(longest, lengths[lowerBound] + 1);
            }
            // update array
            // no need compare, definitely longer than prev idx
            lengths[idx] = longest;
            ans = max(ans, longest);
        }
        return ans; 
    }
};