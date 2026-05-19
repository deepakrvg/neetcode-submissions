class Solution {
public:
    bool rec(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size()) {
            return true;
        }
        if (k > word.size()) {
            return false;
        }

        int n = board.size();
        int m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        if (board[i][j] == '#' || word[k] != board[i][j]) {
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        if (rec(board, word, i + 1, j, k + 1)) {
            return true;
        }
        if (rec(board, word, i - 1, j, k + 1)) {
            return true;
        }
        if (rec(board, word, i, j + 1, k + 1)) {
            return true;
        }
        if (rec(board, word, i, j - 1, k + 1)) {
            return true;
        }
        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(rec(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
