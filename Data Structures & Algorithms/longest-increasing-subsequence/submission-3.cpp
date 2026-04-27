class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for (int num : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), num);
            int pos = it - temp.begin();
            if (pos == temp.size()) {
                temp.push_back(num);
            }
            else {
                temp[pos] = num;
            }
        }
        return temp.size();
    }
};
