class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int m = matrix.size();     
    int n = matrix[0].size();
    int minR = 0;
    int maxR = m-1;
    int minC = 0 ;
    int maxC = n-1 ;
    vector<int> ans;
    while(minR<=maxR && minC<=maxC)
    { 
        // go right 
        for(int j = minC ; j<=maxC; j++)
           {
               ans.push_back(matrix[minR][j]);
           }
           minR++;
       if(minR>maxR || minC>maxC) break;

       // go down 
            for(int i = minR ; i<=maxR; i++)
           {
               ans.push_back(matrix[i][maxC]);
           }
         maxC--;
         if(minR>maxR || minC>maxC) break;

         // go left
         for(int j = maxC ; j>=minC; j--)
           {
               ans.push_back(matrix[maxR][j]);
           }
           maxR--;
            if(minR>maxR || minC>maxC) break;

            //go up
           for(int i = maxR ; i>=minR; i--)
           {
               ans.push_back(matrix[i][minC]);
           }
           minC++;
         if(minR>maxR || minC>maxC) break;

    }    
  return ans;
    }
};

