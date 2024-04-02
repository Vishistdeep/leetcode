class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int hash[256] = {0};
        bool isMapped[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 0 && !isMapped[t[i]]) {
                hash[s[i]] = t[i];
                isMapped[t[i]] = true;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};