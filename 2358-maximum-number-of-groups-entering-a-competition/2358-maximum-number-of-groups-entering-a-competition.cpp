class Solution {
public:
    int maximumGroups(vector<int>& grades)
    {
        // int k = 0, total = 0, n = grades.size();
        // while (total + k + 1 <= n)
        //     total += ++k;
        // return k;
        sort(grades.begin(),grades.end());
        int prev_sum = 0;
        int prev_size=0;
        int cur_sum = 0;
        int cur_size=0;
        int ans=0;
        for(int x:grades)
        {
            cur_size++;
            cur_sum+=x;
            if(cur_size>prev_size && cur_sum > prev_sum)
            {
                prev_size = cur_size;
                prev_sum = cur_sum;
                ans++;
                cur_size=0;
                cur_sum=0;
            }
        }
        return ans;
    }
};
// Arrays.sort(grades);
//         int total = 0;
//         int p = 0;
//         int curr_total = 0;
//         int curr_p = 0;
//         int ans = 0;
//         for(int x : grades)
//         {
//             curr_p += 1;
//             curr_total += x;
            
//             if(curr_p > p && curr_total > total)
//             {
//                 p = curr_p;
//                 total = curr_total;
//                 ans += 1;
//                 curr_p =0;
//                 curr_total = 0;
//             }
            
//         }
//         return ans;
