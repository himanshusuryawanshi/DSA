class Solution {
private:
    int solve(int n, vector<int>& ans)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        
        if(ans[n] != 0) return ans[n];
        
        if(n%2==0)
        {
            ans[n] = solve(n/2,ans);
            return solve(n/2,ans);
        }
        else{
            ans[n] = 1 + solve(n/2,ans);
            return 1 + solve(n/2,ans);
        }
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            ans[i] = solve(i,ans);
        }
        return ans;
    }
};