//link: https://neetcode.io/problems/islands-and-treasure/question


/*

Multisource BFS.

1. Add the treasure coordinates (row and column) to the queue.
2. Until the queue is empty:
    i. get the front grid. (it's already visited)
    ii. access the neighbours if they are valid and not visited (still INT_MAX)
    iii. assign the distance, (mark as visited). push them in the queue.

*/
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue <pair<int, int>> q;
        for (int i = 0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                int r = row+ directions[i][0];
                int c = col + directions[i][1];

                if (r < 0 || r >= grid.size() || c < 0 ||
                    c >= grid[0].size() || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r,c});
            }
        }
    }
};
