class Solution {
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, -1, 0, 1};
    int n, m;

    void dfs(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &ocean){
        ocean[r][c] = true;

        for(int k=0; k<4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
            if(ocean[nr][nc]) continue;
            if(heights[nr][nc]<heights[r][c]) continue;

            dfs(nr, nc, heights, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) dfs(i, 0, heights, pacific);
        for(int i=0; i<n; i++) dfs(i, m-1, heights, atlantic);

        for(int i=0; i<m; i++) dfs(0, i, heights, pacific);
        for(int i=0; i<m; i++) dfs(n-1, i, heights, atlantic);

        vector<vector<int>> result;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};