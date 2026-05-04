class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        if (n > m) {
            return findMedianSortedArrays(b, a);
        }

        int total = n + m;
        int half = total / 2;
        int l = 0, r = n;
        while (l <= r) {
            int i = (l + r) / 2; // array A
            int j = half - i; // array B (-2 because index starts from 0 for both i and j)

            int al = (i > 0) ? a[i - 1] : INT_MIN;
            int ar = (i < n) ? a[i] : INT_MAX;
            int bl = (j > 0) ? b[j - 1] : INT_MIN;
            int br = (j < m) ? b[j] : INT_MAX;

            if (al <= br && bl <= ar) {
                // odd
                if (total % 2 == 1) {
                    return min(ar, br);
                }
                else {
                    return ((min(ar, br) + max(al, bl)) / (double) 2);
                }
            }
            else if (al > br) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 1.0;
    }
};
