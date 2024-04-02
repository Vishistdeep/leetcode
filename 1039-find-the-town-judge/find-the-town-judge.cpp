class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {vector<int> temp(n + 1, 0); 
        int size = trust.size();
        for (int i = 0; i < size; i++) {
            temp[trust[i][0]]--;
            temp[trust[i][1]]++;
        }
        for (int i = 1; i <= n; i++) { 
            if (temp[i] == n - 1) {
                return i;
            }
        }
        return -1;       
    }
};