class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<=heights.size();i++){
            int val;
            if(i==heights.size())
            val=0;
            else
            val=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=val){
                int rm=i;
                int h=heights[st.top()];
                st.pop();
                int lm=st.top();
                int side=min(h,(rm-lm-1));
                maxi=max(maxi, side*side);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size());
        for(int i=0;i<matrix[0].size();i++){
            heights[i]=matrix[0][i]-'0';
        }
        int area=largestRectangleArea(heights);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]-'0'==1){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            area=max(area,largestRectangleArea(heights));
        }
        return area;
    }
};
