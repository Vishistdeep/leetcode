class Solution {
public:
    int kthFactor(int n, int k) {
        if(k>n) return -1;
        if(k==1) return 1;

        for(int i=2;i<=n;i++){
            if(n%i==0) --k;
            if(k==1) return i;
        }
        return -1;  
    }
};