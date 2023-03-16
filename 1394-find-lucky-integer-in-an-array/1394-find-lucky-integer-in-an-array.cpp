class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int ans = -1;
        
        for(auto elem:mp){
            if(elem.first == elem.second){
                ans = max(elem.first,ans);
            }
        }
        return ans;
        
    }
};