class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        int l = 0;
        int r = 0;
        vector<int> ans;
        while (r < k) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);
            r++;
        }

        ans.push_back(nums[dq.front()]);
        l++;

        while (r < n) {
            if (dq.front() < l) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            ans.push_back(nums[dq.front()]);
            l++;
            r++;
        }
        return ans;
    }
};
