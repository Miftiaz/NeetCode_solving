//link:https://neetcode.io/problems/search-for-word/question

/*

Main idea: 
For every box in the grid, we need to check up, down, left, right (if those indices are valid)
Keep track of the path we are visiting now. (To avoid falling in loops)

*/
class Solution {
public:
    int rows, cols;
    set<pair <int, int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(backtrack(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i){
        if (i == word.length()){
            return true;
        } 

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[i] || path.count({r, c})){
            return false;
        }
        path.insert({r, c});
        bool res = backtrack(board, word, r+1, c, i+1) ||
                   backtrack(board, word, r-1, c, i+1) ||
                   backtrack(board, word, r, c+1, i+1) ||
                   backtrack(board, word, r, c-1, i+1);

        path.erase({r, c});
                                      
        return res;
    }
};

//Optimal one. Mark the grid = # while visiting. after visiting re-assign the original value.

class Solution {
public:
    int rows, cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r<rows; r++) {
            for(int c=0; c<cols; c++) {
                if(backtrack(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i){
        if (i == word.length()){
            return true;
        } 

        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            board[r][c] != word[i] || board[r][c] == '#'){
            return false;
        }
        
        board[r][c] = '#';
        bool res = backtrack(board, word, r+1, c, i+1) ||
                   backtrack(board, word, r-1, c, i+1) ||
                   backtrack(board, word, r, c+1, i+1) ||
                   backtrack(board, word, r, c-1, i+1);

        board[r][c] = word[i];
                                      
        return res;
    }
};

