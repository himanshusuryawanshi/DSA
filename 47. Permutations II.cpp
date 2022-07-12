class Solution
{
    private:
        void solve(vector<int> vec, int index, vector<vector<int>> &ans)
        {
        if(index == vec.size() - 1)
        {
            ans.push_back(vec); //BASE CASE
            return;
        }

            for(int j = index;j<vec.size();j++)
            {
               
                if(vec[j]==vec[index]&&j!=index) continue;
                 swap(vec[index],vec[j]);
                 solve(vec,index+1,ans);  

                 //   backtrack

               //   swap(vec[index],vec[j]);            
            } 
        }
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            vector<vector<int>> ans;
            vector<int> output;
            int index = 0;
            sort(nums.begin(),nums.end());
            solve(nums,index,ans);
            return ans;
        }
};
