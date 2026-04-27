class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target) {
                row = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        int col = 0;
        l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] <= target) {
                col = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        if (matrix[row][col] == target) return true;
        return false;
    }
};
