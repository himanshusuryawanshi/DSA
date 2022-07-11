class Solution {
private:
    void solve(int index,int target,vector<vector<int>>& ans,vector<int>&output,vector<int>& candidates)
    {
        if(target==0)
        {
            ans.push_back(output);
            return;
        } 
        
        if(target < 0 || index >= candidates.size())  return;
        if(candidates[index] <= target)
        {
            output.push_back(candidates[index]);
            solve(index, target - candidates[index], ans, output, candidates);
            output.pop_back();
        }
        solve(index+1,target,ans,output,candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(0,target,ans,output,candidates);
        
        return ans;
        
    }
};
