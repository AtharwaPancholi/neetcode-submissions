class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxArea=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area=dfs(i,j,grid,vis);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vis[row][col]=1;
        int area=1;
        for(int i=0; i<4; i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
            grid[nrow][ncol]==1){
                area+=dfs(nrow,ncol,grid,vis);
            }
        }
        return area;
    }
};
