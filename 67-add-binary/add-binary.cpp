class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        
        int m = b.size();
        
        int carry = 0;
        
        string res = "";
        
        
        
        int i = n - 1, j = m - 1;
        
        while(i >= 0 || j >= 0 || carry)
        {
            
            
            int sum = 0;
            
            if(i >= 0)
            {
                sum += a[i] - '0';
            }
            
            if(j >= 0)
            {
                sum += b[j] - '0';
            }
            
            sum += carry;
            
           
            
            carry = sum / 2;
            
           
            
            int digit = (sum % 2) + 48;
           
            char char_digit = (char) digit;
            
            
            
            res += char_digit;
            
            
            
            i--;
            
            j--;
        }  
         reverse(res.begin(), res.end());
        
        return res;
    }
};