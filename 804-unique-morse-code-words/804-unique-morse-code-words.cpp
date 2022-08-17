class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto a:words)
        {
            string ans="";
            for(auto b:a)
            {
                int temp = b - 'a';
                ans+=v[temp];
            }
            s.insert(ans);
        }
        return s.size();
    }
};