class Solution {
    int star;
    private:
    bool check(string& target, int start, string& stamp, vector<int>& ans)
    {
        for(int i=0;i<stamp.size();i++)
        {
            if(target[i+start] != '*' && target[i+start] != stamp[i]) return false;    
        }
        
        ans.push_back(start);
        
        for(int i=start; i-start < stamp.length(); i++)
        {
            if(target[i] != '*') star ++;
            target[i] = '*';
        }
        return true;
    }
    public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;    
        int s_size = stamp.size();
        int t_size = target.size();
        star = 0;
        vector<bool> vis(t_size, false);
        if(stamp == target) return {0};
        while(star < t_size)
        {
            bool replace = false;
            for(int i=0;i<=t_size-s_size && star<t_size;i++)
            {
                if(!vis[i])
                {
                    replace = check(target,i,stamp,ans);
                    vis[i] = replace;
                }
            }
            if(!replace) return {};
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
