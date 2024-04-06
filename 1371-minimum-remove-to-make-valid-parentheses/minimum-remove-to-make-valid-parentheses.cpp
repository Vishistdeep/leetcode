class Solution {
public:
    string minRemoveToMakeValid(string s) {
         int cnt1 = 0;
        int cnt2 = 0;
        int flag = 0;
        string str;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                cnt1++;
                flag++;
            }
            else if(s[i] == ')' && flag > 0){
                cnt2++;
                flag--;
            }
        }

        int a = min(cnt1,cnt2);
        cnt1 = a;
        cnt2 = a;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                if(cnt1 > 0){
                    str.push_back('(');
                    cnt1--;
                }
            }
            else if(s[i] == ')'){
                
                    if(cnt2 > 0 && cnt2 > cnt1){
                        str.push_back(')');
                        cnt2--;
                    } 
                
            }else{
                str.push_back(s[i]);
            }
        }
        return str;
    }
};