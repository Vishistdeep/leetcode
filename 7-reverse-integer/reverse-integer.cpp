class Solution {
public:
    int reverse(int x) {
         long result = 0;
        while(x){
            int dig = x%10;
            result = result*10+dig;
            if(result <INT_MIN || result >INT_MAX){

            return 0;
            }
            x/=10;
        }
        return result;
        
    }
};