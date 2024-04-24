class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1;
        int next=0;
        while(n>=3){
            next=a+b+c;
            a=b;
            b=c;
            c=next;
            n--;
        }
        if(n==0) return a;
        if(n==1) return b;
        if(n==2) return c;
        return 0; 
    }
};