class Solution {
public:
    int t[101][101][201];
    int n, m;

    bool solve(int i, int j, int opencount, vector<vector<char>> &grid){

        opencount += grid[i][j]=='('? 1:-1;

        if(opencount < 0){
            return false;
        }

        if(t[i][j][opencount]!=-1){
            return t[i][j][opencount];
        }

        if(i==n-1 && j==m-1){
            return t[i][j][opencount] = (opencount==0);
        }

        if(i+1<n){
            if(solve(i+1, j, opencount, grid)){
                return true;
            }
        }

        if(j+1<m){
            if(solve(i, j+1, opencount, grid)){
                return true;
            }
        }

        return t[i][j][opencount] = false;
    }


    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if((m+n-1) % 2 == 1) 
            return false;
        
        if(grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;
        
        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, grid);
    }
};