class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int l_max = 0;
        int r_max = n - 1;
        int ans = 0;
        while (l < r) {
            if (height[l] > height[l_max]) {
                l_max = l;
            }
            if (height[r] > height[r_max]) {
                r_max = r;
            }
            
            int diff = min(height[l_max], height[r_max]);
            if (height[l_max] < height[r_max]) {
                ans += (diff - height[l]) < 0 ? 0 : (diff - height[l]);
                l++;
            }
            else {
                ans += (diff - height[r]) < 0 ? 0 : (diff - height[r]);
                r--;
            }
        }
        return ans;
    }
};
