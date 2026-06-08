//https://neetcode.io/problems/surrounded-regions/question

/*

The idea was to
- mark the non-surrounding 'O's. only the reachable 'O's from a border O are non surrounding. Marked them as 'V'.
- replace the other 'O's with 'X'
- revert the 'V's to 'O's

*/

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O') {
                    if(i == 0 || i == row-1 || j == 0 || j == col-1) dfs(board, i, j);
                }
            }
        }

        for(int i = 0; i<row; i++){
            for(int j = 0; j< col; j++){
                if(board[i][j] == 'V') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c){
        board[r][c] = 'V';
        for(auto [dr, dc] : directions){
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size() &&
                board[nr][nc] == 'O'){
                    dfs(board, nr, nc);
                }            
        }
    }
};
