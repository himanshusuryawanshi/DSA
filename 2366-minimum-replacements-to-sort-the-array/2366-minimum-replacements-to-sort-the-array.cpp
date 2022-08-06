class Solution {
public:
    long long minimumReplacement(vector<int>& num) {
        int size = num.size(), right = num[size-1];
        long long ans =0 , temp;
        
        if(size==1)
            return 0;
        
        for(int i=size-2;i>=0;i--)
        {
            if(right>=num[i])
                right = num[i];
            else
            {
                temp = ((num[i]-1)/right)+1;
                right = num[i]/temp;
                ans +=(temp-1);
            }
                
        }
        
        return ans;
    }
};