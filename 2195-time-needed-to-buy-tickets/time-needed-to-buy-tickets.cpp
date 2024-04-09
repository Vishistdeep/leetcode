class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
         int time = 0;

        for (int i = 0; tickets[k] > 0; i++) {
            if (tickets[i] > 0) {
                --tickets[i];
                time++;
            }
            
            if (i + 1 == tickets.size()) 
                i = -1;
        }
        
        return time;
    }
};