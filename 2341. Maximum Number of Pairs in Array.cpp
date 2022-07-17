// SORTING

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=1,pair=0;
        while(i<nums.size())
        {
            if(nums[i]==nums[i-1])
            {
                pair++;
               // nums[i]=nums[i-1]=-1;
                i+=2;
            }
            else
                i++;
        }
        int leftover = nums.size() - 2*pair;
        
        ans.push_back(pair);
        ans.push_back(leftover);
        
        return ans;
    }
};

//HASHMAP
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int pair = 0, leftover = 0;
        for (auto n : nums) {
            freq[n]++;
        }
        for (auto c : freq) {
            pair+= c.second / 2;
            leftover += c.second % 2;
        }
        return {pair, leftover};
    }
};
