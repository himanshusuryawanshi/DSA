class Solution {
public:
    bool binary(int index, vector<int>&nums, vector<int>& changeIndices){
        int n = nums.size();
        vector<int> last(n,-1);

        for(int i=0;i<index;i++){
            int ind = changeIndices[i]-1;
            last[ind] = i;
        }
        for(int i=0;i<n;i++){
            if(last[i]==-1) return false;
        }
        int time = 0;
        for(int i=0;i<index;i++){
            int idx = changeIndices[i]-1;
            if(last[idx]==i){
                time += nums[idx] + 1;
            }
            if(time > i+1) return false;
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int low = 1;
        int high = changeIndices.size();
        int ans = -1;
        while(low<=high){
            int mid = (high-low)/2 + low;

            if(binary(mid,nums,changeIndices)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};