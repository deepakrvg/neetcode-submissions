class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row, col, box;

        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    int box_num = (i / 3) * 3 + (j / 3);
                    // check if already exists
                    if (row[i].find(board[i][j]) != row[i].end() || 
                        col[j].find(board[i][j]) != col[j].end() || 
                        box[box_num].find(board[i][j]) != box[box_num].end()
                    ) {
                        return false;
                    }

                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    box[box_num].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
