class Solution {
public:
    // bool isSafe(int n, int row, int col, vector<string>& queens) {
    //     // checking columns
    //     for (int i = 0; i < row; i++) {
    //         if (queens[i][col] == 'Q') return false;
    //     }

    //     // checking diagonal
    //     int r = row, c = col;
    //     while (r > 0 && c > 0) {
    //         if (queens[r - 1][c - 1] == 'Q') return false;
    //         r--;
    //         c--;
    //     }

    //     r = row, c = col;
    //     while (r > 0 && c < n - 1) {
    //         if (queens[r - 1][c + 1] == 'Q') return false;
    //         r--;
    //         c++;
    //     }

    //     return true;
    // }

    void rec(int n, int row, vector<string>& queens, vector<vector<string>>& ans, vector<bool>& isSafeCol, vector<bool>& isSafePDia, vector<bool>& isSafeNDia) {
        if (row == n) {
            ans.push_back(queens);
            return;
        }

        for (int col = 0; col < n; col++) {
            // diagonal from bottom left to top right
            int positive_diagonal = row + col;
            // diagonal from top left to bottom right
            int negative_diagonal = row - col + (n - 1);

            if (isSafeCol[col] && isSafePDia[positive_diagonal] && isSafeNDia[negative_diagonal]) {
                queens[row][col] = 'Q';
                isSafeCol[col] = false;
                isSafePDia[positive_diagonal] = false;
                isSafeNDia[negative_diagonal] = false;
                rec(n, row + 1, queens, ans, isSafeCol, isSafePDia, isSafeNDia);
                isSafeCol[col] = true;
                isSafePDia[positive_diagonal] = true;
                isSafeNDia[negative_diagonal] = true;
                queens[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        vector<bool> isSafeCol(n, true);
        vector<bool> isSafePDia(2*n-1, true);
        vector<bool> isSafeNDia(2*n-1, true);
        vector<vector<string>> ans;
        rec(n, 0, queens, ans, isSafeCol, isSafePDia, isSafeNDia);
        return ans;
    }
};
