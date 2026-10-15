class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);
        vector<int> st;

        // Find left boundaries.  6 3 1 4 5 1 2 7
        for(int i = 0; i < n; i++) {
            while (!st.empty() &&
                   nums[st.back()] < nums[i] &&
                   (nums[st.back()] | nums[i]) == nums[i]) {
                st.pop_back();
            }
            // -1 0 1 2 
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        // Find right boundaries
        st.clear();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                   (nums[st.back()] | nums[i]) == nums[i]) {
                st.pop_back();
            }

            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        // Count subarrays
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * (i - left[i]) *
                   (right[i] - i);
        }

        return ans;
    }
};
