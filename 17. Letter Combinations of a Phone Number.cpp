class Solution {
private:
    void solve(int index, string& output, vector<string>& ans, string mapping[], string& digits)
    {
        if(index == digits.length())
        {
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++)
        {
            output.push_back(value[i]);
            solve(index+1, output, ans, mapping, digits);
            output.pop_back();
        }
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        vector<string> ans;
        if(digits.length() == 0)
        {
            return ans;
        }
        
        
        solve(0,output,ans,mapping,digits);
        return ans;
    }
};
