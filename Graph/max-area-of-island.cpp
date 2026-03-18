//link: https://neetcode.io/problems/max-area-of-island/question

//dfs

class Solution {
    int directions[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_area = 0;

        for (int r=0; r<row; r++){
            for (int c = 0; c< col; c++){
                if(grid[r][c]) {
                    max_area = max(max_area, visit_dfs(grid, r, c));
                }
            }
        }
        return max_area;
    }

    int visit_dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || !grid[r][c]){
            return 0;
        }
        grid[r][c] = 0;
        int res = 1;
        for (int i=0; i<4; i++){
            res += visit_dfs(grid, r+directions[i][0], c+directions[i][1]);
        }
        return res;
    }
};

//bfs

class Solution {
int max = 0;
int directions[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for (int r=0; r<row; r++){
            for (int c = 0; c< col; c++){
                if(grid[r][c]) {
                    visit_bfs(grid, r, c);
                }
            }
        }
        return max;
    }

    void visit_bfs(vector<vector<int>>& grid, int r, int c){
        queue<pair<int, int>>q;
        int area = 0;
        q.push({r, c});
        grid[r][c] = 0;
        area++;
        while(!q.empty()){
            auto [rr, cc] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = rr + directions[i][0];
                int nc = cc + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc]){
                    q.push({nr, nc});
                    area++;
                    grid[nr][nc] = 0;
                }
            }
        }
        if (area>max) max = area;
    }
};

