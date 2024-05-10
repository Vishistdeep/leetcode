class Solution {
public:
    string simplifyPath(string path) {
         int len = path.length();
        stack<string> st;
        string ans = "";
        for(int i=0; i<len; i++) {
            if(path[i] == '/') continue;
            string temp = "";
            while(i < len && path[i] != '/') temp += path[i++];
            if(temp == ".") continue;
            if(temp == "..") {
                if(!st.empty()) st.pop();
                continue;
            }
            st.push(temp);
        }
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.size()) return ans;
        else return "/";
    }
};