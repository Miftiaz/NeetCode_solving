//link: https://neetcode.io/problems/pacific-atlantic-water-flow/question

/*

Approach:
Think in reverse. Start from the cells adjacent to the oceans. If the next cells have higher height water can flow from that cell 
    (as the current cell height is lower than that of the next cell).

1. Keep two matrices to store if water can be flowed (one for atlantis, one for pacific)
2. call the dfs function to determine those two matrices.
3. for every cell of the main matrix, if both atlantis and pacific is true, then push the index to the result.

*/

class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector <vector<bool>> pac(rows, vector<bool> (cols, false));
        vector <vector<bool>> atl(rows, vector<bool> (cols, false));
        vector <vector<int>> res;
        
        for(int i=0; i<rows; i++){
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, cols-1);
        }

        for(int i=0; i<cols; i++){
            dfs(heights, pac, 0, i);
            dfs(heights, atl, rows-1, i);
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        ocean[r][c] = true;
        for(auto [dr, dc] : directions){
            int nr = r + dr;
            int nc = c + dc;
            if(nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                heights[nr][nc] >= heights[r][c] && !ocean[nr][nc]){
                    dfs(heights, ocean, nr, nc);
                }
        }
    }
};
