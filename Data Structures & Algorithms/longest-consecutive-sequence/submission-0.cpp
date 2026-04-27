class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int count = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            // found the start of sequence
            if (st.find(nums[i] - 1) == st.end()) {
                int num = nums[i];
                while (st.find(num) != st.end()) {
                    count++;
                    num++;
                }
                mx = max(mx, count);
                count = 0;
            }
        }
        return mx;
    }
};
