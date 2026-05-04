class Solution {
public:
    bool check(vector<int>& piles, int h, int x) {
        int total = 0;
        for (int pile : piles) {
            total += ceil((double) pile / x);
        }
        return total <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxCap = 0;
        for (int pile : piles) {
            maxCap = max(pile, maxCap);
        }

        int l = 1;
        int r = maxCap;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
