class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int close = nums[0]+nums[1]+nums[2];
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int low = i+1, high = n-1;
            while(low<high){
                int closest = nums[i] + nums[low] + nums[high];
                if(abs(target-closest) < abs(target-close)){
                    close = closest;
                }
                if(closest>target) high--;
                else low++;
            }
        }
        return close;
    }
};