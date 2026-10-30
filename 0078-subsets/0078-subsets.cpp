class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // set<vector<int>>s;
        vector<vector<int>> ans;
        int n=nums.size();
        int size = pow(2,n);
        for(int i=0;i<size;i++){
            int temp = i;
            int idx = 0;
            vector<int>t = {};
            while(temp){
                if(temp&1)t.push_back(nums[idx]);
                idx++;
                temp>>=1;
            }
            ans.push_back(t);   
        }
        
        return ans;
    }
};