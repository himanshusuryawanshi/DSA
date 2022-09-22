class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        string z="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')
                st.push(s[i]);
            else{
                while(st.empty()==false){
                    z+=st.top();
                    st.pop();
                }
                z+=' ';
            }
        }
        while(st.empty()==false){
            z+=st.top();
            st.pop();
        }
        return z;
    }
};