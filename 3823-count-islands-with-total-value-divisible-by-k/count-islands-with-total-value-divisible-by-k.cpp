class Solution {
public:
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, -1, 0, 1};
    int n, m;

    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int k,int i, int j){ 

        int totalsum = grid[i][j]%k;

        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j]=true;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int l=0; l<4; l++){
                int nr = r + dr[l];
                int nc = c + dc[l];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 0 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    totalsum = (totalsum + grid[nr][nc]) % k;
                    q.push({nr, nc});
                }
            }
        }
        return totalsum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        
        n = grid.size();
        m = grid[0].size();
        int totalcountisland = 0;

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    if(bfs(grid,vis,k,i,j)==0){
                        totalcountisland++;
                    }
                }
            }
        }
        return totalcountisland;
    }
};