class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        bool ans = false;
        for (int num : nums) {
            if (st.find(num) != st.end()) {
                ans = true;
                break;
            }
            else {
                st.insert(num);
            }
        }

        return ans;
    }
};