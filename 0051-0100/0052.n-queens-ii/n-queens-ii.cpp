class Solution {
public:
vector<vector<string> > res;
void f(vector<string>& board, int row) {
    if (row == board.size()) {
        res.push_back(board);
        return;
    }
    int n = board.size();

    for (int col = 0; col != n; ++col) {
        if (!isValid(board, row, col)) continue;
        board[row][col] = 'Q';
        f(board, row + 1);
        board[row][col] = '.';
    }
}

bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();

    for (int i = 0; i != n; ++i) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    return true;

}
int totalNQueens(int n) {
    vector<string> board(n, string(n, '.'));

    f(board, 0);
    return res.size();
}
};