class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int n = board.size();
        int m = board[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m) return;
        if (board[r][c] == 'X' || (board[r][c] == '2')) return;

        board[r][c] = '2';
        cout << r << " " << c << endl;
        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                cout << i << " " << 0 << endl;
                dfs(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                cout << i << " " << m - 1 << endl;
                dfs(board, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                cout << 0 << " " << j << endl;
                dfs(board, 0, j);
            }
            if (board[n - 1][j] == 'O') {
                cout << n - 1 << " " << j << endl;
                dfs(board, n - 1, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '2') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
