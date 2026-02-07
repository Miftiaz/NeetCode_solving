// link: https://neetcode.io/problems/valid-sudoku/question

/*
I solved using an unordered map where I stored three values (for row, column and box) for every number.
For example, if 1 is in row 1, column 1, box 1,
111, 121, 131 is stored in the map.

The middle number is used to denote:
1 -- column
2 -- row
3 -- box

The readablity of the code was poor. I could've easily determine the box number as I did later.
*/

/*

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <int, int> values;
        int num = 0;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(isdigit(board[i][j])){
                    int dig = board[i][j] - '0';
                    int blk = getblock(i, j);
                    int row = dig + 10 + (i+1)*100;
                    int col = dig + 20 + (j+1)*100;
                    int box = dig + 30 + blk*100;
                    if (values[row] || values[col] || values[box]) {
                        return 0;
                    }
                    else {
                        values[row]++; 
                        values[col]++; 
                        values[box]++;
                    }
                }
            }
        }
        return 1;
    }
private:
    int getblock(int a, int b){
        if(a>= 0 && a<3){
            if(b>= 0 && b<3) return 1;
            else if( b>2 && b<6) return 2;
            else return 3;
        }
        else if(a>= 3 && a<6){
            if(b>= 0 && b<3) return 4;
            else if( b>2 && b<6) return 5;
            else return 6;
        }
        else {
            if(b>= 0 && b<3) return 7;
            else if( b>2 && b<6) return 8;
            else return 9;
        }
    }
};

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                int digit = board[i][j] - '1';
                int box = (i / 3) * 3 + (j / 3);

                if (rows[i][digit] || cols[j][digit] || boxes[box][digit]) {
                    return false;
                }

                rows[i][digit] = true;
                cols[j][digit] = true;
                boxes[box][digit] = true;
            }
        }
        return true;
    }
};