class Solution {
private:
    void solve(vector<int> nums,vector<vector<int>> &ans,int index)
    {
        if(index == nums.size()-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            
            //backtrack
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        solve(nums,ans,0);
        return ans;
    }
};

/*
TIME COMPLEXITY -> n!*n
SPACE COMPLEXITY -> BIG O of N (for the depth of recursion)

/*


class Solution {
private:
    void solve(vector<int>&freq, vector<int>& output, vector<vector<int>> &ans, vector<int>& nums)
    {
       if(output.size()==nums.size())
       {
           ans.push_back(output);
           return;
       }
        
        for(int i=0;i<nums.size();i++)
        {
            if(freq[i] == 0)
            {
                output.push_back(nums[i]);
                freq[i] = 1;
                solve(freq,output,ans,nums);
                output.pop_back();
                freq[i] = 0;
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        vector<int> freq(nums.size(),0);
        
        solve(freq,output,ans,nums);
        
        return ans;
    }
};

N -> size of nums array
TIME COMPLEXITY -> n! * n
SPACE COMPLEXITY -> BIG O of N (for output vector) + BIG O of N (for freq vector) + BIG O of N (for recursion)
                  ~ BIG O of N

*/
