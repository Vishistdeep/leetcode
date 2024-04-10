class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       int n=deck.size();
        deque<int>ans;
        sort(deck.begin(),deck.end());
        ans.push_back(deck[n-1]);
        for(int i=n-2;i>=0;i--){
            ans.push_front(ans.back());
            ans.pop_back();
            ans.push_front(deck[i]);
        }
        vector<int>ans1;
        for(int i=0;i<ans.size();i++){
            ans1.push_back(ans[i]);
        }
        return ans1;  
    }
};