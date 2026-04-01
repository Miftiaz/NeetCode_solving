//link:https://neetcode.io/problems/rotting-fruit/question

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair <int, int>> q;
        int count = 0;
        for (int i = 0; i< grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) count++;
            }
        }


        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int t = 0;
        bool flag = 0;

        while(count > 0 && !q.empty()){
            int n = q.size();
            for(int c=0; c<n; c++){
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int i=0; i<4; i++){
                    int r = row + directions[i][0];
                    int c = col + directions[i][1];

                    if (r < 0 || r >= grid.size() || c < 0 ||
                        c >= grid[0].size() || grid[r][c] != 1) {
                        continue;
                    }

                    grid[r][c] = 2;
                    count--;
                    q.push({r,c});
                }
            }
            t++;
        }
        
        return count == 0 ? t : -1;
    }
};
