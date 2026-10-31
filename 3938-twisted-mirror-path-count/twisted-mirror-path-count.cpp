class Solution {
public:
    int LEFT = 0; // Arrived at current cell from left cell (moving right)
    int UP = 1;   // Arrived at current cell from up cell (moving down)
    int MOD = 1e9+7;
    int m; // rows
    int n; // cols


    int solve(vector<vector<int>>& grid, int i, int j, int cameFrom, vector<vector<array<int, 2>>>& t) {
        // Base case: Out of bounds
        if(i >= m || j >= n) {
            return 0;
        }
        
        // Base case: Reached the destination, increment the answer
        if(i == m-1 && j == n-1) {
            return 1;
        }

        if (t[i][j][cameFrom] != -1) {
            return t[i][j][cameFrom];
        }
        
        // Case 1: The current cell is a mirror (forces a 90-degree turn)
        if(grid[i][j] == 1) {
            if(cameFrom == LEFT) {
                return t[i][j][cameFrom] = solve(grid, i+1, j, UP, t);
            } else {
                return t[i][j][cameFrom] = solve(grid, i, j+1, LEFT, t);
            }
        }
        
        // Case 2: The current cell is empty (branches both ways)
        int totalans = 0;
        totalans = (totalans + solve(grid, i, j+1, LEFT, t))%MOD; // Try moving right
        totalans = (totalans + solve(grid, i+1, j, UP, t))%MOD;   // Try moving down
        return t[i][j][cameFrom] = totalans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<array<int, 2>>>t(m+1,vector<array<int,2>>(n+1 ,{-1,-1}));
        
        // Start exploring from the top-left cell
        return solve(grid, 0, 0, LEFT, t);
        
    }
};