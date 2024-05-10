class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int n= matrix.size();
        int m=matrix[0].size();
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        for(int x : s1)
        {
            for(int i=0;i<m; i++)
            {
                matrix[x][i]=0;
            }
        }
        for(int x : s2)
        {
            for(int i=0;i<n; i++)
            {
                matrix[i][x]=0;
            }
        }
        
    }
};