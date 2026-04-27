class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int j = mp[target - nums[i]];
            if (j && j != i) {
                if (j < i) {
                    ans.push_back(j);
                    ans.push_back(i);
                    break;
                }
                else {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};
