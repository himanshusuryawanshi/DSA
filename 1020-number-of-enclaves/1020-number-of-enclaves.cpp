class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>> & grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1;
        
        int delr[] = {-1, 0, +1, 0};
        int delc[] = {0, -1, 0, +1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
              && grid[nrow][ncol] == 1)
            {
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    
    public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1)
            {
                dfs(n-1,j,vis,grid);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0] ==1)
            {
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,vis,grid);
            }
        }
        
       // int totc = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
         //       if(grid[i][j] == 1) totc++;
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
       // cout<<notv<<endl;
        
        // int ans = totc - notv;
        
        return ans;
    }
};