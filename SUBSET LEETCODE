class Solution {
private:
    void solve(int index, vector<vector<int>>&ans, vector<int> output, vector<int> nums,int n)
    {
        if(index == n)
        {  
            ans.push_back(output);
            return;
        }
            
        solve(index+1,ans,output,nums,n);
        
        output.push_back(nums[index]);
        solve(index+1,ans,output,nums,n);
        output.pop_back();
          
    }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      
        vector<vector<int>> ans;
        vector<int> output;
        int n = nums.size();
        
        solve(0,ans,output,nums,n);
        
        return ans;
        
    }
};
