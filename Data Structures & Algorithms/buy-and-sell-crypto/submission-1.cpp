class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mx = 0;
        for (int i = n - 1; i >=0; i--) {
            mx = max(mx, prices[i]);
            ans = max(ans, mx - prices[i]);
        }
        return ans;
    }
};
