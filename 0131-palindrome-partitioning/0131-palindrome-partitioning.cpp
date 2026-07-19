class Solution {
public:
    void solve(string s, vector<vector<string>> &ans, vector<string> temp, int start, int end){
        if(start == end){
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int i=start;i<end;i++){
            t += s[i];
            int j=0; int k=t.length()-1;
            bool flag = true;
            while(j<k){
                if(t[j]!=t[k]){
                    flag = false; 
                    break;
                }
                j++;k--;
            }
            if(flag){
                temp.push_back(t);
                solve(s, ans, temp, i+1, end);
                temp.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp,0,s.length());
        return ans;
    }
};