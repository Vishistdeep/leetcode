class Solution {
public:
    string makeGood(string s) {
          while (true) {
            string pre = s;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] - 'A' == s[i - 1] - 'a' || s[i] - 'a' == s[i - 1] - 'A') {
                    s.erase(i - 1, 2);
                }
            }
            if (s == pre) break;
        }
        return s;
    }
};