class Solution {
public:
    bool rec(vector<vector<char>>& board, string& word, int i, int j, int k, string& s) {
        if (s == word) {
            return true;
        }
        if (s.size() > word.size() || k >= word.size()) {
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
        s.push_back(board[i][j]);
        char ch = board[i][j];
        board[i][j] = '#';
        if (rec(board, word, i + 1, j, k + 1, s)) {
            return true;
        }
        if (rec(board, word, i - 1, j, k + 1, s)) {
            return true;
        }
        if (rec(board, word, i, j + 1, k + 1, s)) {
            return true;
        }
        if (rec(board, word, i, j - 1, k + 1, s)) {
            return true;
        }
        s.pop_back();
        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                string s;
                ans = ans || rec(board, word, i, j, 0, s);
            }
        }
        return ans;
    }
};
