class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
       int temp=citations.size();
       for(int i=0;i<citations.size();i++){
        if(citations[i]<temp){
            temp--;
        }

       }
       return temp;
    }
};