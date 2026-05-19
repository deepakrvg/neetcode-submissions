class Solution {
public:
    bool isSafe(int n, int row, int col, vector<string>& queens) {
        // checking columns
        for (int i = 0; i < row; i++) {
            if (queens[i][col] == 'Q') return false;
        }

        // checking diagonal
        int r = row, c = col;
        while (r > 0 && c > 0) {
            if (queens[r - 1][c - 1] == 'Q') return false;
            r--;
            c--;
        }

        r = row, c = col;
        while (r > 0 && c < n - 1) {
            if (queens[r - 1][c + 1] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }

    void rec(int n, int row, vector<string>& queens, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(queens);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(n, row, col, queens)) {
                queens[row][col] = 'Q';
                rec(n, row + 1, queens, ans);
                queens[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        vector<vector<string>> ans;
        rec(n, 0, queens, ans);
        return ans;
    }
};
