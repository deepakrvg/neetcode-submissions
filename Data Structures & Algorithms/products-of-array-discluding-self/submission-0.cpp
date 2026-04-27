class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 0; i < n; i++) {
            if (i != 0) prefix[i] = prefix[i - 1] * nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1) suffix[i] = suffix[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            cout << prefix[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << suffix[i] << " ";
        }
        cout << endl;

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int prev = (i == 0) ? 1 : prefix[i - 1];
            int next = (i == n - 1) ? 1 : suffix[i + 1];
            ans.push_back(prev * next);
        }

        return ans;
    }
};
