class Solution {
public:
    bool isPalindrome(string s) {
      int j=0;
        for(int i=0; i<s.size(); i++){
           
            if (isalnum(s[i])){
               
                s[j]=toupper(s[i]);
                j++;
            }


        }
        int k=j-1;
        int a=0;
     
        for(int i=0; i<=k;i++){
            if(s[i]==s[k]){
                a++;
                k--;
            }
            else {
               
                break;
            }
           
        }

        if(a>(j-1)/2 || j==0 || j==1){
          return 1;
        }

        else {
            return 0;
        }

    }
}; 