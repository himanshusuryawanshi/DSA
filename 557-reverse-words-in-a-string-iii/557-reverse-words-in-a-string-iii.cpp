class Solution {
public:
    string reverseWords(string s)
    {
        //T.C O(N)
        //S.C O(1)
        int space = 0;
        
        for(int i=0;i<=s.length();i++)
        {
            if(i==s.length() || s[i]==' ')
            {
                reverse(&s[space],&s[i]);
                space = i+1;
            }
        }
        return s;
        
    }
    
    
    /*
    string reverseWords(string s) {
     //TC O(N)
        //SC O(N) because of the auxiliary space cuz of using stack
        
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
    */
};