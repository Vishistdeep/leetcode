class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
          int s = (minutesToTest / minutesToDie) + 1,i,ans=100,k=s;
      for(i=1;i<=1000;i++){
          if(s>=buckets){
              ans=i;
              break;
          }
          s*=k;

      }
      if(buckets==1) {
        ans=0;
      }

    return ans;
        
    }
};