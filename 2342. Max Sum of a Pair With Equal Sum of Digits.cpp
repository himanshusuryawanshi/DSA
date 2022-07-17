class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> digitsum_arr;
        vector<pair<int,int>> helper;
        int ans = -1;
        
        for(int i=0;i<nums.size();i++)
        {   
            int sum_digits = 0;
            int number = nums[i];
            while(number)
            {
                sum_digits += number%10;
                number/=10;
            }
            digitsum_arr.push_back(sum_digits);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            helper.push_back(make_pair(digitsum_arr[i],nums[i]));
        }
        sort(helper.begin(),helper.end());
        
        for(int i=1;i<nums.size();i++)
        {
            if(helper[i].first == helper[i-1].first)
            {
                int prob_ans = helper[i].second + helper[i-1].second;
                ans = max(ans,prob_ans);
            }
        }
        
        return ans;
    }
};
