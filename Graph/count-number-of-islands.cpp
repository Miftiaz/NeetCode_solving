//link: https://neetcode.io/problems/count-number-of-islands/question

/*

Main idea:
When we find a "1", number of island ++
Then visit all the connected "1"s with the current island and make them 0 to denote visited.

*/

//DFS

class Solution {
    int directions[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
public:
    int row, col, res = 0;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == '1'){
                    res++;
                    visit(grid, r, c);
                }
            }
        }

        return res;
    }

    void visit(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= row || c >=col || 
            grid[r][c] == '0'){
                return;
        }
        
        grid[r][c] = '0';

        for (int i = 0; i<4; i++) {
            visit(grid, r + directions[i][0], c + directions[i][1]);
        }
    }
};

//BFS

class Solution {
    int directions[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
public:
    int row, col, res = 0;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == '1'){
                    res++;
                    visit_bfs(grid, r, c);
                }
            }
        }

        return res;
    }

    void visit_bfs(vector<vector<char>>& grid, int r, int c){
        queue <pair<int, int>> q;
        
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if( nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
