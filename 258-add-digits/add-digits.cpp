class Solution {
public:
    int addDigits(int num) {
       int n=num;
       while(n>9){
        int temp=0;
        while(n>0){
            temp+=n%10;
            n/=10;

        }
        n=temp;

       }
       return n;
    }
};