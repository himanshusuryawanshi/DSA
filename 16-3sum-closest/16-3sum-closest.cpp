
class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(),a.end());   // -4 -1 1 2
        int ans = INT_MAX;
        int mn = INT_MAX;
        for(int i = 0;i<a.size();i++)
        {
            int x = a[i];
            int low = i+1;
            int high = a.size()-1;
            while(low<high)
            {
                int y = a[low] + a[high];
                if(x+y-target>0)
                {
                    high--;
                }
                else 
                    low++;
                if(abs(x+y-target)<mn)
                {
                    ans = x + y;
                    mn = abs(x+y-target);
                }
            }
        }
        return ans;
    }
};